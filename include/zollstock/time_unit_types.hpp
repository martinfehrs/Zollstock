#ifndef __ZOLLSTOCK_TIME_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_TIME_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            template <typename Prefix>
            struct basic_second
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, Prefix::factor, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, Prefix::symbol + "s"_us, ""_us };
            };

            using quektosecond = basic_second<quekto    >;
            using rontosecond  = basic_second<ronto     >;
            using yoktosecond  = basic_second<yokto     >;
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
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 60.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "min"_us, ""_us };
            };

            struct hour
            {
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 3'600.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "h"_us, ""_us };
            };

            struct day
            {
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 86'400.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "d"_us, ""_us };
            };

            struct year
            {
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 31'536'000.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "a"_us, ""_us };
            };

        }

    }

}


#endif //__ZOLLSTOCK_TIME_UNIT_TYPES_HPP__
