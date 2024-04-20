#ifndef __ZOLLSTOCK_TIME_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_TIME_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>


namespace zollstock::inline units::inline types
{

    template <prefix_c Prefix>
    struct basic_second
    {
        static constexpr auto quantity = quantity_t::time;
        static constexpr auto symbol = Prefix::symbol + "s"_us;
        static constexpr auto factor = Prefix::factor;
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

    struct minute
    {
        static constexpr auto quantity = quantity_t::time;
        static constexpr auto symbol = "min"_us;
        static constexpr auto factor = 60.0L;
    };

    struct hour
    {
        static constexpr auto quantity = quantity_t::time;
        static constexpr auto symbol = "h"_us;
        static constexpr auto factor = 3'600.0L;
    };

    struct day
    {
        static constexpr auto quantity = quantity_t::time;
        static constexpr auto symbol = "d"_us;
        static constexpr auto factor = 86'400.0L;
    };

    struct year
    {
        static constexpr auto quantity = quantity_t::time;
        static constexpr auto symbol = "a"_us;
        static constexpr auto factor = 31'536'000.0L;
    };

}


#endif //__ZOLLSTOCK_TIME_UNIT_TYPES_HPP__
