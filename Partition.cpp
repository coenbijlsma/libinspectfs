#include "Partition.h"

Partition::Partition( PartitionRecord* record ) throw( Exception) {
    if ( record == 0 ) {
        throw Exception( "Cannot create partition from empty record." );
    }
    this->_record = record;
}

Partition::~Partition() {

}

unsigned char* Partition::readBlock( unsigned long lba, bool keepopen )
        throw( IOException ) {
    return this->_record->getMBR()->getBlockDevice()->readBlock( this->_record, lba, keepopen );
}