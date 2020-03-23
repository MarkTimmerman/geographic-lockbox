#ifndef LATCH_H
#define LATCH_H

#include <Servo.h>

class Latch {
    public:
        Latch(int);
        void set_angle_for_opened(int);
        void set_angle_for_closed(int);
        void open();
        void close();
    private:
        Servo* servo;
        int angle_for_opened;
        int angle_for_closed;
};

#endif

