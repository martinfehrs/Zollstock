#ifndef __ZOLLSTOCK_TIME_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_TIME_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>


namespace zollstock::inline units::inline types
{

    template <prefix_c Prefix>
    struct basic_second : unit
    {
        static constexpr unit_data time{ 1, Prefix::factor, Prefix::symbol + "s"_us };
    };

    using quectosecond = basic_second<quecto    >;
    using rontosecond  = basic_second<ronto     >;
    using yoctosecond  = basic_second<yocto     >;
    using zeptosecond  = basic_second<zepto     >;
    using attosecond   = basic_second<atto      >;
    using femtosecond  = basic_second<femto     >;
    using picosecond   = basic_second<pico      >;
    using nanosecond   = basic_second<nano      >;
    using microsecond  = basic_second<micro     >;
    using millisecond  = basic_second<milli     >;
    using centisecond  = basic_second<centi     >;
    using decisecond   = basic_second<deci      >;
    using second       = basic_second<unprefixed>;
    using decasecond   = basic_second<deca      >;
    using hectosecond  = basic_second<hecto     >;
    using kilosecond   = basic_second<kilo      >;
    using megasecond   = basic_second<mega      >;
    using gigasecond   = basic_second<giga      >;
    using terasecond   = basic_second<tera      >;
    using petasecond   = basic_second<peta      >;
    using exasecond    = basic_second<exa       >;
    using zettasecond  = basic_second<zetta     >;
    using yottasecond  = basic_second<yotta     >;
    using ronnasecond  = basic_second<ronna     >;
    using quettasecond = basic_second<quetta    >;

    struct minute : unit
    {
        static constexpr unit_data time{ 1, 60.0L, "min"_us };
    };

    struct hour : unit
    {
        static constexpr unit_data time{ 1, 3'600.0L, "h"_us };
    };

    struct day : unit
    {
        static constexpr unit_data time{ 1, 86'400.0L, "d"_us };
    };

    struct year : unit
    {
        static constexpr unit_data time{ 1, 31'536'000.0L, "a"_us };
    };

}


#endif //__ZOLLSTOCK_TIME_UNIT_TYPES_HPP__
