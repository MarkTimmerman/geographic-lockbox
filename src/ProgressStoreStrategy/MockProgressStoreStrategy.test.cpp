#include "MockProgressStoreStrategy.h"
#include "../../testing/catch.hpp"

TEST_CASE("can get and set number of zones visited", "[MockProgressStoreStrategy]") {
    MockProgressStoreStrategy strategy;

    REQUIRE(strategy.get_number_of_zones_visited() == 0);

    strategy.set_number_of_zones_visited(1);
    REQUIRE(strategy.get_number_of_zones_visited() == 1);
}


TEST_CASE("can get and set number of zones visited, defined as a pointer", "[MockProgressStoreStrategy]") {
    MockProgressStoreStrategy* strategy = new MockProgressStoreStrategy();

    REQUIRE(strategy->get_number_of_zones_visited() == 0);

    strategy->set_number_of_zones_visited(1);
    REQUIRE(strategy->get_number_of_zones_visited() == 1);
}


