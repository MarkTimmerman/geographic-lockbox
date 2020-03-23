#include "Latch.h"
#include <Servo.h>

Latch::Latch(int servo_pin) {
    servo = new Servo();
    servo->attach(servo_pin);
    angle_for_opened = 0;
    angle_for_closed = 0;
}

void Latch::set_angle_for_opened(int angle_for_opened_to_set) {
    angle_for_opened = angle_for_opened_to_set;
}

void Latch::set_angle_for_closed(int angle_for_closed_to_set) {
    angle_for_closed = angle_for_closed_to_set;
}

void Latch::open() {
    servo->write(angle_for_opened);
}

void Latch::close() {
    servo->write(angle_for_closed);
}
