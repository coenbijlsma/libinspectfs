/* 
 * File:   Partition.h
 * Author: coen
 *
 * Created on June 1, 2010, 5:05 PM
 */

#ifndef _PARTITIONRECORD_H
#define	_PARTITIONRECORD_H

#include <map>
#include <string>
#include "MBR.h"
#include "Exception.h"

using std::map;
using std::string;

class MBR;

class PartitionRecord {

protected:

    /**
     * The MBR this PartitionRecord belongs to.
     */
    MBR* _mbr;

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
    int _chsFirst[ 3 ];

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
    int _chsLast[ 3 ];

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
    PartitionRecord( MBR* mbr, char* bytes ) throw( Exception );

    /**
     * Destructor.
     */
    virtual ~PartitionRecord();
    
    /**
     * Returns whether this partition is bootable.
     *
     * @return Whether this partition is bootable.
     */
    bool isBootable();

    /**
     * Gets the type of this partition.
     *
     * @return the type of this Partition.
     */
    unsigned char getType();

    unsigned short getFirstCylinder();

    unsigned short getFirstHead();

    unsigned short getFirstSector();

    unsigned short getLastCylinder();

    unsigned short getLastHead();

    unsigned short getLastSector();

    /**
     * Returns the first LBA of this partition.
     */
    unsigned long getLBAFirst();

    /**
     * Returns the amount of sectors on this partition.
     */
    unsigned long getSectorCount();

    /**
     * Returns whether this PartitionRecord represents an extended partition.
     */
    bool isExtended();

    /**
     * Returns the MBR this PartitionRecord belongs to.
     */
    MBR* getMBR();

    /**
     * Gets the type of partition according to the given type
     *
     * @param type The type of the partition (I.E. 0x83)
     * @return The description of the partition type.
     */
    static string getTypeDescription( unsigned char type );
};

#endif	/* _PARTITIONRECORD_H */

