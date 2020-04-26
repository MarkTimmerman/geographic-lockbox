#include "MockProgressIndicatorsStrategy.h"

MockProgressIndicatorsStrategy::MockProgressIndicatorsStrategy(int initial_number_of_zones) {
    number_of_zones = initial_number_of_zones;
    number_of_zones_visited = 0;
}

void MockProgressIndicatorsStrategy::set_number_of_zones_visited(int new_number_of_zones_visited) {
    number_of_zones_visited = new_number_of_zones_visited;
}

bool MockProgressIndicatorsStrategy::is_indicator_on_by_index(int index) {
    return index < number_of_zones_visited;
}

