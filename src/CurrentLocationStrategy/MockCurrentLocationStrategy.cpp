#include "MockCurrentLocationStrategy.h"

MockCurrentLocationStrategy::MockCurrentLocationStrategy(Coordinates initial_coordinates) {
    coordinates = initial_coordinates;
}

Coordinates MockCurrentLocationStrategy::get() {
    return coordinates;
}
