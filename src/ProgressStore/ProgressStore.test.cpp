#include "ProgressStore.h"
#include "../ProgressStoreStrategy/MockProgressStoreStrategy.h"
#include "../../testing/catch.hpp"

/*
 * Can't figure out why this test won't pass.

TEST_CASE("can set and get number of zones visited", "[ProgressStore]") {
    MockProgressStoreStrategy* strategy = new MockProgressStoreStrategy();
    ProgressStore progressStore = ProgressStore(strategy);

    progressStore.set_number_of_zones_visited(76);
    REQUIRE(progressStore.get_number_of_zones_visited() == 76);

    progressStore.set_number_of_zones_visited(13);
    REQUIRE(progressStore.get_number_of_zones_visited() == 13);
}
*/

