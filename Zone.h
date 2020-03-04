#ifndef ZONE_H
#define ZONE_H

#include "Coordinates.h"

class Zone {
    public:
        Zone();

        Coordinates coordinates;
        double radius;
        bool has_been_visited;
        bool is_being_located;

        double get_distance_in_miles_from_coordinates(Coordinates);
        static Zone build_from_latitude_longitude_and_radius(double, double, double);
};

#endif
