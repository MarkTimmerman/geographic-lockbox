#include "Zone.h"
#include "../../testing/catch.hpp"

TEST_CASE("can build Zone from latitude, longitude, and radius", "[Zone]") {
    double latitude = 43.5;
    double longitude = -73.4;
    double radius = 0.15;

    Zone zone = Zone(latitude, longitude, radius);

    REQUIRE(zone.coordinates.latitude == latitude);
    REQUIRE(zone.coordinates.longitude == longitude);
    REQUIRE(zone.radius == radius);
    REQUIRE(zone.has_been_visited == false);
}


TEST_CASE("can visit Zone", "[Zone]") {
    Zone zone = Zone();

    zone.visit();

    REQUIRE(zone.has_been_visited == true);
}

TEST_CASE("returns true when given coordinates inside the zone", "[Zone]") {
    Zone zone = Zone(42.359285, -71.068276, 2.0);
    Coordinates coordinates = Coordinates(42.354927, -71.091457);

    bool isInsideZone = zone.are_coordinates_inside(coordinates);

    REQUIRE(isInsideZone == true);
}

TEST_CASE("returns false when given coordinates outside the zone", "[Zone]") {
    Zone zone = Zone(42.359285, -71.068276, 1.0);
    Coordinates coordinates = Coordinates(42.354927, -71.091457);

    bool isInsideZone = zone.are_coordinates_inside(coordinates);

    REQUIRE(isInsideZone == false);
}
