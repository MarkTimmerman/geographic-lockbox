#ifndef ZONE_H
#define ZONE_H

#ifdef ARDUINO_ARCH_AVR
    #include "Coordinates.h"
#else
    #include "../Coordinates/Coordinates.h"
#endif

class Zone {
    public:
        Zone();
        Zone(double, double, double);

        Coordinates coordinates;
        double radius;
        bool has_been_visited;

        void visit();
        bool are_coordinates_inside(Coordinates);
};

#endif
