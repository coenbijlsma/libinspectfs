/* 
 * File:   Disk.h
 * Author: coen
 *
 * Created on May 30, 2010, 9:44 PM
 */

#ifndef _BLOCKDEVICE_H
#define	_BLOCKDEVICE_H

#include <linux/fs.h>
#include "Device.h"
#include "MBR.h"
#include "PartitionRecord.h"
#include "IOException.h"

class MBR;
class PartitionRecord;

class BlockDevice : public Device {

protected:
    
    int _logical_block_size;

    int _physical_block_size;
    
    unsigned long _size_in_bytes;

    MBR* _mbr;

    unsigned char _identity[ 512 ];

    int _fd;

    struct hd_geometry* _geometry;
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
     * Returns whether this BlockDevice contains a GPT. For this, the MBR is 
     * inspected, and if it contains only one partition of type 0xEE 
     * (EFI Protective MBR) and it's size matches the device's size
     * a GPT should exist.
     * 
     * @return Whether this BlockDevice contains a GPT.
     */
    bool hasGPT();

    /**
     * Returns the logical sector size of this BlockDevice.
     * This is mostly 512 bytes, but for optical discs this is 2048 bytes.
     * Wikipedia says that from 2011, manufacturers will implement 4096 bytes
     * as the new standard sector size. The value is retrieved by calling
     * ioctl( fd, BLKBSZGET, &var ).
     *
     * @link http://en.wikipedia.org/wiki/Disk_sector
     */
    int getLogicalBlockSize() throw( IOException );

    /**
     * Returns the physical sector size of this BlockDevice.
     * This is mostly 512 bytes, but for optical discs this is 2048 bytes.
     * Wikipedia says that from 2011, manufacturers will implement 4096 bytes
     * as the new standard sector size. The value is retrieved by calling
     * ioctl( fd, BLKSSZGET, &var ).
     *
     * @link http://en.wikipedia.org/wiki/Disk_sector
     */
    int getPhysicalBlockSize() throw( IOException );

    /**
     * Returns the geometry of this BlockDevice.
     *  struct hd_geometry {
     *        unsigned char heads;
     *        unsigned char sectors;
     *        unsigned short cylinders;
     *        unsigned long start;
     *  };
     */
    struct hd_geometry* getGeometry();
    
    /**
     * @return The size of this BlockDevice in bytes
     * 
     * @throws IOException If the ioctl() call fails
     */
    unsigned long getSizeInBytes();

    /**
     * Calls ioctl() with the HDIO_GET_IDENTITY parameter, and returns the
     * result (512 bytes). I didn't find a decent description or manual about
     * ioctl() so use it if you want to on your own risk.
     */
    unsigned char* getIdentity();

    /**
     * Reads a block from the device, relative to the given PartitionRecord.
     * The lba field is relative to the given PartitionRecord.
     *
     * @param record The PartitionRecord to use as offset.
     * @param lba The lba to be read, relative to the PartitionRecord.
     * @param keepopen Whether to close the file descriptor after reading
     * the block (speedup for mass reading).
     * @return The requested block. This block must be free()'d when needed.
     * If record points to a PartitionRecord of type 0x0 (Empty) or
     * if record = 0, this function returns (unsigned char*)0.
     * 
     * @throws IOException If the given lba exceeds the perimeters of the given
     * PartitionRecord.
     */
    unsigned char* readBlock( PartitionRecord* record, unsigned long lba, bool keepopen ) throw( IOException );

    /**
     * Closes the file descriptor that belongs to this BlockDevice, if it is
     * still open.
     */
    void closeFD();
    
};

#endif	/* _BLOCKDEVICE_H */

