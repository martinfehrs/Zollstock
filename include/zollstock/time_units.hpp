#ifndef __ZOLLSTOCK_TIME_UNITS_HPP__
#define __ZOLLSTOCK_TIME_UNITS_HPP__


#include <zollstock/scalar.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>
#include <zollstock/definition_helpers.hpp>


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
                static constexpr quantity_factors factors{ 0.0L, 3600.0L, 0.0L };
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
                static constexpr quantity_symbols symbols{ ""_us, "d"_us, ""_us };
            };

        }

        inline namespace constants
        {

            inline constexpr quektosecond qs  {};
            inline constexpr rontosecond  rs  {};
            inline constexpr yoktosecond  ys  {};
            inline constexpr zeptosecond  zs  {};
            inline constexpr attosecond   as  {};
            inline constexpr femtosecond  fs  {};
            inline constexpr picosecond   ps  {};
            inline constexpr nanosecond   ns  {};
            inline constexpr microsecond  mics{};
            inline constexpr millisecond  ms  {};
            inline constexpr centisecond  cs  {};
            inline constexpr decisecond   ds  {};
            inline constexpr second       s   {};
            inline constexpr decasecond   das {};
            inline constexpr hectosecond  hs  {};
            inline constexpr kilosecond   ks  {};
            inline constexpr megasecond   Ms  {};
            inline constexpr gigasecond   Gs  {};
            inline constexpr terasecond   Ts  {};
            inline constexpr petasecond   Ps  {};
            inline constexpr exasecond    Es  {};
            inline constexpr zettasecond  Zs  {};
            inline constexpr yottasecond  Ys  {};
            inline constexpr ronnasecond  Rs  {};
            inline constexpr quettasecond Qs  {};

            inline constexpr minute      min  {};
            inline constexpr hour        h    {};
            inline constexpr day         d    {};
            inline constexpr year        a    {};

        }

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_LITERAL(quektosecond, qs  )
            ZOLLSTOCK_DEFINE_LITERAL(rontosecond , rs  )
            ZOLLSTOCK_DEFINE_LITERAL(yoktosecond , ys  )
            ZOLLSTOCK_DEFINE_LITERAL(zeptosecond , zs  )
            ZOLLSTOCK_DEFINE_LITERAL(attosecond  , as  )
            ZOLLSTOCK_DEFINE_LITERAL(femtosecond , fs  )
            ZOLLSTOCK_DEFINE_LITERAL(picosecond  , ps  )
            ZOLLSTOCK_DEFINE_LITERAL(nanosecond  , ns  )
            ZOLLSTOCK_DEFINE_LITERAL(microsecond , mics)
            ZOLLSTOCK_DEFINE_LITERAL(millisecond , ms  )
            ZOLLSTOCK_DEFINE_LITERAL(centisecond , cs  )
            ZOLLSTOCK_DEFINE_LITERAL(decisecond  , ds  )
            ZOLLSTOCK_DEFINE_LITERAL(second      , s   )
            ZOLLSTOCK_DEFINE_LITERAL(decasecond  , das )
            ZOLLSTOCK_DEFINE_LITERAL(hectosecond , hs  )
            ZOLLSTOCK_DEFINE_LITERAL(kilosecond  , ks  )
            ZOLLSTOCK_DEFINE_LITERAL(megasecond  , Ms  )
            ZOLLSTOCK_DEFINE_LITERAL(gigasecond  , Gs  )
            ZOLLSTOCK_DEFINE_LITERAL(terasecond  , Ts  )
            ZOLLSTOCK_DEFINE_LITERAL(petasecond  , Ps  )
            ZOLLSTOCK_DEFINE_LITERAL(exasecond   , Es  )
            ZOLLSTOCK_DEFINE_LITERAL(zettasecond , Zs  )
            ZOLLSTOCK_DEFINE_LITERAL(yottasecond , Ys  )
            ZOLLSTOCK_DEFINE_LITERAL(ronnasecond , Rs  )
            ZOLLSTOCK_DEFINE_LITERAL(quettasecond, Qs  )

            ZOLLSTOCK_DEFINE_LITERAL(minute      , min )
            ZOLLSTOCK_DEFINE_LITERAL(hour        , h   )
            ZOLLSTOCK_DEFINE_LITERAL(day         , d   )
            ZOLLSTOCK_DEFINE_LITERAL(year        , a   )

        }

    }

}


#endif //__ZOLLSTOCK_TIME_UNITS_HPP__
