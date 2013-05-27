#include "Scanner.h"
#include "BlockDevice.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Scanner::Scanner() : _udev( udev_new() ){
    
}

Scanner::~Scanner() {
    vector<Device*>::iterator it = this->_devices.begin();

    while( it != this->_devices.end() ) {
        Device* dev = *it;
        delete dev;
        it++;
    }
    udev_unref( this->_udev );
}

vector<Device*> Scanner::scan() {
    if ( !this->_devices.size() ) {
        struct udev_enumerate* enumerate = udev_enumerate_new( this->_udev );

        int result = udev_enumerate_scan_devices( enumerate );

        if ( result == 0 ) {

            /*
             * Fetch the first entry of the list containing the devices.
             */
            struct udev_list_entry* entry
                = udev_enumerate_get_list_entry( enumerate );

            while( entry ) {
                const char* syspath = udev_list_entry_get_name( entry );
                struct udev_device* device = udev_device_new_from_syspath( this->_udev, syspath );
                const char* devtype = udev_device_get_devtype( device );

                // Find out the type of device we've got here
                if ( devtype ) {
                    if ( strcmp( "disk", devtype ) == 0 ) {
                        /*
                         * See if we really have a physical disk here by
                         * querying the ID_TYPE property.
                         */
                        struct udev_list_entry* id_type = 
                            udev_list_entry_get_by_name(
                                udev_device_get_properties_list_entry( device )
                                , "ID_TYPE"
                            );
                        const char* id_type_value = udev_list_entry_get_value( id_type );

                        if ( id_type ) {
                            
                            if ( strcmp( "disk", id_type_value ) == 0 ) {
                                BlockDevice* disk = new BlockDevice( device );
                                this->_devices.push_back( disk );
                            }
                            else if ( strcmp( "cd", id_type_value ) == 0 ) {
                                // TODO: handle cd
                            }
                        }
                    }
                    else if ( strcmp( "partition", devtype ) == 0 )  {
                        // handle partition
                        const char* slaveof = udev_device_get_property_value( device, "UDISKS_PARTITION_SLAVE" );

                        if ( slaveof ) {
                            Device* parent = this->findBySyspath( string( slaveof ) );
                            if ( parent ) {
                                cout << "Found slave of " << parent->getDevNode() << endl;
                            }
                        }
                    }
                }
                
                entry = udev_list_entry_get_next( entry );
            }
        }
        else {
            cout << "Could not scan devices." << endl;
        }

        udev_enumerate_unref( enumerate );
    }

    return this->_devices;
}

Device* Scanner::findBySyspath( string syspath ) {

    vector<Device*>::iterator it = this->_devices.begin();

    while( it != this->_devices.end() ) {
        Device* dev = *it;
        if ( dev->getSysPath().compare( syspath ) == 0 ) {
            return dev;
        }
        it++;
    }

    return (Device*)0;
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
