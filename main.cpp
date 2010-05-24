/* 
 * File:   main.cpp
 * Author: coen
 *
 * Created on May 24, 2010, 5:20 PM
 */

#include <stdlib.h>
#include "Scanner.h"
#include "Device.h"
#include "Property.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

/*
 * For testing purposes only.
 * Change (project)settings to application instead of library.
 */
int main(int argc, char** argv) {

    Scanner scanner;
    vector<Device*> devices = scanner.scan();
    vector<Device*>::iterator it = devices.begin();

    while( it != devices.end() ) {
        Device* device = *it;

        Property* prop = device->getPropertyByName( string( "ID_TYPE" ) );

        if ( prop && ( string( "disk" ).compare( prop->getValue() ) == 0 ) ) {
            cout << device->getDevNode() << endl;
        }
        it++;
    }
    return (EXIT_SUCCESS);
}

