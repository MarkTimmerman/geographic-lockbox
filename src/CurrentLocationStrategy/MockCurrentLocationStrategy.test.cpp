#include "MockCurrentLocationStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("returns provided coordinates", "[MockCurrentLocationStrategy]") {
    double latitude = 42.359285;
    double longitude = -71.068276;
    Coordinates coordinates = Coordinates(latitude, longitude);
    MockCurrentLocationStrategy current_location_strategy = MockCurrentLocationStrategy(coordinates);

    Coordinates currentCoordinates = current_location_strategy.get();

    REQUIRE(currentCoordinates.latitude == latitude);
    REQUIRE(currentCoordinates.longitude == longitude);
}

TEST_CASE("returns can_get_location", "[MockCurrentLocationStrategy]") {
    double latitude = 42.359285;
    double longitude = -71.068276;
    Coordinates coordinates = Coordinates(latitude, longitude);
    MockCurrentLocationStrategy current_location_strategy = MockCurrentLocationStrategy(coordinates, true);

    bool can_get_location = current_location_strategy.can_get_location();

    REQUIRE(can_get_location == true);
}

