#include "ProgressStore.h"

#ifdef ARDUINO_ARCH_AVR
    #include "ProgressStoreStrategy.h"
#else
    #include "../ProgressStoreStrategy/ProgressStoreStrategy.h"
#endif


ProgressStore::ProgressStore(ProgressStoreStrategy* initial_strategy) {
    strategy = initial_strategy;
}

int ProgressStore::get_number_of_zones_visited() {
    return strategy->get_number_of_zones_visited();
}

void ProgressStore::set_number_of_zones_visited(int number_of_zones_visited) {
    strategy->set_number_of_zones_visited(number_of_zones_visited);
}

