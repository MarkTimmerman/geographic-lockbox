#include "Zone.h"
#include "../../testing/catch.hpp"

TEST_CASE("can build Zone from latitude, longitude, and radius", "[zone]") {
    double latitude = 43.5;
    double longitude = -73.4;
    double radius = 0.15;

    Zone zone = Zone(latitude, longitude, radius);

    REQUIRE(zone.coordinates.latitude == latitude);
    REQUIRE(zone.coordinates.longitude == longitude);
    REQUIRE(zone.radius == radius);
}

