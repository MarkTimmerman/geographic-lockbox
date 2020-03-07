#ifndef GEOGRAPHIC_LOCK_H
#define GEOGRAPHIC_LOCK_H

#include "../Zone/Zone.h"
#include "../CurrentLocationStrategy/CurrentLocationStrategy.h"
#include <vector>

using namespace std;

class GeographicLock {
    public:
        GeographicLock(CurrentLocationStrategy*);

        CurrentLocationStrategy* currentLocationStrategy;
        vector<Zone> zones;
        Zone* zoneBeingLocated;

        void set_zones(vector<Zone>);
        double distanceToZoneBeingLocated;
        void update_state();
        void update_distance_to_zone_being_located();
        bool is_current_location_inside_zone_being_located();
        bool have_visited_all_zones();
        int get_number_of_zones_visited();
};

#endif
