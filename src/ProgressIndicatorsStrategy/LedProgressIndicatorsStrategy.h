#ifndef LED_PROGRESS_INDICATORS_STRATEGY_H
#define LED_PROGRESS_INDICATORS_STRATEGY_H

#include "ProgressIndicatorsStrategy.h"

class LedProgressIndicatorsStrategy : public ProgressIndicatorsStrategy {
    public:
        LedProgressIndicatorsStrategy(int*, int);
        void set_number_of_zones_visited(int);
    private:
        int* pins;
        int number_of_zones;
        void set_pin_modes();
};

#endif



