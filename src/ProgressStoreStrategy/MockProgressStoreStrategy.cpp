#include "MockProgressStoreStrategy.h"

MockProgressStoreStrategy::MockProgressStoreStrategy() {
    number_of_zones_visited = 0;
}

int MockProgressStoreStrategy::get_number_of_zones_visited() {
    return number_of_zones_visited;
}

void MockProgressStoreStrategy::set_number_of_zones_visited(int new_number_of_zones_visited) {
    number_of_zones_visited = new_number_of_zones_visited;
}
