#include "GeographicLockbox.h"
#include "Coordinates.h"

GeographicLockbox::GeographicLockbox (vector<Zone> initialZones) {
    zones = initialZones;
}

double GeographicLockbox::is_working() {
    Coordinates here = Coordinates(42.348331, -71.088065);
    return zones[0].get_distance_in_miles_from_coordinates(here);
}
