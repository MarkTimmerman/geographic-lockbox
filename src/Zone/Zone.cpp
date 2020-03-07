#include "Zone.h"

Zone::Zone () {
    coordinates = Coordinates(0, 0);
    radius = 0.5;
    has_been_visited = false;
}

Zone::Zone(double initial_latitude, double initial_longitude, double initial_radius) {
    coordinates = Coordinates(initial_latitude, initial_longitude);
    radius = initial_radius;
    has_been_visited = false;
}

void Zone::visit() {
    has_been_visited = true;
}

bool Zone::are_coordinates_inside(Coordinates maybe_within_zone) {
    double distance_to_zone_center = coordinates.get_distance_in_miles_from(maybe_within_zone);
    return distance_to_zone_center <= radius;
}

