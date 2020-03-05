#ifndef CURRENT_LOCATION_STRATEGY_H
#define CURRENT_LOCATION_STRATEGY_H

#include "../Coordinates/Coordinates.h"

class CurrentLocationStrategy {
    public:
        virtual Coordinates get();
};

#endif
