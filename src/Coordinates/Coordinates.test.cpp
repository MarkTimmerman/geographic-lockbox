#include "Coordinates.h"
#include "../../testing/catch.hpp"

TEST_CASE("can build default Coordinates", "[Coordinates]") {
    Coordinates coordinates = Coordinates();

    REQUIRE(coordinates.latitude == 0.0);
    REQUIRE(coordinates.longitude == 0.0);
}


TEST_CASE("can build Coordinates from latitude and longitude", "[Coordinates]") {
    double latitude = 42.359285;
    double longitude = -71.068276;

    Coordinates coordinates = Coordinates(latitude, longitude);

    REQUIRE(coordinates.latitude == latitude);
    REQUIRE(coordinates.longitude == longitude);
}

TEST_CASE("distance from identical coordinates is 0.0", "[Coordinates]") {
    double latitude = 42.359285;
    double longitude = -71.068276;

    Coordinates start = Coordinates(latitude, longitude);
    Coordinates end = Coordinates(latitude, longitude);

    REQUIRE(end.get_distance_in_miles_from(start) == 0.0);
}

TEST_CASE("distance from two different coordinates is correct", "[Coordinates]") {
    Coordinates start = Coordinates(42.359285, -71.068276);
    Coordinates end = Coordinates(42.354927, -71.091457);

    double distance = end.get_distance_in_miles_from(start);

    REQUIRE(distance == Approx(1.2213).epsilon(0.01));
}



