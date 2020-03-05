#include "MockCurrentLocationStrategy.h"

MockCurrentLocationStrategy::MockCurrentLocationStrategy(Coordinates initialCoordinates) {
    coordinates = initialCoordinates;
}

Coordinates MockCurrentLocationStrategy::get() {
    return coordinates;
}
