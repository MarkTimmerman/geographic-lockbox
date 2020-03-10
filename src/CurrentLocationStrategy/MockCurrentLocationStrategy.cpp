#include "MockCurrentLocationStrategy.h"

MockCurrentLocationStrategy::MockCurrentLocationStrategy(Coordinates initial_coordinates) {
    coordinates = initial_coordinates;
}

MockCurrentLocationStrategy::MockCurrentLocationStrategy(Coordinates initial_coordinates, bool initial_can_get_location_value) {
    coordinates = initial_coordinates;
    can_get_location_value = initial_can_get_location_value;
}

Coordinates MockCurrentLocationStrategy::get() {
    return coordinates;
}

bool MockCurrentLocationStrategy::can_get_location() {
    return can_get_location_value;
}
