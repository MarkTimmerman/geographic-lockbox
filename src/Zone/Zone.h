#ifndef ZONE_H
#define ZONE_H

#include "../Coordinates/Coordinates.h"

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
