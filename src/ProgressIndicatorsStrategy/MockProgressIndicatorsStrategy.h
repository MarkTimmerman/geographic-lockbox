#ifndef MOCK_PROGRESS_INDICATORS_STRATEGY_H
#define MOCK_PROGRESS_INDICATORS_STRATEGY_H

#include "ProgressIndicatorsStrategy.h"

class MockProgressIndicatorsStrategy : public ProgressIndicatorsStrategy {
    public:
        MockProgressIndicatorsStrategy(int);
        void set_number_of_zones_visited(int);
        bool is_indicator_on_by_index(int);
    private:
        int number_of_zones;
        int number_of_zones_visited;
};

#endif


