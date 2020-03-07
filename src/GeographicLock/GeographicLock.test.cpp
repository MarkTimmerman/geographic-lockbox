#include "GeographicLock.h"
#include "../../testing/catch.hpp"

#include "../Coordinates/Coordinates.h"
#include "../CurrentLocationStrategy/MockCurrentLocationStrategy.h"

TEST_CASE("returns true if current location is inside zone being located", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(currentLocationStrategy);
    vector<Zone> zones { Zone(42.354927, -71.091457, 2.0) };
    lock.set_zones(zones);
    lock.zoneBeingLocated = &zones[0];

    bool is_inside_zone = lock.is_current_location_inside_zone_being_located();

    REQUIRE(is_inside_zone == true);
}

TEST_CASE("returns false if current location is outside zone being located", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(currentLocationStrategy);
    vector<Zone> zones { Zone(42.354927, -71.091457, 0.0) };
    lock.set_zones(zones);
    lock.zoneBeingLocated = &zones[0];

    bool is_inside_zone = lock.is_current_location_inside_zone_being_located();

    REQUIRE(is_inside_zone == false);
}

TEST_CASE("returns true if all zones have been visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(currentLocationStrategy);
    vector<Zone> zones {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030)
    };
    lock.set_zones(zones);
    lock.zones[0].visit();
    lock.zones[1].visit();

    double haveAllZonesBeenVisited = lock.have_visited_all_zones();

    REQUIRE(haveAllZonesBeenVisited == true);
}

TEST_CASE("returns false if not all zones have been visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(currentLocationStrategy);
    vector<Zone> zones {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030)
    };
    lock.set_zones(zones);
    lock.zones[0].visit();

    double haveAllZonesBeenVisited = lock.have_visited_all_zones();

    REQUIRE(haveAllZonesBeenVisited == false);
}

TEST_CASE("returns 0 when ono zones have been visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(currentLocationStrategy);
    vector<Zone> zones {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030)
    };
    lock.set_zones(zones);

    int numberOfZonesVisited = lock.get_number_of_zones_visited();

    REQUIRE(numberOfZonesVisited == 0);
}

TEST_CASE("returns 1 when one zone has been visited", "[GeographicLock]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLock lock = GeographicLock(currentLocationStrategy);
    vector<Zone> zones {
        Zone(42.359285, -71.068276, 0.015),
        Zone(42.354927, -71.091457, 0.030)
    };
    lock.set_zones(zones);
    lock.zones[0].visit();

    int numberOfZonesVisited = lock.get_number_of_zones_visited();

    REQUIRE(numberOfZonesVisited == 1);
}

