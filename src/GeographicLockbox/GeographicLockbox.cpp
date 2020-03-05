#include "GeographicLockbox.h"
#include "../Coordinates/Coordinates.h"
#include "../CurrentLocationStrategy/CurrentLocationStrategy.h"

#include <iostream>
using namespace std;

GeographicLockbox::GeographicLockbox(CurrentLocationStrategy* initialCurrentLocationStrategy) {
    currentLocationStrategy = initialCurrentLocationStrategy;
}

void GeographicLockbox::set_zones (vector<Zone> initialZones) {
    zones = initialZones;
    zoneBeingLocated = &zones[0];
}

void GeographicLockbox::update_state() {
    update_distance_to_zone_being_located();

    if (is_current_location_inside_zone_being_located()) {
        zoneBeingLocated->visit();
    }

    if (have_visited_all_zones()) {
        printf("Success!\n");
    }
}

void GeographicLockbox::update_distance_to_zone_being_located() {
    Coordinates currentLocation = Coordinates(43, -73);
    distanceToZoneBeingLocated = zoneBeingLocated->coordinates.get_distance_in_miles_from(currentLocation);
}

bool GeographicLockbox::is_current_location_inside_zone_being_located() {
    Coordinates currentLocation = currentLocationStrategy->get();
    double distanceToZone = zoneBeingLocated->coordinates.get_distance_in_miles_from(currentLocation);
    return distanceToZone <= zoneBeingLocated->radius;
}

bool GeographicLockbox::have_visited_all_zones() {
    return false;
}

int GeographicLockbox::get_number_of_zones_visited() {
    return 0;
}
