/* 
 * File:   Property.h
 * Author: coen
 *
 * Created on May 24, 2010, 5:20 PM
 */

#ifndef _PROPERTY_H
#define	_PROPERTY_H

#include <string>

using std::string;

class Property {

protected:
    string name;
    string value;

public:

    /**
     * Constructor.
     *
     * @param name The name of this Property.
     * @param value The value of this Property.
     */
    Property(string name, string value);

    /**
     * Destructor.
     */
    virtual ~Property();

    /**
     * Gets the name of this Property.
     *
     * @return The name of this Property
     */
    string getName();

    /**
     * Gets the value of this Property.
     *
     * @return The value of this Property.
     */
    string getValue();
    
};

#endif	/* _PROPERTY_H */

