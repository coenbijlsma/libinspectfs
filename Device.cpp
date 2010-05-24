#include "Device.h"

Device::Device(udev_device* dev) {
    this->dev = dev;
}

Device::~Device() {

    vector<Property*>::iterator it = this->properties.begin();

    while( it != this->properties.end() ) {
        Property* prop = *it;
        delete prop;
        it++;
    }

    udev_device_unref( this->dev );
}

string Device::getDevNode() {
    return string( udev_device_get_devnode( this->dev ) );
}

vector<Property*> Device::getProperties() {
    if ( !this->properties.size() ) {
        struct udev_list_entry* entry 
            = udev_device_get_properties_list_entry( this->dev );

        while( entry ) {
            Property* property = new Property(
                    string( udev_list_entry_get_name( entry ) )
                    , string( udev_list_entry_get_value( entry ) )
            );
            this->properties.push_back( property );
            entry = udev_list_entry_get_next( entry );
        }
        
    }

    return this->properties;
}

Property* Device::getPropertyByName(string name) {
    vector<Property*> props = this->getProperties();
    vector<Property*>::iterator it = props.begin();

    while( it != props.end() ) {
        Property* prop = *it;
        if( prop->getName().compare( name ) == 0 ) {
            return prop;
        }
        it++;
    }

    return (Property*)0;
}

string Device::getSysPath() {
    return string( udev_device_get_syspath( this->dev ) );
}

string Device::getType() {
    return string( udev_device_get_devtype( this->dev ) );
}