#ifndef PROGRESS_STORE_STRATEGY_H
#define PROGRESS_STORE_STRATEGY_H

class ProgressStoreStrategy {
    public:
        virtual int get_number_of_zones_visited();
        virtual void set_number_of_zones_visited(int);
};

#endif

