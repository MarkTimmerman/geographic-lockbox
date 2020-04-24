#ifndef PROGRESS_STORE_H
#define PROGRESS_STORE_H

#ifdef ARDUINO_ARCH_AVR
    #include "ProgressStoreStrategy.h"
#else
    #include "../ProgressStoreStrategy/ProgressStoreStrategy.h"
#endif

class ProgressStore {
    public:
        ProgressStore(ProgressStoreStrategy*);
        int get_number_of_zones_visited();
        void set_number_of_zones_visited(int);
    private:
        ProgressStoreStrategy* strategy;
};

#endif

