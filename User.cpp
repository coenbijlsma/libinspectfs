#include "User.h"

User* User::_current;
int User::_count;

User::User() {
    User::_count++;
}

User::~User() {
    User::_count--;

    if ( _count == 0 ) {
        delete User::_current;
    }
}

bool User::isRoot() {
    return this->_uid == 0 || this->_euid == 0;
}

uid_t User::getUid() {
    return this->_uid;
}

uid_t User::getEffectiveUid() {
    return this->_euid;
}

string User::getName() {
    return string( getlogin() );
}

User* User::getCurrent() {
    if ( !User::_current ) {
        User::_current = new User();
        User::_current->_uid = getuid();
        User::_current->_euid = geteuid();
    }

    return User::_current;
}