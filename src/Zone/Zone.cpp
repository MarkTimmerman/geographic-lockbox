#include "Zone.h"

Zone::Zone () {
    coordinates = Coordinates(0, 0);
    radius = 0.5;
    has_been_visited = false;
    is_being_located = true;
}

Zone::Zone(double initialLatitude, double initialLongitude, double initialRadius) {
    coordinates = Coordinates(initialLatitude, initialLongitude);
    radius = initialRadius;
    has_been_visited = false;
    is_being_located = true;
}

