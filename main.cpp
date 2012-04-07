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
#include "BlockDevice.h"
#include "MBR.h"
#include "PartitionRecord.h"
#include <vector>
#include <string>
#include <iostream>
#include <linux/hdreg.h>

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

        cout << device->getDevNode() << endl;
        cout << "\t" << device->getType() << endl;

        BlockDevice* disk = dynamic_cast<BlockDevice*>(device);

        if ( disk ) {
            try {
                
                cout.flags( ios::dec );
                
                try {
                    cout << "\tSize: " << (disk->getSizeInBytes() / (1024*1024*1024)) << " GB" << endl;
                }
                catch( IOException& ex )
                {
                    cout << "\tCannot read size: " << ex.what() << endl;
                }
                
                cout << "\tDisk has GPT: " << endl;
                disk->hasGPT();
                
                cout.flags( ios::hex );
                MBR* mbr = disk->getMBR();

                if ( mbr && !mbr->isValid() ) {

                    cout << "\tMBR not valid (magic number doesn't match '0x55AA')" << endl;
                }
                else {
                    cout << "\tsignature: 0x";
                    unsigned long signature = mbr->getDiskSignature();
                    cout << signature << endl;
                    cout.flags( ios::dec );
                    cout << "\tSector size (logical/physical): " << disk->getLogicalBlockSize() << " / " <<  disk->getPhysicalBlockSize() << " bytes" << endl;
                    cout << "\th/s/c/start: " << (unsigned short)disk->getGeometry()->heads << "/" << (unsigned short)disk->getGeometry()->sectors << "/" << disk->getGeometry()->cylinders << "/" << disk->getGeometry()->start << endl;
                    cout.flags( ios::hex );

                    vector<PartitionRecord*> partitions = mbr->getPartitions();
                    vector<PartitionRecord*>::iterator it = partitions.begin();

                    while( it != partitions.end() ) {
                        PartitionRecord* partition = *it;

                        cout << "\t\tFound "
                                << ( partition->isBootable() ? "bootable " : "non-bootable " )
                                << ( partition->isExtended() ? "extended " : "" )
                                << "partition of type "
                                << PartitionRecord::getTypeDescription( partition->getType() )
                                << " (0x" << ( (int)partition->getType() ) << "). ";
                        cout.flags( ios::dec );
                        cout << "LBA Address: "  << partition->getLBAFirst() << endl;
                        cout << "\t\tSector count: " << partition->getSectorCount() << endl;
                        it++;
                    }
                }

                vector<Property*> props = device->getProperties();
                vector<Property*>::iterator pit = props.begin();

                while( pit != props.end() ) {
                    Property* p = *pit;
                    cout << "\t" << p->getName() << ":" << p->getValue() << endl;
                    pit++;
                }
            }
            catch( IOException& ex ) {
                cerr << "IOException: " << ex.what() << endl;
            }
        }

        it++;
    }
    return (EXIT_SUCCESS);
}
