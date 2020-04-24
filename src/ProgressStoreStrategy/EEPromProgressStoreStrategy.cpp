#include "EEPromProgressStoreStrategy.h"
#include <EEPROM.h>

EEPromProgressStoreStrategy::EEPromProgressStoreStrategy(int address) {
    eeprom_address = address;
}

int EEPromProgressStoreStrategy::get_number_of_zones_visited() {
    return EEPROM.read(eeprom_address);
}

void EEPromProgressStoreStrategy::set_number_of_zones_visited(int number_of_zones_visited) {
    EEPROM.write(eeprom_address, number_of_zones_visited);
}

