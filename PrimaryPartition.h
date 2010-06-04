/* 
 * File:   PartitionRecord.h
 * Author: coen
 *
 * Created on May 29, 2010, 6:33 PM
 */

#ifndef _PRIMARY_PARTITION_H
#define	_PRIMARY_PARTITION_H

#include "Partition.h"
#include "Exception.h"

class PrimaryPartition : public Partition {

protected:

    /**
     * The status of this Partition (either 0x80 or 0x00)
     */
    unsigned char _status;

    /**
     * CHS address of the first absolute sector in the partition.
     * - The first byte contains the head (range = 0-254 inclusive)
     * - The sector is in bits 5-0 of the second byte (range = 1-63 inclusive).
     *   bits 7-6 contain bits 9-8 of the cylinder.
     * - The cylinder is thus in bits 7-6 of the second byte and in bits 7-0
     * of the third byte.
     * The value can be reassembled as follows:
     * cylinder = ( byte[ 2 ] & 0xc0 ) * 4 + byte( 3 )
     */
    unsigned char _chsFirst[ 3 ];

    /**
     * The type of the partition.
     *
     * @see Partition::getTypeDescription(unsigned char)
     */
    unsigned char _type;

    /**
     * CHS address of the last absolute sector in the partition.
     * - The first byte contains the head (range = 0-254 inclusive)
     * - The sector is in bits 5-0 of the second byte (range = 1-63 inclusive).
     *   bits 7-6 contain bits 9-8 of the cylinder.
     * - The cylinder is thus in bits 7-6 of the second byte and in bits 7-0
     * of the third byte.
     * The value can be reassembled as follows:
     * cylinder = ( byte[ 2 ] & 0xc0 ) * 4 + byte( 3 )
     */
    unsigned char _chsLast[ 3 ];

    /**
     * LBA of first absolute sector in the partition.
     */
    unsigned char _lbaFirst[ 4 ];

    /**
     * The number of sectors in the partition, in little endian format.
     */
    unsigned char _sectorCount[ 4 ];
    
public:

    static const unsigned short STATUS_BOOTABLE = 0x80;
    static const unsigned short STATUS_NON_BOOTABLE = 0x00;

    /**
     * Constructor.
     *
     * @param bytes The bytes read from the disk that form this Partition
     * record. The first 16 bytes of this pointer are read.
     */
    PrimaryPartition( char* bytes ) throw( Exception );

    /**
     * Destructor.
     */
    ~PrimaryPartition();

    /**
     * Returns whether the bootable status is set for this Partition
     */
    bool isBootable();

    /**
     * Returns the type of this Partition
     *
     * @see Partition::getTypeDescription(unsigned char)
     */
    unsigned char getType();

};

#endif	/* _PRIMARY_PARTITION_H */

