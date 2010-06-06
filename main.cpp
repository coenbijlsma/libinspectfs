/* 
 * File:   main.cpp
 * Author: coen
 *
 * Created on May 24, 2010, 5:20 PM
 */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "Scanner.h"
#include "Device.h"
#include "Property.h"
#include "User.h"
#include "IOException.h"
#include "Disk.h"
#include "MBR.h"
#include "Partition.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::ios;
using std::cout;
using std::cerr;
using std::endl;

/*
 * For testing purposes only.
 * Change (project)settings to application instead of library.
 */
int main(int argc, char** argv) {
    User* me = User::getCurrent();
    
    if ( !me->isRoot() ) {
        cout << "This program must be run as root." << endl;
        return (EXIT_FAILURE);
    }

    Scanner scanner;
    vector<Device*> devices = scanner.scan();
    vector<Device*>::iterator it = devices.begin();

    while( it != devices.end() ) {
        Device* device = *it;

        //if ( device->isLogicalDisk() || device->isPhysicalDisk() ) {
            cout << device->getDevNode() << endl;
            cout << "\t" << device->getType() << endl;

            BlockDevice* disk = dynamic_cast<BlockDevice*>(device);
            
            if ( disk ) {
                try {
                    cout.flags( ios::hex );
                    MBR* mbr = disk->getMBR();

                    if ( mbr && !mbr->isValid() ) {
                        
                        cout << "\tMBR not valid (magic number doesn't match '0x55AA'" << endl;
                    }
                    else {
                        cout << "\tsignature: ";
                        unsigned long signature = mbr->getDiskSignature();
                        cout << signature << endl;
                        vector<Partition*> partitions = mbr->getPartitions();
                        vector<Partition*>::iterator it = partitions.begin();

                        while( it != partitions.end() ) {
                            Partition* partition = *it;

                            
                            cout << "\t\tFound "
                                    << ( partition->isBootable() ? "bootable " : "non-bootable " )
                                    << "partition of type "
                                    << Partition::getTypeDescription( partition->getType() )
                                    << " (0x" << ( (int)partition->getType() ) << ")"
                                    << endl;
                            it++;
                        }
                    }
                }
                catch( IOException& ex ) {
                    cerr << ex.what() << endl;
                }
            }
            /*
            vector<Property*> props = device->getProperties();
            vector<Property*>::iterator pit = props.begin();

            while( pit != props.end() ) {
                Property* p = *pit;
                cout << "\t" << p->getName() << ":" << p->getValue() << endl;
                pit++;
            }
            */
        //}
        it++;
    }
    return (EXIT_SUCCESS);
}
