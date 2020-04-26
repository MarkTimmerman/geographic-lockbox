#include "LedProgressIndicatorsStrategy.h"
#include <Arduino.h>

LedProgressIndicatorsStrategy::LedProgressIndicatorsStrategy(int* initial_pins, int initial_number_of_zones) {
    pins = initial_pins;
    number_of_zones = initial_number_of_zones;
    set_pin_modes();
}

void LedProgressIndicatorsStrategy::set_pin_modes() {
    for (int pin_index=0; pin_index<number_of_zones; pin_index++) {
        pinMode(pins[pin_index], OUTPUT);
    }
}

void LedProgressIndicatorsStrategy::set_number_of_zones_visited(int number_of_zones_visited) {
    for (int pin_index=0; pin_index<number_of_zones; pin_index++) {
        digitalWrite(pins[pin_index], pin_index < number_of_zones_visited);
    }
}

