/* 
 * File:   Disk.h
 * Author: coen
 *
 * Created on May 30, 2010, 9:44 PM
 */

#ifndef _DISK_H
#define	_DISK_H

#include "Device.h"
#include "MBR.h"

class MBR;

class Disk : public Device {

protected:
    MBR* _mbr;

public:

    /**
     * Constructor.
     *
     * @param dev The udev device this Device is based upon.
     */
    Disk( struct udev_device* dev );

    /**
     * Destructor.
     */
    virtual ~Disk();

    /**
     * Returns the MBR from this Disk. This function always returns an MBR
     * object.
     * @see MBR::getErrors()
     */
    MBR* const getMBR();
};

#endif	/* _DISK_H */

