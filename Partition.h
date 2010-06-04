/* 
 * File:   Partition.h
 * Author: coen
 *
 * Created on June 1, 2010, 5:05 PM
 */

#ifndef _PARTITION_H
#define	_PARTITION_H

#include <map>
#include <string>

using std::map;
using std::string;

class Partition {

public:

    /**
     * Destructor.
     */
    virtual ~Partition() {}
    
    /**
     * Returns whether this partition is bootable.
     *
     * @return Whether this partition is bootable.
     */
    virtual bool isBootable() =0;

    /**
     * Gets the type of this partition.
     *
     * @return the type of this Partition.
     */
    virtual unsigned char getType() =0;

    /**
     * Gets the type of partition according to the given type
     *
     * @param type The type of the partition (I.E. 0x83)
     * @return The description of the partition type.
     */
    static string getTypeDescription( unsigned char type );
};

#endif	/* _PARTITION_H */

