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
        bool is_being_located;

        double get_distance_in_miles_from_coordinates(Coordinates);
};

#endif
