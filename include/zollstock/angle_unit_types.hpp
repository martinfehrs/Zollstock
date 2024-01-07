#ifndef __ZOLLSTOCK_ANGLE_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>
#include <zollstock/math_constants.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            template <typename Prefix>
            struct basic_radian
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, Prefix::factor };
                static constexpr quantity_symbols symbols{ ""_us,  ""_us, Prefix::symbol + "rad"_us };
            };

            using quektoradian = basic_radian<quekto    >;
            using rontoradian  = basic_radian<ronto     >;
            using yoktoradian  = basic_radian<yokto     >;
            using zeptoradian  = basic_radian<zepto     >;
            using attoradian   = basic_radian<atto      >;
            using femtoradian  = basic_radian<femto     >;
            using picoradian   = basic_radian<pico      >;
            using nanoradian   = basic_radian<nano      >;
            using microradian  = basic_radian<micro     >;
            using milliradian  = basic_radian<milli     >;
            using centiradian  = basic_radian<centi     >;
            using deciradian   = basic_radian<deci      >;
            using radian       = basic_radian<unprefixed>;
            using decaradian   = basic_radian<deca      >;
            using hectoradian  = basic_radian<hecto     >;
            using kiloradian   = basic_radian<kilo      >;
            using megaradian   = basic_radian<mega      >;
            using gigaradian   = basic_radian<giga      >;
            using teraradian   = basic_radian<tera      >;
            using petaradian   = basic_radian<peta      >;
            using exaradian    = basic_radian<exa       >;
            using zettaradian  = basic_radian<zetta     >;
            using yottaradian  = basic_radian<yotta     >;
            using ronnaradian  = basic_radian<ronna     >;
            using quettaradian = basic_radian<quetta    >;

            struct degree
            {
                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, pi/180.0L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, "deg"_us };
            };

            struct arcminute
            {
                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, pi/10.8e3L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, "arcmin"_us };
            };

            struct arcsecond
            {
                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, pi/648e3L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, "arcsec"_us };
            };

            struct milliarcsecond
            {
                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, pi/648e6L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, "mas"_us };
            };

            struct microarcsecond
            {
                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, pi/648e9L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, "micas"_us };
            };

            template <typename Prefix>
            struct basic_gradian
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 0, 0, 1 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, Prefix::factor * pi/200.0L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, Prefix::symbol + "gon"_us };
            };

            using quektogradian = basic_gradian<quekto    >;
            using rontogradian  = basic_gradian<ronto     >;
            using yoktogradian  = basic_gradian<yokto     >;
            using zeptogradian  = basic_gradian<zepto     >;
            using attogradian   = basic_gradian<atto      >;
            using femtogradian  = basic_gradian<femto     >;
            using picogradian   = basic_gradian<pico      >;
            using nanogradian   = basic_gradian<nano      >;
            using microgradian  = basic_gradian<micro     >;
            using milligradian  = basic_gradian<milli     >;
            using centigradian  = basic_gradian<centi     >;
            using decigradian   = basic_gradian<deci      >;
            using gradian       = basic_gradian<unprefixed>;
            using decagradian   = basic_gradian<deca      >;
            using hectogradian  = basic_gradian<hecto     >;
            using kilogradian   = basic_gradian<kilo      >;
            using megagradian   = basic_gradian<mega      >;
            using gigagradian   = basic_gradian<giga      >;
            using teragradian   = basic_gradian<tera      >;
            using petagradian   = basic_gradian<peta      >;
            using exagradian    = basic_gradian<exa       >;
            using zettagradian  = basic_gradian<zetta     >;
            using yottagradian  = basic_gradian<yotta     >;
            using ronnagradian  = basic_gradian<ronna     >;
            using quettagradian = basic_gradian<quetta    >;

        }

    }

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_TYPES_HPP__
