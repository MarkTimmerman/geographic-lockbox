#include "CurrentLocationStrategy.h"

#ifdef ARDUINO_ARCH_AVR
    #include "Coordinates.h"
#else
    #include "../Coordinates/Coordinates.h"
#endif

Coordinates CurrentLocationStrategy::get() {
    Coordinates coordinates = Coordinates();
    return coordinates;
}

bool CurrentLocationStrategy::can_get_location() {
    return false;
}
