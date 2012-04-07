/* 
 * File:   GPT.h
 * Author: coen
 *
 * Created on April 7, 2012, 2:49 PM
 */

#ifndef GPT_H
#define	GPT_H

#include "BlockDevice.h"
#include "IOException.h"

class GPT
{
private:
    
    BlockDevice* _block_device;
};

#endif	/* GPT_H */

