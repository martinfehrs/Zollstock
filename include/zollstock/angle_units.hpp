#ifndef __ZOLLSTOCK_ANGLE_UNITS_HPP__
#define __ZOLLSTOCK_ANGLE_UNITS_HPP__


#include <zollstock/scalar.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock
{

    inline namespace math_constants
    {

        inline constexpr long double pi{ 3.14159265358979323846264338327950288419716939937510L };

    }

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

        }

        inline namespace constants
        {

            ZOLLSTOCK_DEFINE_SI_CONSTANTS(,radian, rad)

            inline constexpr degree       deg    {};

        }

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_LITERAL(quektoradian, qrad  )
            ZOLLSTOCK_DEFINE_LITERAL(rontoradian , rrad  )
            ZOLLSTOCK_DEFINE_LITERAL(yoktoradian , yrad  )
            ZOLLSTOCK_DEFINE_LITERAL(zeptoradian , zrad  )
            ZOLLSTOCK_DEFINE_LITERAL(attoradian  , arad  )
            ZOLLSTOCK_DEFINE_LITERAL(femtoradian , frad  )
            ZOLLSTOCK_DEFINE_LITERAL(picoradian  , prad  )
            ZOLLSTOCK_DEFINE_LITERAL(nanoradian  , nrad  )
            ZOLLSTOCK_DEFINE_LITERAL(microradian , micrad)
            ZOLLSTOCK_DEFINE_LITERAL(milliradian , mrad  )
            ZOLLSTOCK_DEFINE_LITERAL(centiradian , crad  )
            ZOLLSTOCK_DEFINE_LITERAL(deciradian  , drad  )
            ZOLLSTOCK_DEFINE_LITERAL(radian      , rad   )
            ZOLLSTOCK_DEFINE_LITERAL(decaradian  , darad )
            ZOLLSTOCK_DEFINE_LITERAL(hectoradian , hrad  )
            ZOLLSTOCK_DEFINE_LITERAL(kiloradian  , krad  )
            ZOLLSTOCK_DEFINE_LITERAL(megaradian  , Mrad  )
            ZOLLSTOCK_DEFINE_LITERAL(gigaradian  , Grad  )
            ZOLLSTOCK_DEFINE_LITERAL(teraradian  , Trad  )
            ZOLLSTOCK_DEFINE_LITERAL(petaradian  , Prad  )
            ZOLLSTOCK_DEFINE_LITERAL(exaradian   , Erad  )
            ZOLLSTOCK_DEFINE_LITERAL(zettaradian , Zrad  )
            ZOLLSTOCK_DEFINE_LITERAL(yottaradian , Yrad  )
            ZOLLSTOCK_DEFINE_LITERAL(ronnaradian , Rrad  )
            ZOLLSTOCK_DEFINE_LITERAL(quettaradian, Qrad  )

            ZOLLSTOCK_DEFINE_LITERAL(degree      , deg   )

        }

    }

    inline namespace math_constants
    {

        inline constexpr scalar<radian> pi_rad{ pi };

    }

}


#endif //__ZOLLSTOCK_ANGLE_UNITS_HPP__
