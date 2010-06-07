/* 
 * File:   Partition.h
 * Author: coen
 *
 * Created on June 7, 2010, 5:27 PM
 */

#ifndef _PARTITION_H
#define	_PARTITION_H

#include "PartitionRecord.h"
#include "Exception.h"
#include "IOException.h"

class Partition {

protected:
    PartitionRecord* _record;

public:

    Partition( PartitionRecord* record ) throw( Exception );

    virtual ~Partition();

    unsigned char* readBlock( unsigned long lba, bool keepopen ) throw( IOException );
};

#endif	/* _PARTITION_H */

