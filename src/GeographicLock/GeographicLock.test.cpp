#include "GeographicLock.h"
#include "../../testing/catch.hpp"

#include "../Coordinates/Coordinates.h"
#include "../Zone/Zone.h"
#include "../CurrentLocationStrategy/MockCurrentLocationStrategy.h"

TEST_CASE("when no visits get_state returns 0 zones visited and false for all zones visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates();
    CurrentLocationStrategy* current_location_strategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(current_location_strategy);
    Zone zones[4] = {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030),
        Zone(42.369772, -71.112643, 0.010),
        Zone(42.352732, -71.110063, 0.004)
    };
    lock.set_zones(zones, 4);

    GeographicLockState state = lock.get_state();

    REQUIRE(state.number_of_zones_visited == 0);
    REQUIRE(state.have_all_zones_been_visited == false);
}

TEST_CASE("when 1 of 2 visits, get_state returns 1 zones visited and false for all zones visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* current_location_strategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(current_location_strategy);
    Zone zones[2] = {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030)
    };
    lock.set_zones(zones, 2);

    GeographicLockState state = lock.get_state();

    REQUIRE(state.number_of_zones_visited == 1);
    REQUIRE(state.have_all_zones_been_visited == false);
}

TEST_CASE("when 2 of 2 visits, get_state returns 2 zones visited and true for all zones visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    MockCurrentLocationStrategy* current_location_strategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(current_location_strategy);
    Zone zones[2] {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030)
    };
    lock.set_zones(zones, 2);

    GeographicLockState state = lock.get_state();
    current_location_strategy->coordinates = Coordinates(42.354927, -71.091457);
    state = lock.get_state();

    REQUIRE(state.number_of_zones_visited == 2);
    REQUIRE(state.have_all_zones_been_visited == true);
}

TEST_CASE("get_state returns distance to next zone", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* current_location_strategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(current_location_strategy);
    Zone zones[1] { Zone(42.354927, -71.091457, 0.015) };
    lock.set_zones(zones, 1);

    GeographicLockState state = lock.get_state();

    REQUIRE(state.miles_to_next_zone == Approx(1.2213).epsilon(0.01));
}

TEST_CASE("can set the number of zones visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* current_location_strategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(current_location_strategy);
    Zone zones[2] {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030)
    };
    lock.set_zones(zones, 2);

    lock.set_number_of_zones_visited(2);
    REQUIRE(lock.get_state().number_of_zones_visited == 2);

    lock.set_number_of_zones_visited(1);
    REQUIRE(lock.get_state().number_of_zones_visited == 1);

    lock.set_number_of_zones_visited(0);
    REQUIRE(lock.get_state().number_of_zones_visited == 0);

    lock.set_number_of_zones_visited(5);
    REQUIRE(lock.get_state().number_of_zones_visited == 2);
}

