#ifndef __ZOLLSTOCK_VELOCITY_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_VELOCITY_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/length_units.hpp>
#include <zollstock/time_units.hpp>


namespace zollstock::inline unit::inline types
{

    using centimeter_per_second = divide_units_v<centimeter , second>;
    using centimeter_per_minute = divide_units_v<centimeter , minute>;
    using centimeter_per_hour   = divide_units_v<centimeter , hour  >;

    using decimeter_per_second  = divide_units_v<decimeter  , second>;
    using decimeter_per_minute  = divide_units_v<decimeter  , minute>;
    using decimeter_per_hour    = divide_units_v<decimeter  , hour  >;

    using meter_per_second      = divide_units_v<meter      , second>;
    using meter_per_minute      = divide_units_v<meter      , minute>;
    using meter_per_hour        = divide_units_v<meter      , hour  >;

    using decameter_per_second  = divide_units_v<decameter  , second>;
    using decameter_per_minute  = divide_units_v<decameter  , minute>;
    using decameter_per_hour    = divide_units_v<decameter  , hour  >;

    using hectometer_per_second = divide_units_v<hectometer , second>;
    using hectometer_per_minute = divide_units_v<hectometer , minute>;
    using hectometer_per_hour   = divide_units_v<hectometer , hour  >;

    using kilometer_per_second  = divide_units_v<kilometer  , second>;
    using kilometer_per_minute  = divide_units_v<kilometer  , minute>;
    using kilometer_per_hour    = divide_units_v<kilometer  , hour  >;

}


#endif //__ZOLLSTOCK_VELOCITY_UNIT_TYPES_HPP__
