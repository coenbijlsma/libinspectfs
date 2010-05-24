#include "Property.h"

Property::Property(string name, string value) {
    this->name = name;
    this->value = value;
}

Property::~Property(){}

string Property::getName() {
    return this->name;
}

string Property::getValue() {
    return this->value;
}