#include "BlockDevice.h"
#include "IOException.h"
#include <iostream>

using std::cerr;
using std::endl;

BlockDevice::BlockDevice( struct udev_device* dev)
    : Device( dev ), _mbr( 0 ) {
}

BlockDevice::~BlockDevice() {

    if ( this->_mbr ) {
        delete this->_mbr;
        this->_mbr = (MBR*)0;
    }
}

MBR* const BlockDevice::getMBR() {
    if ( !this->_mbr ) {
        this->_mbr = new MBR( this );
    }

    return this->_mbr;
}

