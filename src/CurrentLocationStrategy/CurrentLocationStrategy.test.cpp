#include "CurrentLocationStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("throws on get", "[CurrentLocationStrategy]") {
    CurrentLocationStrategy currentLocationStrategy = CurrentLocationStrategy();

    CHECK_THROWS(currentLocationStrategy.get());
}

