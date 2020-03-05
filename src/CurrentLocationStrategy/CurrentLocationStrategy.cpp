#include "CurrentLocationStrategy.h"
#include <exception>
using namespace std;

class NotImplementedError: public exception {
    virtual const char* what() const throw() {
        return "Method not implemented";
    }
} notImplementedError;

Coordinates CurrentLocationStrategy::get() {
    throw notImplementedError;
}
