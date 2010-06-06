#include "MBR.h"
#include "PrimaryPartition.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using std::filebuf;
using std::istream;
using std::ios;
using std::stringstream;

const streamsize MBR::BLCODE_SIZE;
const streamsize MBR::DISK_SIGNATURE_SIZE;
const streamsize MBR::EMPTY_SIZE;
const streamsize MBR::MBR_SIGN_SIZE;

const unsigned short MBR::PARTITION_RECORD_SIZE;
const unsigned short MBR::MAGIC_NUMBER;

MBR::MBR(BlockDevice* disk) : _disk( disk ) {
    filebuf fb;
    fb.open( this->_disk->getDevNode().c_str(), ios::in | ios::binary );
    istream is( &fb );

    is.read( this->_code, BLCODE_SIZE );

    if ( is.gcount()  != BLCODE_SIZE ) {
        this->_errors.push_back( string( "Could not read boot loader code from device node " )
            + this->_disk->getDevNode()
        );
    }

    is.read( this->_disk_signature, DISK_SIGNATURE_SIZE );
    if ( is.gcount() != DISK_SIGNATURE_SIZE ) {
        this->_errors.push_back( string( "Could not read disk signature from device node " )
            + this->_disk->getDevNode()
        );
    }

    is.read( this->_empty, EMPTY_SIZE );
    if ( is.gcount() != EMPTY_SIZE ) {
        this->_errors.push_back( string( "Could not read MBR from device node " )
            + this->_disk->getDevNode()
        );
    }

    // Read the partition records
    for( int i = 0; i < 4; i++ ) {
        char partition[ PARTITION_RECORD_SIZE ] ;
        is.read( partition, PARTITION_RECORD_SIZE );

        if ( is.gcount() != PARTITION_RECORD_SIZE ) {
            std::stringstream conv;
            conv << i;
            this->_errors.push_back( string( "Could not read partition record "
                    + conv.str() + " from device node "
                    + this->_disk->getDevNode()  )
            );
        }
        else {
            this->_partitions.push_back( new PrimaryPartition( partition ) );
        }
    }

    is.read( this->_mbr_signature, MBR_SIGN_SIZE );
    if ( is.gcount() != MBR_SIGN_SIZE ) {
        this->_errors.push_back( string( "Could not read MBR signature from device node " )
            + this->_disk->getDevNode()
        );
    }
    
    fb.close();
}

MBR::~MBR() {

    vector<Partition*>::iterator it = this->_partitions.begin();

    while( it != this->_partitions.end() ) {
        Partition* partition = *it;
        delete partition;
        partition = (Partition*)0;
        it++;
    }

    this->_partitions.clear();
}

char* MBR::getCode() {
    return this->_code;
}

unsigned long MBR::getDiskSignature() {
    unsigned long signature = 0;

    // todo move this to constructor.
    signature |= (unsigned char)this->_disk_signature[ 3 ];

    signature <<= 8;
    signature |= (unsigned char)this->_disk_signature[ 2 ];

    signature <<= 8;
    signature |= (unsigned char)this->_disk_signature[ 1 ];

    signature <<= 8;
    signature |= (unsigned char)this->_disk_signature[ 0 ];

    return signature;
}

char* MBR::getMBRSignature() {
    return this->_mbr_signature;
}

bool MBR::isValid() {
    return ( ( this->_mbr_signature[ 0 ] << 8 ) | ( this->_mbr_signature[ 1 ] & 0xAA ) ) == MAGIC_NUMBER;
}

vector<Partition*> MBR::getPartitions() {
    return this->_partitions;
}

vector<string> MBR::getErrors() {
    return this->_errors;
}