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
    vector<Device*> devices;
    struct udev* udev;

public:

    Scanner();

    ~Scanner();

    vector<Device*> scan();
};

#endif	/* _SCANNER_H */

