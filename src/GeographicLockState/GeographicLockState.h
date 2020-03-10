#ifndef GEOGRAPHIC_LOCK_STATE_H
#define GEOGRAPHIC_LOCK_STATE_H

class GeographicLockState {
    public:
        double miles_to_next_zone;
        int number_of_zones_visited;
        int total_number_of_zones;
        bool have_all_zones_been_visited;
};

#endif

