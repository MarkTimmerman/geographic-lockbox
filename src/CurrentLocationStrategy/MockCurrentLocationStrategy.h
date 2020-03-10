#ifndef MOCK_CURRENT_LOCATION_STRATEGY_H
#define MOCK_CURRENT_LOCATION_STRATEGY_H

#include "CurrentLocationStrategy.h"

#ifdef ARDUINO_ARCH_AVR
    #include "Coordinates.h"
#else
    #include "../Coordinates/Coordinates.h"
#endif

class MockCurrentLocationStrategy : public CurrentLocationStrategy {
    public:
        MockCurrentLocationStrategy(Coordinates);
        MockCurrentLocationStrategy(Coordinates, bool);
        Coordinates get();
        bool can_get_location();
        Coordinates coordinates;
        bool can_get_location_value;
};

#endif

