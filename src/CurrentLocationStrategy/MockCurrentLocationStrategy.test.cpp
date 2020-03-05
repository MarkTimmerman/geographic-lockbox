#include "MockCurrentLocationStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("returns provided coordinates", "[MockCurrentLocationStrategy]") {
    double latitude = 42.359285;
    double longitude = -71.068276;
    Coordinates coordinates = Coordinates(latitude, longitude);
    MockCurrentLocationStrategy currentLocationStrategy = MockCurrentLocationStrategy(coordinates);

    Coordinates currentCoordinates = currentLocationStrategy.get();

    REQUIRE(currentCoordinates.latitude == latitude);
    REQUIRE(currentCoordinates.longitude == longitude);
}


