#ifndef __ZOLLSTOCK_VELOCITY_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_VELOCITY_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/length_units.hpp>
#include <zollstock/time_units.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using centimeter_per_second = unit_fraction<centimeter , second>;
            using centimeter_per_minute = unit_fraction<centimeter , minute>;
            using centimeter_per_hour   = unit_fraction<centimeter , hour  >;

            using decimeter_per_second  = unit_fraction<decimeter  , second>;
            using decimeter_per_minute  = unit_fraction<decimeter  , minute>;
            using decimeter_per_hour    = unit_fraction<decimeter  , hour  >;

            using meter_per_second      = unit_fraction<meter      , second>;
            using meter_per_minute      = unit_fraction<meter      , minute>;
            using meter_per_hour        = unit_fraction<meter      , hour  >;

            using decameter_per_second  = unit_fraction<decameter  , second>;
            using decameter_per_minute  = unit_fraction<decameter  , minute>;
            using decameter_per_hour    = unit_fraction<decameter  , hour  >;

            using hectometer_per_second = unit_fraction<hectometer , second>;
            using hectometer_per_minute = unit_fraction<hectometer , minute>;
            using hectometer_per_hour   = unit_fraction<hectometer , hour  >;

            using kilometer_per_second  = unit_fraction<kilometer  , second>;
            using kilometer_per_minute  = unit_fraction<kilometer  , minute>;
            using kilometer_per_hour    = unit_fraction<kilometer  , hour  >;

        }

    }

}


#endif //__ZOLLSTOCK_VELOCITY_UNIT_TYPES_HPP__
