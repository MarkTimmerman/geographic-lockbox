#include "ProgressIndicators.h"

#ifdef ARDUINO_ARCH_AVR
    #include "ProgressIndicatorsStrategy.h"
#else
    #include "../ProgressIndicatorsStrategy/ProgressIndicatorsStrategy.h"
#endif


ProgressIndicators::ProgressIndicators(ProgressIndicatorsStrategy* initial_strategy) {
    strategy = initial_strategy;
}

void ProgressIndicators::set_number_of_zones_visited(int number_of_zones_visited) {
    strategy->set_number_of_zones_visited(number_of_zones_visited);
}

