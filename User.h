/* 
 * File:   User.h
 * Author: coen
 *
 * Created on May 29, 2010, 5:39 PM
 */

#ifndef _USER_H
#define	_USER_H

#include <unistd.h>
#include <sys/types.h>
#include <string>

using std::string;

class User {

private:
    uid_t _uid;
    uid_t _euid;

    static User* _current;
    static int _count;
    
public:

    User();

    ~User();

    bool isRoot();

    uid_t getUid();

    uid_t getEffectiveUid();

    string getName();

    static User* getCurrent();
};


#endif	/* _USER_H */

