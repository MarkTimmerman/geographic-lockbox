#ifndef GEOGRAPHIC_LOCK_STATE_H
#define GEOGRAPHIC_LOCK_STATE_H

class GeographicLockState {
    public:
        double distance_to_zone_being_located;
        int number_of_zones_visited;
        int total_number_of_zones;
        bool have_all_zones_been_visited;
};

#endif

