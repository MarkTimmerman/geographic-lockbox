#include "GeographicLock.h"
#include "../GeographicLockState/GeographicLockState.h"
#include "../Coordinates/Coordinates.h"
#include "../CurrentLocationStrategy/CurrentLocationStrategy.h"
#include "../errors/NoZonesSetError.h"

GeographicLock::GeographicLock(CurrentLocationStrategy* initial_current_location_strategy) {
    current_location_strategy = initial_current_location_strategy;
}

void GeographicLock::set_zones(vector<Zone> initial_zones) {
    zones = initial_zones;
    update_zone_being_located();
}

void GeographicLock::update_zone_being_located() {
    if (have_all_zones_been_visited()) {
        zone_being_located = &zones[get_total_number_of_zones() - 1];
    } else {
        zone_being_located = &zones[get_number_of_zones_visited()];
    }
}

bool GeographicLock::have_all_zones_been_visited() {
    int number_of_zones_visited = get_number_of_zones_visited();
    int total_number_of_zones = get_total_number_of_zones();
    return number_of_zones_visited == total_number_of_zones;
}

int GeographicLock::get_number_of_zones_visited() {
    int number_of_zones_visited = 0;
    for (Zone zone : zones) {
        if (zone.has_been_visited) {
            number_of_zones_visited++;
        }
    }
    return number_of_zones_visited;
}

int GeographicLock::get_total_number_of_zones() {
    return zones.size();
}

GeographicLockState GeographicLock::get_state() {
    throw_if_no_zones();

    if (have_all_zones_been_visited()) {
        return build_current_state();
    }

    visit_current_zone_if_current_location_is_inside();
    return build_current_state();
}

void GeographicLock::throw_if_no_zones() {
    if (zones.empty()) {
        NoZonesSetError noZonesSetError;
        throw noZonesSetError;
    }
}

GeographicLockState GeographicLock::build_current_state() {
    GeographicLockState state;

    state.distance_to_zone_being_located = get_distance_to_zone_being_located();
    state.number_of_zones_visited = get_number_of_zones_visited();
    state.total_number_of_zones = get_total_number_of_zones();
    state.have_all_zones_been_visited = have_all_zones_been_visited();

    return state;
}

double GeographicLock::get_distance_to_zone_being_located() {
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
    double distance_to_zone_being_located = get_distance_to_zone_being_located();
    return distance_to_zone_being_located <= zone_being_located->radius;
}

