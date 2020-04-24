#ifndef EEPROM_PROGRESS_STORE_STRATEGY_H
#define EEPROM_PROGRESS_STORE_STRATEGY_H

#include "ProgressStoreStrategy.h"

class EEPromProgressStoreStrategy : public ProgressStoreStrategy {
    public:
        EEPromProgressStoreStrategy(int address);
        int get_number_of_zones_visited();
        void set_number_of_zones_visited(int);
    private:
        int eeprom_address;
};

#endif


