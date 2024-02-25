#ifndef __ZOLLSTOCK_MASS_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_MASS_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>


namespace zollstock::inline units::inline types
{

    template <prefix_c Prefix>
    struct basic_gram
    {
        static constexpr quantity_data mass{ 1, Prefix::factor, Prefix::symbol + "g"_us };
    };

    using quectogram = basic_gram<quecto    >;
    using rontogram  = basic_gram<ronto     >;
    using yoctogram  = basic_gram<yocto     >;
    using zeptogram  = basic_gram<zepto     >;
    using attogram   = basic_gram<atto      >;
    using femtogram  = basic_gram<femto     >;
    using picogram   = basic_gram<pico      >;
    using nanogram   = basic_gram<nano      >;
    using microgram  = basic_gram<micro     >;
    using milligram  = basic_gram<milli     >;
    using centigram  = basic_gram<centi     >;
    using decigram   = basic_gram<deci      >;
    using gram       = basic_gram<unprefixed>;
    using decagram   = basic_gram<deca      >;
    using hectogram  = basic_gram<hecto     >;
    using kilogram   = basic_gram<kilo      >;
    using megagram   = basic_gram<mega      >;
    using gigagram   = basic_gram<giga      >;
    using teragram   = basic_gram<tera      >;
    using petagram   = basic_gram<peta      >;
    using exagram    = basic_gram<exa       >;
    using zettagram  = basic_gram<zetta     >;
    using yottagram  = basic_gram<yotta     >;
    using ronnagram  = basic_gram<ronna     >;
    using quettagram = basic_gram<quetta    >;

}


#endif //__ZOLLSTOCK_MASS_UNIT_TYPES_HPP__
