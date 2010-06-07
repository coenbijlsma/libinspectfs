/* 
 * File:   MBR.h
 * Author: coen
 *
 * Created on May 29, 2010, 6:21 PM
 */

#ifndef _MBR_H
#define	_MBR_H

#include "BlockDevice.h"
#include "IOException.h"
#include "PartitionRecord.h"
#include <iostream>
#include <vector>

using std::vector;
using std::streamsize;

class BlockDevice;
class PartitionRecord;

class MBR {

protected:

    static const streamsize BLCODE_SIZE = 440;

    static const streamsize DISK_SIGNATURE_SIZE = 4;

    static const streamsize EMPTY_SIZE = 2;

    static const streamsize MBR_SIGN_SIZE = 2;

    static const unsigned short PARTITION_RECORD_SIZE = 16;

    static const unsigned short MAGIC_NUMBER = 0x55AA;
    
    /**
     * @var The Disk this MBR belongs to.
     */
    BlockDevice* _block_device;

    /**
     * @var The boot loader code, offset 0 - 439
     */
    char _code[ 440 ];

    /**
     * @var The disk signature (optional), offset 440 - 443
     */
    char _disk_signature[ 4 ];

    /**
     * @var Mostly null values, offset 444 - 445
     */
    char _empty[ 2 ];

    /**
     * @var The records of the primary partitions, offset 446 - 509
     */
    vector<PartitionRecord*> _partitions;

    /**
     * @var The MBR signature (0xAA55), offzet 510 - 511
     */
    char _mbr_signature[ 2 ];

    /**
     * Contains errors that were raised when reading the MBR from disk (if any).
     */
    vector<string> _errors;

public:

    /**
     * Constructor.
     *
     * @param disk The physical device this MBR belongs to.
     */
    MBR( BlockDevice* disk );

    /**
     * Destructor.
     */
    virtual ~MBR();

    /**
     * Returns the boot loader code.
     */
    char* getCode();

    /**
     * Returns the disk signature.
     */
    unsigned long getDiskSignature();

    /**
     * Returns the signature of this MBR (2 bytes).
     */
    char* getMBRSignature();

    /**
     * Returns whether ths signature of this MBR is valid (I.E. equals 0xAA55)
     */
    bool isValid();

    /**
     * Returns the 4 partition records from this MBR.
     */
    vector<PartitionRecord*> getPartitions();

    /**
     * If there were any errors while constructing this MBR, the errors are
     * stored for later inspection.
     * This function returns them, if there are any. If there are no errors,
     * this function returns an empry vector.
     */
    vector<string> getErrors();

    /**
     * Returns the BlockDevice this MBR belongs to.
     */
    BlockDevice* getBlockDevice();
};

#endif	/* _MBR_H */

