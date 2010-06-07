/* 
 * File:   Scanner.h
 * Author: coen
 *
 * Created on May 24, 2010, 5:20 PM
 */

#ifndef _SCANNER_H
#define	_SCANNER_H

#include <libudev.h>
#include <string>
#include <vector>
#include "Device.h"

using std::string;
using std::vector;

class Scanner {

private:
    vector<Device*> _devices;
    struct udev* _udev;

    Device* findBySyspath( string syspath );

public:

    Scanner();

    ~Scanner();

    vector<Device*> scan();
};

// .so stuff
typedef Scanner* create_scanner_t();
typedef bool destroy_scanner_t(Scanner* scanner);

#endif	/* _SCANNER_H */

