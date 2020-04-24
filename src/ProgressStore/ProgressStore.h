#ifndef PROGRESS_STORE_H
#define PROGRESS_STORE_H

#include "../ProgressStoreStrategy/ProgressStoreStrategy.h"

class ProgressStore {
    public:
        ProgressStore(ProgressStoreStrategy*);
        int get_number_of_zones_visited();
        void set_number_of_zones_visited(int);
    private:
        ProgressStoreStrategy* strategy;
};

#endif

