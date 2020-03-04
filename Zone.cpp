#include "Zone.h"
#include <cmath>
#include <iostream>

using namespace std;

Zone::Zone () {
    coordinates = Coordinates(0, 0);
    radius = 0.5;
    has_been_visited = false;
    is_being_located = true;
}

double Zone::get_distance_in_miles_from_coordinates(Coordinates otherCoordinates) {
    double zoneLatitudeInRadians = M_PI * coordinates.latitude / 180;
    double coordinatesLatitudeInRadians = M_PI * otherCoordinates.latitude / 180;
    double theta = coordinates.longitude - otherCoordinates.longitude;
    double thetaInRadians = M_PI * theta / 180;
    double intermediaryValue = sin(zoneLatitudeInRadians) * sin(coordinatesLatitudeInRadians)
        + cos(zoneLatitudeInRadians) * cos(coordinatesLatitudeInRadians) * cos(thetaInRadians);
    double distanceInMeters = acos(intermediaryValue) * 180 / M_PI;
    double distanceInMiles = distanceInMeters * 60 * 1.515;
    return distanceInMiles;
}

Zone Zone::build_from_latitude_longitude_and_radius(double latitude, double longitude, double radius) {
    Zone zone = Zone();
    zone.coordinates = Coordinates(latitude, longitude);
    zone.radius = radius;
    return zone;
}
