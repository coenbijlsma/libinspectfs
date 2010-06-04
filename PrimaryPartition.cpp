#include "PrimaryPartition.h"

const unsigned short PrimaryPartition::STATUS_BOOTABLE;
const unsigned short PrimaryPartition::STATUS_NON_BOOTABLE;

PrimaryPartition::PrimaryPartition( char* bytes ) throw( Exception ){
    if ( bytes == 0 ) {
        throw Exception( "Empty data for partition." );
    }

    this->_status = bytes[ 0x00 ];

    this->_chsFirst[ 0 ] = bytes[ 0x01 ];
    this->_chsFirst[ 1 ] = bytes[ 0x02 ];
    this->_chsFirst[ 2 ] = bytes[ 0x03 ];

    this->_type = bytes[ 0x04 ];

    // todo the rest
}

PrimaryPartition::~PrimaryPartition() {

}

bool PrimaryPartition::isBootable() {
    return STATUS_BOOTABLE == this->_status;
}

unsigned char PrimaryPartition::getType() {
    return this->_type;
}