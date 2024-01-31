#ifndef __ZOLLSTOCK_LENGTH_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_LENGTH_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>


namespace zollstock::inline units::inline types
{

    template <prefix_c Prefix>
    struct basic_meter : unit
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data length{ 1, Prefix::factor, Prefix::symbol + "m"_us };
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


#endif //__ZOLLSTOCK_LENGTH_UNIT_TYPES_HPP__
