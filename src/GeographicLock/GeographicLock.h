#ifndef GEOGRAPHIC_LOCK_H
#define GEOGRAPHIC_LOCK_H

#ifdef ARDUINO_ARCH_AVR
    #include "GeographicLockState.h"
    #include "Zone.h"
    #include "CurrentLocationStrategy.h"
#else
    #include "../GeographicLockState/GeographicLockState.h"
    #include "../Zone/Zone.h"
    #include "../CurrentLocationStrategy/CurrentLocationStrategy.h"
#endif

class GeographicLock {
    public:
        GeographicLock(CurrentLocationStrategy*);
        void set_zones(Zone*, int);
        GeographicLockState get_state();

    private:
        Zone* zones;
        int number_of_zones;
        Zone* zone_being_located;
        CurrentLocationStrategy* current_location_strategy;

        void update_zone_being_located();
        bool have_all_zones_been_visited();
        int get_number_of_zones_visited();
        void throw_if_no_zones();
        GeographicLockState build_current_state();
        double get_miles_to_next_zone();
        void visit_current_zone_if_current_location_is_inside();
        bool is_current_location_inside_zone_being_located();
};

#endif
