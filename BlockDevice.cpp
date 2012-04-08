#include "BlockDevice.h"
#include <linux/fs.h>
#include <linux/hdreg.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include <string>
#include <iostream>
#include <vector>

#ifndef _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE 1
#endif

using std::cout;
using std::cerr;
using std::endl;

BlockDevice::BlockDevice( struct udev_device* dev)
    : Device( dev ), _logical_block_size( 0 ), _physical_block_size( 0 ), _size_in_bytes( 0 ), _mbr( 0 ), _fd( -1 ) {
}

BlockDevice::~BlockDevice() {
    delete this->_geometry;

    if ( this->_mbr ) {
        delete this->_mbr;
        this->_mbr = (MBR*)0;
    }
    
    if ( this->_fd != -1 ) {
        this->closeFD();
    }
}

MBR* const BlockDevice::getMBR() {
    if ( !this->_mbr ) {
        this->_mbr = new MBR( this );
    }

    return this->_mbr;
}

bool BlockDevice::hasGPT() {
    MBR* mbr = this->getMBR();
    
    if(mbr->isValid())
    {
        cout << "\tValid MBR, querying partitions..." << endl;
        vector<PartitionRecord*> partitions = mbr->getPartitions();
        
        PartitionRecord* record = *(partitions.begin());

        // The type of the partition should be 0xEE: EFI protective MBR
        if(record->getType() == 0xee)
        {
            unsigned long partitionSize = record->getSectorCount() * this->getPhysicalBlockSize();
            
            // Compare with (partitionSize + 512) because the MBR
            // is not part of the partition size.
            if( (partitionSize + 512) == this->getSizeInBytes())
            {
                cout << "\tDisk contains GPT" << endl;
                return true;
            }
            else
            {
                cout << "\tFirst partition is of type 0xEE but it doesn't match the disk size:" << endl;
                cout << "\tPartition size is " << partitionSize << " and disk size is " << this->getSizeInBytes() << endl;
            }
        }
        else
        {
            cout << "\tFound only one partition but it isn't of type 0xEE" << endl;
        }
        
    }
    
    return false;
}

int BlockDevice::getLogicalBlockSize() throw( IOException ) {
    if ( this->_logical_block_size == 0 ) {
        int fd = open( this->getDevNode().c_str(), O_RDONLY );

        if ( !fd ) {
            throw IOException( string( "Cannot open device " ) + this->getDevNode() );
        }
        else {
            int result = ioctl( fd, BLKBSZGET, &this->_logical_block_size );
            close( fd );

            if( result == -1 ) {
                if ( errno ) {
                    char* errorstring = strerror( errno );
                    string what( errorstring );
                    throw IOException( what );
                }
                else {
                    throw IOException( string( "Cannot read block size off device ") + this->getDevNode() );
                }
            }
        }
        

    }

    return this->_logical_block_size;
}

int BlockDevice::getPhysicalBlockSize() throw( IOException ) {
    if ( this->_physical_block_size == 0 ) {
        int fd = open( this->getDevNode().c_str(), O_RDONLY );

        if ( !fd ) {
            throw IOException( string( "Cannot open device " ) + this->getDevNode() );
        }
        else {
            int result = ioctl( fd, BLKSSZGET, &this->_physical_block_size );
            close( fd );

            if( result == -1 ) {
                if ( errno ) {
                    char* errorstring = strerror( errno );
                    string what( errorstring );
                    throw IOException( what );
                }
                else {
                    throw IOException( string( "Cannot read block size off device ") + this->getDevNode() );
                }
            }
        }


    }

    return this->_physical_block_size;
}

struct hd_geometry* BlockDevice::getGeometry() {
    if ( this->_geometry == 0 ) {
        this->_geometry = new struct hd_geometry;
        int fd = open( this->getDevNode().c_str(), O_RDONLY );

        if ( !fd ) {
            throw new IOException( string( "Cannot open device " ) + this->getDevNode() );
        }
        else {
            int result = ioctl( fd, HDIO_GETGEO, this->_geometry );
            close( fd );

            if( result == -1 ) {
                if ( errno ) {
                    char* errorstring = strerror( errno );
                    string what( errorstring );
                    throw IOException( what );
                }
                else {
                    throw IOException( string( "Cannot read identity off device ") + this->getDevNode() );
                }
            }
        }
    }

    return this->_geometry;
}

unsigned long BlockDevice::getSizeInBytes()
{
    if(this->_size_in_bytes == 0)
    {
        int fd = open( this->getDevNode().c_str(), O_RDONLY );
        
        if( !fd )
        {
            throw IOException( string( "Cannot open device ") + this->getDevNode() );
        }
        else {
            unsigned long blocks = 0;
            int result = ioctl( fd, BLKGETSIZE, &blocks );
            close( fd );
            
            if( result == -1 ) {
                if( errno )
                {
                    char* errorstring = strerror( errno );
                    string what( errorstring );
                    throw IOException( what );
                }
                else {
                    throw IOException( string( "Cannot read size off device ") + this->getDevNode() );
                }
            }
            
            this->_size_in_bytes = blocks * this->getPhysicalBlockSize();
        }
    }
    
    return this->_size_in_bytes;
}

unsigned char* BlockDevice::getIdentity() {
    if ( this->_identity == 0 ) {
        
        int fd = open( this->getDevNode().c_str(), O_RDONLY );

        if ( !fd ) {
            throw IOException( string( "Cannot open device " ) + this->getDevNode() );
        }
        else {
            int result = ioctl( fd, HDIO_GET_IDENTITY, this->_identity );
            close( fd );

            if( result == -1 ) {
                if ( errno ) {
                    char* errorstring = strerror( errno );
                    string what( errorstring );
                    throw IOException( what );
                }
                else {
                    throw IOException( string( "Cannot read identity off device ") + this->getDevNode() );
                }
            }
        }
    }

    return this->_identity;
}

unsigned char* BlockDevice::readBlock( PartitionRecord* record, unsigned long lba, bool keepopen )
        throw( IOException ){
    if ( this->_fd == -1 ) {
        this->_fd = open( this->getDevNode().c_str(), O_RDONLY );

        if ( this->_fd == -1 ) {
            throw IOException( strerror( errno ) );
        }
    }
    
    if ( record == 0 || record->getType() == 0x0 ) {
        return (unsigned char*)0;
    }

    unsigned long real_lba = lba + record->getLBAFirst();
    unsigned long max_lba = record->getLBAFirst() + ( record->getSectorCount() / this->getPhysicalBlockSize() );
    
    // real_lba must be <= max_lba, or we read outside of PartitionRecord.
    if ( real_lba > max_lba ) {
        throw IOException( "Attempting to read outside of PartitionRecord boundaries." );
    }

    // real offset in bytes (from BlockDevice)
    unsigned long offset = real_lba * this->getPhysicalBlockSize();

    // Set the pointer for the filedescriptor of this BlockDevice to offset.
    off64_t seek_result = lseek64( this->_fd, (off64_t)offset, SEEK_SET );

    if ( seek_result == -1 ) {
        switch( errno ) {
            case EBADF:
                throw IOException( "Cannot seek in closed file descriptor." );
            case EINVAL:
                throw IOException( "Invalid whence provided." );
            case EOVERFLOW:
                throw IOException( "Offset too large" );
            case ESPIPE:
                throw IOException( "fd is not a block device." );
            default:
                throw IOException( "Unknown I/O error." );
        }
        
    }

    unsigned char* buf = (unsigned char*)malloc( this->getPhysicalBlockSize() );
    int err = errno;

    // Maybe we ran out of memory
    if ( buf == NULL && err ) {
        throw IOException( strerror( err ) );
    }

    memset( buf, 0, this->getPhysicalBlockSize() );
    ssize_t bytes_read = read( this->_fd, buf, this->getPhysicalBlockSize() );

    if ( bytes_read == -1 ) {
        throw IOException( strerror( errno ) );
    }


    if ( !keepopen ) {
        close( this->_fd );
        this->_fd = -1;
    }
    
    return buf;
}

void BlockDevice::closeFD() {
    if ( this->_fd != -1 ) {
        close( this->_fd );
        this->_fd = -1;
    }
}