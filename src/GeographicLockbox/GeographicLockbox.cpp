#include "GeographicLockbox.h"
#include "../Coordinates/Coordinates.h"

GeographicLockbox::GeographicLockbox (vector<Zone> initialZones) {
    zones = initialZones;
}

double GeographicLockbox::is_working() {
    return zones[0].coordinates.get_distance_in_miles_from(zones[1].coordinates);
}
