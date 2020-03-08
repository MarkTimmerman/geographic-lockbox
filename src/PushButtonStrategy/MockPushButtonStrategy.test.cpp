#include "MockPushButtonStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("is_pushed() returns true if set to true", "[MockPushButtonStrategy]") {
    MockPushButtonStrategy strategy = MockPushButtonStrategy(true);

    bool is_pushed = strategy.is_pushed();

    REQUIRE(is_pushed == true);
}

TEST_CASE("is_pushed() returns false if set to false", "[MockPushButtonStrategy]") {
    MockPushButtonStrategy strategy = MockPushButtonStrategy(false);

    bool is_pushed = strategy.is_pushed();

    REQUIRE(is_pushed == false);
}

