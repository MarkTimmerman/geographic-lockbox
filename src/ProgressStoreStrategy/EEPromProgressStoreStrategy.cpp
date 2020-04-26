#include "EEPromProgressStoreStrategy.h"
#include <EEPROM.h>

EEPromProgressStoreStrategy::EEPromProgressStoreStrategy(int address, int initial_number_of_zones) {
    eeprom_address = address;
    number_of_zones = initial_number_of_zones;
}

int EEPromProgressStoreStrategy::get_number_of_zones_visited() {
    int eeprom_reading = EEPROM.read(eeprom_address);
    if (eeprom_reading >= 0 && eeprom_reading <= number_of_zones) {
        return eeprom_reading;
    }
    return 0;
}

void EEPromProgressStoreStrategy::set_number_of_zones_visited(int number_of_zones_visited) {
    EEPROM.write(eeprom_address, number_of_zones_visited);
}

