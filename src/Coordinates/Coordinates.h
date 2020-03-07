#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
    public: 
        Coordinates();
        Coordinates(double, double);

        double latitude;
        double longitude; 
        double get_distance_in_miles_from(Coordinates);

    private:
        double degrees_to_radians(double degrees);
};

#endif
