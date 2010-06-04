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

    unsigned char _chsFirst[ 3 ];

    unsigned char _type;

    unsigned char _chsLast[ 3 ];

    unsigned char _lbaFirst[ 4 ];

    unsigned char _sectorCount[ 4 ];
    
public:

    static const unsigned short STATUS_BOOTABLE = 0x80;
    static const unsigned short STATUS_NON_BOOTABLE = 0x00;

    
    PrimaryPartition( char* bytes ) throw( Exception );

    ~PrimaryPartition();

    bool isBootable();

    unsigned char getType();

};

#endif	/* _PRIMARY_PARTITION_H */

