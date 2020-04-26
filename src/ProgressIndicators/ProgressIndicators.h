#ifndef PROGRESS_INDICATORS_H
#define PROGRESS_INDICATORS_H

#ifdef ARDUINO_ARCH_AVR
    #include "ProgressIndicatorsStrategy.h"
#else
    #include "../ProgressIndicatorsStrategy/ProgressIndicatorsStrategy.h"
#endif

class ProgressIndicators {
    public:
        ProgressIndicators(ProgressIndicatorsStrategy*);
        void set_number_of_zones_visited(int);
    private:
        ProgressIndicatorsStrategy* strategy;
};

#endif


