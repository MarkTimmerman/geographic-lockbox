#ifndef NOT_IMPLEMENTED_ERROR_H
#define NOT_IMPLEMENTED_ERROR_H

#include <exception>
using namespace std;

class NotImplementedError: public exception {
    virtual const char* what() const throw() {
        return "Method not implemented";
    }
};

#endif
