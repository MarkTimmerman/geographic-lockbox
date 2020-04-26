#include "ProgressIndicators.h"
#include "../ProgressIndicatorsStrategy/MockProgressIndicatorsStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("can update number of zones visited to 1", "[ProgressIndicators]") {
    MockProgressIndicatorsStrategy* strategy = new MockProgressIndicatorsStrategy(2);
    ProgressIndicators progressStore = ProgressIndicators(strategy);
    
    REQUIRE(strategy->is_indicator_on_by_index(0) == false);
    REQUIRE(strategy->is_indicator_on_by_index(1) == false);

    progressStore.set_number_of_zones_visited(1);

    REQUIRE(strategy->is_indicator_on_by_index(0) == true);
    REQUIRE(strategy->is_indicator_on_by_index(1) == false);
}

TEST_CASE("can update number of zones visited to 2", "[ProgressIndicators]") {
    MockProgressIndicatorsStrategy* strategy = new MockProgressIndicatorsStrategy(3);
    ProgressIndicators progressStore = ProgressIndicators(strategy);
    
    REQUIRE(strategy->is_indicator_on_by_index(0) == false);
    REQUIRE(strategy->is_indicator_on_by_index(1) == false);
    REQUIRE(strategy->is_indicator_on_by_index(2) == false);

    progressStore.set_number_of_zones_visited(2);

    REQUIRE(strategy->is_indicator_on_by_index(0) == true);
    REQUIRE(strategy->is_indicator_on_by_index(1) == true);
    REQUIRE(strategy->is_indicator_on_by_index(2) == false);
}

TEST_CASE("can update number of zones visited to 3", "[ProgressIndicators]") {
    MockProgressIndicatorsStrategy* strategy = new MockProgressIndicatorsStrategy(3);
    ProgressIndicators progressStore = ProgressIndicators(strategy);
    
    REQUIRE(strategy->is_indicator_on_by_index(0) == false);
    REQUIRE(strategy->is_indicator_on_by_index(1) == false);
    REQUIRE(strategy->is_indicator_on_by_index(2) == false);
    REQUIRE(strategy->is_indicator_on_by_index(3) == false);

    progressStore.set_number_of_zones_visited(3);

    REQUIRE(strategy->is_indicator_on_by_index(0) == true);
    REQUIRE(strategy->is_indicator_on_by_index(1) == true);
    REQUIRE(strategy->is_indicator_on_by_index(2) == true);
    REQUIRE(strategy->is_indicator_on_by_index(3) == false);
}

