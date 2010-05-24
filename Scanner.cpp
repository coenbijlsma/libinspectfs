#include "Scanner.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Scanner::Scanner() {
    this->udev = udev_new();
}

Scanner::~Scanner() {
    vector<Device*>::iterator it = this->devices.begin();

    while( it != this->devices.end() ) {
        Device* dev = *it;
        delete dev;
        it++;
    }
    udev_unref( this->udev );
}

vector<Device*> Scanner::scan() {
    if ( !this->devices.size() ) {
        struct udev_enumerate* enumerate = udev_enumerate_new( this->udev );

        int result = udev_enumerate_scan_devices( enumerate );

        if ( result == 0 ) {
            struct udev_list_entry* entry
                = udev_enumerate_get_list_entry( enumerate );

            while( entry ) {
                const char* syspath = udev_list_entry_get_name( entry );
                struct udev_device* device = udev_device_new_from_syspath( this->udev, syspath );
                const char* devtype = udev_device_get_devtype( device );

                if ( devtype && ( strcmp( "disk", devtype ) == 0 || strcmp( "partition", devtype ) == 0 ) ) {
                    Device* dev = new Device( device );
                    this->devices.push_back( dev );
                }
                
                entry = udev_list_entry_get_next( entry );
            }
        }
        else {
            cout << "Could not scan devices." << endl;
        }

        udev_enumerate_unref( enumerate );
    }

    return this->devices;
}

// .so stuff
extern "C" Scanner* create_scanner() {
    return new Scanner();
}

extern "C" bool destroy_scanner(Scanner* scanner) {
    delete scanner;
    scanner = (Scanner*)0;
    return true;
}