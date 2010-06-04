/* 
 * File:   Exception.h
 * Author: coen
 *
 * Created on June 4, 2010, 9:38 AM
 */

#ifndef _EXCEPTION_H
#define	_EXCEPTION_H

#include <exception>
#include <string>

using std::exception;
using std::string;

class Exception : public exception {

protected:
    string _what;

public:

    Exception();

    Exception( string what );

    virtual ~Exception() throw();

    virtual const char* what() const throw();
};

#endif	/* _EXCEPTION_H */

