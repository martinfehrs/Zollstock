#ifndef __ZOLLSTOCK_LENGTH_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_LENGTH_UNIT_TYPES_HPP__


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
            struct basic_meter
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 1, 0, 0 };
                static constexpr quantity_factors factors{ Prefix::factor, 0.0L, 0.0L };
                static constexpr quantity_symbols symbols{ Prefix::symbol + "m"_us, ""_us, ""_us };
            };

            using quectometer = basic_meter<quecto    >;
            using rontometer  = basic_meter<ronto     >;
            using yoctometer  = basic_meter<yocto     >;
            using zeptometer  = basic_meter<zepto     >;
            using attometer   = basic_meter<atto      >;
            using femtometer  = basic_meter<femto     >;
            using picometer   = basic_meter<pico      >;
            using nanometer   = basic_meter<nano      >;
            using micrometer  = basic_meter<micro     >;
            using millimeter  = basic_meter<milli     >;
            using centimeter  = basic_meter<centi     >;
            using decimeter   = basic_meter<deci      >;
            using meter       = basic_meter<unprefixed>;
            using decameter   = basic_meter<deca      >;
            using hectometer  = basic_meter<hecto     >;
            using kilometer   = basic_meter<kilo      >;
            using megameter   = basic_meter<mega      >;
            using gigameter   = basic_meter<giga      >;
            using terameter   = basic_meter<tera      >;
            using petameter   = basic_meter<peta      >;
            using exameter    = basic_meter<exa       >;
            using zettameter  = basic_meter<zetta     >;
            using yottameter  = basic_meter<yotta     >;
            using ronnameter  = basic_meter<ronna     >;
            using quettameter = basic_meter<quetta    >;

        }

    }

}


#endif //__ZOLLSTOCK_LENGTH_UNIT_TYPES_HPP__
