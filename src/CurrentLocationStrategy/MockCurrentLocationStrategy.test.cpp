#include "MockCurrentLocationStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("returns provided coordinats", "[MockCurrentLocationStrategy]") {
    Coordinates coordinates = Coordinates(42.359285, -71.068276);
    MockCurrentLocationStrategy currentLocationStrategy = MockCurrentLocationStrategy(coordinates);

    Coordinates currentCoordinates = currentLocationStrategy.get();

    REQUIRE(currentCoordinates.latitude == coordinates.latitude);
    REQUIRE(currentCoordinates.longitude == coordinates.longitude);
}


