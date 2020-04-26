#include "MockProgressIndicatorsStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("all indicators are off when no zones visited", "[MockProgressIndicatorsStrategy]") {
    MockProgressIndicatorsStrategy strategy = MockProgressIndicatorsStrategy(3);

    REQUIRE(strategy.is_indicator_on_by_index(0) == false);
    REQUIRE(strategy.is_indicator_on_by_index(1) == false);
    REQUIRE(strategy.is_indicator_on_by_index(2) == false);
}

TEST_CASE("first indicator is on when 1 zone visited ", "[MockProgressIndicatorsStrategy]") {
    MockProgressIndicatorsStrategy strategy = MockProgressIndicatorsStrategy(3);

    strategy.set_number_of_zones_visited(1);

    REQUIRE(strategy.is_indicator_on_by_index(0) == true);
    REQUIRE(strategy.is_indicator_on_by_index(1) == false);
    REQUIRE(strategy.is_indicator_on_by_index(2) == false);
}

TEST_CASE("first and second indicators are on when 2 zone visited ", "[MockProgressIndicatorsStrategy]") {
    MockProgressIndicatorsStrategy strategy = MockProgressIndicatorsStrategy(3);

    strategy.set_number_of_zones_visited(2);

    REQUIRE(strategy.is_indicator_on_by_index(0) == true);
    REQUIRE(strategy.is_indicator_on_by_index(1) == true);
    REQUIRE(strategy.is_indicator_on_by_index(2) == false);
}

TEST_CASE("all indicators are on when all zones visited ", "[MockProgressIndicatorsStrategy]") {
    MockProgressIndicatorsStrategy strategy = MockProgressIndicatorsStrategy(3);

    strategy.set_number_of_zones_visited(3);

    REQUIRE(strategy.is_indicator_on_by_index(0) == true);
    REQUIRE(strategy.is_indicator_on_by_index(1) == true);
    REQUIRE(strategy.is_indicator_on_by_index(2) == true);
}

