#include "IOException.h"

IOException::IOException()
    : Exception() {

}

IOException::IOException( string what )
    : Exception( what ) {
    
}

IOException::~IOException() throw() {

}