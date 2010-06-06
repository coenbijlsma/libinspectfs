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

class BlockDevice : public Device {

protected:
    MBR* _mbr;
public:

    /**
     * Constructor.
     *
     * @param dev The udev device this Device is based upon.
     */
    BlockDevice( struct udev_device* dev );

    /**
     * Destructor.
     */
    virtual ~BlockDevice();

    /**
     * Returns the MBR from this Disk. This function always returns an MBR
     * object.
     * @see MBR::getErrors()
     */
    MBR* const getMBR();

    /**
     * Returns the block size of this Disk. This is mostly 512 bytes,
     * but for optical discs this is 2048 bytes.
     * Wikipedia sais that from 2011, manufacturers will implement 4096 bytes
     * as the new standard sector size.
     *
     * @link http://en.wikipedia.org/wiki/Disk_sector
     */
    unsigned short getSectorSize();
    
};

#endif	/* _DISK_H */

