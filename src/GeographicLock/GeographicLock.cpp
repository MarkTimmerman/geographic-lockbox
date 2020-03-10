#include "GeographicLock.h"

#ifdef ARDUINO_ARCH_AVR
    #include "GeographicLockState.h"
    #include "Coordinates.h"
    #include "CurrentLocationStrategy.h"
#else
    #include "../GeographicLockState/GeographicLockState.h"
    #include "../Coordinates/Coordinates.h"
    #include "../CurrentLocationStrategy/CurrentLocationStrategy.h"
#endif

GeographicLock::GeographicLock(CurrentLocationStrategy* initial_current_location_strategy) {
    current_location_strategy = initial_current_location_strategy;
}

void GeographicLock::set_zones(Zone* initial_zones, int initial_number_of_zones) {
    zones = initial_zones;
    number_of_zones = initial_number_of_zones;
    update_zone_being_located();
}

void GeographicLock::update_zone_being_located() {
    if (have_all_zones_been_visited()) {
        zone_being_located = &zones[number_of_zones - 1];
    } else {
        zone_being_located = &zones[get_number_of_zones_visited()];
    }
}

bool GeographicLock::have_all_zones_been_visited() {
    int number_of_zones_visited = get_number_of_zones_visited();
    int total_number_of_zones = number_of_zones;
    return number_of_zones_visited == total_number_of_zones;
}

int GeographicLock::get_number_of_zones_visited() {
    int number_of_zones_visited = 0;

    for (int i=0; i<number_of_zones; i++) {
        if (zones[i].has_been_visited) {
            number_of_zones_visited++;
        }
    }

    return number_of_zones_visited;
}

GeographicLockState GeographicLock::get_state() {
    if (have_all_zones_been_visited()) {
        return build_current_state();
    }

    visit_current_zone_if_current_location_is_inside();
    return build_current_state();
}

GeographicLockState GeographicLock::build_current_state() {
    GeographicLockState state;

    state.miles_to_next_zone = get_miles_to_next_zone();
    state.number_of_zones_visited = get_number_of_zones_visited();
    state.total_number_of_zones = number_of_zones;
    state.have_all_zones_been_visited = have_all_zones_been_visited();

    return state;
}

double GeographicLock::get_miles_to_next_zone() {
    Coordinates current_location = current_location_strategy->get();
    return zone_being_located->coordinates.get_distance_in_miles_from(current_location);
}

void GeographicLock::visit_current_zone_if_current_location_is_inside() {
    if (is_current_location_inside_zone_being_located()) {
        zone_being_located->visit();
        update_zone_being_located();
    }
}

bool GeographicLock::is_current_location_inside_zone_being_located() {
    double miles_to_next_zone = get_miles_to_next_zone();
    return miles_to_next_zone <= zone_being_located->radius;
}

