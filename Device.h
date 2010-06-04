/* 
 * File:   Device.h
 * Author: coen
 *
 * Created on May 24, 2010, 5:20 PM
 */

#ifndef _DEVICE_H
#define	_DEVICE_H

#include <string>
#include <vector>
#include <libudev.h>
#include "Property.h"

using std::string;
using std::vector;

class Device {

protected:
    struct udev_device* _dev;
    vector<Property*> _properties;

public:

    /**
     * Constructor.
     *
     * @param dev The udev device this Device is based upon.
     */
    Device( struct udev_device* dev );

    /**
     * Destructor.
     */
    virtual ~Device();

    /**
     * Gets the devicenode of this Device.
     *
     * @return The device node of this Device.
     */
    string getDevNode();

    /**
     * Gets the syspath of this Device.
     *
     * @return The syspath of this Device.
     */
    string getSysPath();

    /**
     * Gets the type of this device.
     */
    string getType();

    /**
     * Gets the properties that are available for this Device.
     *
     * @return The properties of this Device.
     */
    vector<Property*> getProperties();

    /**
     * Gets the property that has the given name.
     * If no such property exists, this function returns NULL
     *
     * @return The property that has the given name.
     */
    Property* getPropertyByName( string name );
};

#endif	/* _DEVICE_H */

