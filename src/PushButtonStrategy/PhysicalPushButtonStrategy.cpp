#include "PhysicalPushButtonStrategy.h"
#include <Arduino.h>

PhysicalPushButtonStrategy::PhysicalPushButtonStrategy(
    int initial_momentary_switch_pin,
    int initial_led_pin
) {
    momentary_switch_pin = initial_momentary_switch_pin;
    led_pin = initial_led_pin;
    set_pin_modes();
}

void PhysicalPushButtonStrategy::set_pin_modes() {
    pinMode(momentary_switch_pin, INPUT);
    pinMode(led_pin, OUTPUT);
}

bool PhysicalPushButtonStrategy::is_pushed() {
    return digitalRead(momentary_switch_pin);
}

