#ifndef GEOGRAPHIC_LOCK_H
#define GEOGRAPHIC_LOCK_H

#include "../GeographicLockState/GeographicLockState.h"
#include "../Zone/Zone.h"
#include "../CurrentLocationStrategy/CurrentLocationStrategy.h"
#include <vector>

using namespace std;

class GeographicLock {
    public:
        GeographicLock(CurrentLocationStrategy*);
        void set_zones(vector<Zone>);
        GeographicLockState get_state();

    private:
        vector<Zone> zones;
        Zone* zone_being_located;
        CurrentLocationStrategy* current_location_strategy;

        void update_zone_being_located();
        bool have_all_zones_been_visited();
        int get_number_of_zones_visited();
        int get_total_number_of_zones();
        void throw_if_no_zones();
        GeographicLockState build_current_state();
        double get_distance_to_zone_being_located();
        void visit_current_zone_if_current_location_is_inside();
        bool is_current_location_inside_zone_being_located();
};

#endif
