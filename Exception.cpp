#include "Exception.h"

Exception::Exception()
    : _what( "" ) {

}

Exception::Exception( string what )
    : _what( what ) {

}

Exception::~Exception() throw() {

}

const char* Exception::what() const throw() {
    return this->_what.c_str();
}
