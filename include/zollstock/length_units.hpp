#ifndef __ZOLLSTOCK_LENGTH_UNITS_HPP__
#define __ZOLLSTOCK_LENGTH_UNITS_HPP__


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
            struct basic_meter
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 1, 0, 0 };
                static constexpr quantity_factors factors{ Prefix::factor, 0.0L, 0.0L };
                static constexpr quantity_symbols symbols{ Prefix::symbol + "m"_us, ""_us, ""_us };
            };

            using quektometer = basic_meter<quekto    >;
            using rontometer  = basic_meter<ronto     >;
            using yoktometer  = basic_meter<yokto     >;
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

        inline namespace constants
        {

            inline constexpr quektometer qm   {};
            inline constexpr rontometer  rm   {};
            inline constexpr yoktometer  ym   {};
            inline constexpr zeptometer  zm   {};
            inline constexpr attometer   am   {};
            inline constexpr femtometer  fm   {};
            inline constexpr picometer   pm   {};
            inline constexpr nanometer   nm   {};
            inline constexpr micrometer  micm {};
            inline constexpr millimeter  mm   {};
            inline constexpr centimeter  cm   {};
            inline constexpr decimeter   dm   {};
            inline constexpr meter       m    {};
            inline constexpr decameter   dam  {};
            inline constexpr hectometer  hm   {};
            inline constexpr kilometer   km   {};
            inline constexpr megameter   Mm   {};
            inline constexpr gigameter   Gm   {};
            inline constexpr terameter   Tm   {};
            inline constexpr petameter   Pm   {};
            inline constexpr exameter    Em   {};
            inline constexpr zettameter  Zm   {};
            inline constexpr yottameter  Ym   {};
            inline constexpr ronnameter  Rm   {};
            inline constexpr quettameter Qm   {};

        }

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_LITERAL(quektometer, qm  )
            ZOLLSTOCK_DEFINE_LITERAL(rontometer , rm  )
            ZOLLSTOCK_DEFINE_LITERAL(yoktometer , ym  )
            ZOLLSTOCK_DEFINE_LITERAL(zeptometer , zm  )
            ZOLLSTOCK_DEFINE_LITERAL(attometer  , am  )
            ZOLLSTOCK_DEFINE_LITERAL(femtometer , fm  )
            ZOLLSTOCK_DEFINE_LITERAL(picometer  , pm  )
            ZOLLSTOCK_DEFINE_LITERAL(nanometer  , nm  )
            ZOLLSTOCK_DEFINE_LITERAL(micrometer , micm)
            ZOLLSTOCK_DEFINE_LITERAL(millimeter , mm  )
            ZOLLSTOCK_DEFINE_LITERAL(centimeter , cm  )
            ZOLLSTOCK_DEFINE_LITERAL(decimeter  , dm  )
            ZOLLSTOCK_DEFINE_LITERAL(meter      , m   )
            ZOLLSTOCK_DEFINE_LITERAL(decameter  , dam )
            ZOLLSTOCK_DEFINE_LITERAL(hectometer , hm  )
            ZOLLSTOCK_DEFINE_LITERAL(kilometer  , km  )
            ZOLLSTOCK_DEFINE_LITERAL(megameter  , Mm  )
            ZOLLSTOCK_DEFINE_LITERAL(gigameter  , Gm  )
            ZOLLSTOCK_DEFINE_LITERAL(terameter  , Tm  )
            ZOLLSTOCK_DEFINE_LITERAL(petameter  , Pm  )
            ZOLLSTOCK_DEFINE_LITERAL(exameter   , Em  )
            ZOLLSTOCK_DEFINE_LITERAL(zettameter , Zm  )
            ZOLLSTOCK_DEFINE_LITERAL(yottameter , Ym  )
            ZOLLSTOCK_DEFINE_LITERAL(ronnameter , Rm  )
            ZOLLSTOCK_DEFINE_LITERAL(quettameter, Qm  )

        }

    }

}


#endif //__ZOLLSTOCK_LENGTH_UNITS_HPP__
