#ifndef MOCK_CURRENT_LOCATION_STRATEGY_H
#define MOCK_CURRENT_LOCATION_STRATEGY_H

#include "CurrentLocationStrategy.h"
#include "../Coordinates/Coordinates.h"

class MockCurrentLocationStrategy: public CurrentLocationStrategy {
    public:
        MockCurrentLocationStrategy(Coordinates);
        Coordinates coordinates;
        Coordinates get();
};

#endif

