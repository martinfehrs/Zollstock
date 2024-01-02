#ifndef __ZOLLSTOCK_VELOCITY_UNITS_HPP__
#define __ZOLLSTOCK_VELOCITY_UNITS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/length_units.hpp>
#include <zollstock/time_units.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using centimeter_per_second = unit_division<centimeter , second>;
            using centimeter_per_minute = unit_division<centimeter , minute>;
            using centimeter_per_hour   = unit_division<centimeter , hour  >;

            using decimeter_per_second  = unit_division<decimeter  , second>;
            using decimeter_per_minute  = unit_division<decimeter  , minute>;
            using decimeter_per_hour    = unit_division<decimeter  , hour  >;

            using meter_per_second      = unit_division<meter      , second>;
            using meter_per_minute      = unit_division<meter      , minute>;
            using meter_per_hour        = unit_division<meter      , hour  >;

            using decameter_per_second  = unit_division<decameter  , second>;
            using decameter_per_minute  = unit_division<decameter  , minute>;
            using decameter_per_hour    = unit_division<decameter  , hour  >;

            using hectometer_per_second  = unit_division<hectometer, second>;
            using hectometer_per_minute  = unit_division<hectometer, minute>;
            using hectometer_per_hour    = unit_division<hectometer, hour  >;

            using kilometer_per_second  = unit_division<kilometer  , second>;
            using kilometer_per_minute  = unit_division<kilometer  , minute>;
            using kilometer_per_hour    = unit_division<kilometer  , hour  >;

        }

    }

}


#endif //__ZOLLSTOCK_VELOCITY_UNITS_HPP__
