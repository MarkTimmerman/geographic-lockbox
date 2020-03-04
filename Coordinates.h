#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
    private:
        double latitude;
        double longitude; 

    public:
        void set_latitude(double);
        void set_longitude(double);
        double get_latitude();
        double get_longitude();
};

#endif
