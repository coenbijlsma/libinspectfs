#include "Disk.h"
#include "IOException.h"
#include <iostream>

using std::cerr;
using std::endl;

Disk::Disk( struct udev_device* dev)
    : Device( dev ) {
}

Disk::~Disk() {

    if ( this->_mbr ) {
        delete this->_mbr;
        this->_mbr = (MBR*)0;
    }
}

MBR* const Disk::getMBR() {
    if ( !this->_mbr ) {
        this->_mbr = new MBR( this );
    }

    return this->_mbr;
}