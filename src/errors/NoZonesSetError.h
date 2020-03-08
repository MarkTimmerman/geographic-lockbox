#ifndef NO_ZONES_SET_ERROR_H
#define NO_ZONES_SET_ERROR_H

#include <exception>
using namespace std;

class NoZonesSetError: public exception {
    virtual const char* what() const throw() {
        return "No zones have been set";
    }
};

#endif
