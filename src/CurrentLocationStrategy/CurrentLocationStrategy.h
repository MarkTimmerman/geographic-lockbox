#ifndef CURRENT_LOCATION_STRATEGY_H
#define CURRENT_LOCATION_STRATEGY_H

#ifdef ARDUINO_ARCH_AVR
    #include "Coordinates.h"
#else
    #include "../Coordinates/Coordinates.h"
#endif

class CurrentLocationStrategy {
    public:
        virtual Coordinates get();
};

#endif
