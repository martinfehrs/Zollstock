#ifndef __ZOLLSTOCK_ANGLE_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>
#include <zollstock/math_constants.hpp>


namespace zollstock::inline unit::inline types
{

    template <prefix_c Prefix>
    struct basic_radian
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data angle{ 1, Prefix::factor, Prefix::symbol + "rad"_us };
    };

    using quectoradian = basic_radian<quecto    >;
    using rontoradian  = basic_radian<ronto     >;
    using yoctoradian  = basic_radian<yocto     >;
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
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data angle{ 1, pi/180.0L, "deg"_us };
    };

    struct arcminute
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data angle{ 1, pi/10.8e3L, "arcmin"_us };
    };

    template <prefix_c Prefix>
    struct basic_arcsecond
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data angle{ 1, Prefix::factor * pi/648e3L, Prefix::symbol + "as"_us };
    };

    template <>
    struct basic_arcsecond<unprefixed>
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data angle{ 1, pi/648e3L, "arcsec"_us };
    };

    using quectoarcsecond = basic_arcsecond<quecto    >;
    using rontoarcsecond  = basic_arcsecond<ronto     >;
    using yoctoarcsecond  = basic_arcsecond<yocto     >;
    using zeptoarcsecond  = basic_arcsecond<zepto     >;
    using attoarcsecond   = basic_arcsecond<atto      >;
    using femtoarcsecond  = basic_arcsecond<femto     >;
    using picoarcsecond   = basic_arcsecond<pico      >;
    using nanoarcsecond   = basic_arcsecond<nano      >;
    using microarcsecond  = basic_arcsecond<micro     >;
    using milliarcsecond  = basic_arcsecond<milli     >;
    using centiarcsecond  = basic_arcsecond<centi     >;
    using deciarcsecond   = basic_arcsecond<deci      >;
    using arcsecond       = basic_arcsecond<unprefixed>;
    using decaarcsecond   = basic_arcsecond<deca      >;
    using hectoarcsecond  = basic_arcsecond<hecto     >;
    using kiloarcsecond   = basic_arcsecond<kilo      >;
    using megaarcsecond   = basic_arcsecond<mega      >;
    using gigaarcsecond   = basic_arcsecond<giga      >;
    using teraarcsecond   = basic_arcsecond<tera      >;
    using petaarcsecond   = basic_arcsecond<peta      >;
    using exaarcsecond    = basic_arcsecond<exa       >;
    using zettaarcsecond  = basic_arcsecond<zetta     >;
    using yottaarcsecond  = basic_arcsecond<yotta     >;
    using ronnaarcsecond  = basic_arcsecond<ronna     >;
    using quettaarcsecond = basic_arcsecond<quetta    >;

    template <prefix_c Prefix>
    struct basic_gradian
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data angle{ 1, Prefix::factor * pi/200.0L, Prefix::symbol + "gon"_us };
    };

    using quectogradian = basic_gradian<quecto    >;
    using rontogradian  = basic_gradian<ronto     >;
    using yoctogradian  = basic_gradian<yocto     >;
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


#endif //__ZOLLSTOCK_ANGLE_UNIT_TYPES_HPP__
