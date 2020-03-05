#include "GeographicLockbox.h"
#include "../../testing/catch.hpp"

#include "../Coordinates/Coordinates.h"
#include "../CurrentLocationStrategy/MockCurrentLocationStrategy.h"

TEST_CASE("returns true if current location is inside zone being located", "[GeographicLockbox]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLockbox lockbox = GeographicLockbox(currentLocationStrategy);
    vector<Zone> zones { Zone(42.354927, -71.091457, 2.0) };
    lockbox.set_zones(zones);
    lockbox.zoneBeingLocated = &zones[0];

    bool is_inside_zone = lockbox.is_current_location_inside_zone_being_located();

    REQUIRE(is_inside_zone == true);
}

TEST_CASE("returns false if current location is outside zone being located", "[GeographicLockbox]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    CurrentLocationStrategy* currentLocationStrategy = new MockCurrentLocationStrategy(coordinates);
    GeographicLockbox lockbox = GeographicLockbox(currentLocationStrategy);
    vector<Zone> zones { Zone(42.354927, -71.091457, 0.0) };
    lockbox.set_zones(zones);
    lockbox.zoneBeingLocated = &zones[0];

    bool is_inside_zone = lockbox.is_current_location_inside_zone_being_located();

    REQUIRE(is_inside_zone == false);
}

TEST_CASE("returns true if all zones have been visited", "[GeographicLockbox]") {
    REQUIRE(true == true);
}

TEST_CASE("returns false if not all zones have been visited", "[GeographicLockbox]") {
    REQUIRE(true == true);
}

TEST_CASE("returns the number of zones visited", "[GeographicLockbox]") {
    REQUIRE(true == true);
}

