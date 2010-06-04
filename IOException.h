/* 
 * File:   IOException.h
 * Author: coen
 *
 * Created on June 1, 2010, 2:12 PM
 */

#ifndef _IOEXCEPTION_H
#define	_IOEXCEPTION_H

#include "Exception.h"

class IOException : public Exception {

protected:
    string _what;

public:

    IOException();

    IOException( string what );

    virtual ~IOException() throw();
};

#endif	/* _IOEXCEPTION_H */

