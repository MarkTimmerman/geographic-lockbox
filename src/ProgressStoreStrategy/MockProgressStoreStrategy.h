#ifndef MOCK_PROGRESS_STORE_STRATEGY_H
#define MOCK_PROGRESS_STORE_STRATEGY_H

#include "ProgressStoreStrategy.h"

class MockProgressStoreStrategy : public ProgressStoreStrategy {
    public:
        MockProgressStoreStrategy();
        int get_number_of_zones_visited();
        void set_number_of_zones_visited(int);
    private:
        int number_of_zones_visited;
};

#endif

