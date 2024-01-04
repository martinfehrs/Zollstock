#ifndef __ZOLLSTOCK_AREA_UNITS_HPP__
#define __ZOLLSTOCK_AREA_UNITS_HPP__


#include <zollstock/length_units.hpp>
#include <zollstock/scalar.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using square_quektometer = unit_product<quektometer, quektometer>;
            using square_rontometer  = unit_product<rontometer , rontometer >;
            using square_yoktometer  = unit_product<yoktometer , yoktometer >;
            using square_zeptometer  = unit_product<zeptometer , zeptometer >;
            using square_attometer   = unit_product<attometer  , attometer  >;
            using square_femtometer  = unit_product<femtometer , femtometer >;
            using square_picometer   = unit_product<picometer  , picometer  >;
            using square_nanometer   = unit_product<nanometer  , nanometer  >;
            using square_micrometer  = unit_product<micrometer , micrometer >;
            using square_millimeter  = unit_product<millimeter , millimeter >;
            using square_centimeter  = unit_product<centimeter , centimeter >;
            using square_decimeter   = unit_product<decimeter  , decimeter  >;
            using square_meter       = unit_product<meter      , meter      >;
            using square_decameter   = unit_product<decameter  , decameter  >;
            using square_hectometer  = unit_product<hectometer , hectometer >;
            using square_kilometer   = unit_product<kilometer  , kilometer  >;
            using square_megameter   = unit_product<megameter  , megameter  >;
            using square_gigameter   = unit_product<gigameter  , gigameter  >;
            using square_terameter   = unit_product<terameter  , terameter  >;
            using square_petameter   = unit_product<petameter  , petameter  >;
            using square_exameter    = unit_product<exameter   , exameter   >;
            using square_zettameter  = unit_product<zettameter , zettameter >;
            using square_yottameter  = unit_product<yottameter , yottameter >;
            using square_ronnameter  = unit_product<ronnameter , ronnameter >;
            using square_quettameter = unit_product<quettameter, quettameter>;

        }

        inline namespace constants
        {

            inline constexpr square_quektometer qm2  {};
            inline constexpr square_rontometer  rm2  {};
            inline constexpr square_yoktometer  ym2  {};
            inline constexpr square_zeptometer  zm2  {};
            inline constexpr square_attometer   am2  {};
            inline constexpr square_femtometer  fm2  {};
            inline constexpr square_picometer   pm2  {};
            inline constexpr square_nanometer   nm2  {};
            inline constexpr square_micrometer  micm2{};
            inline constexpr square_millimeter  mm2  {};
            inline constexpr square_centimeter  cm2  {};
            inline constexpr square_decimeter   dm2  {};
            inline constexpr square_meter       m2   {};
            inline constexpr square_decameter   dam2 {};
            inline constexpr square_hectometer  hm2  {};
            inline constexpr square_kilometer   km2  {};
            inline constexpr square_megameter   Mm2  {};
            inline constexpr square_gigameter   Gm2  {};
            inline constexpr square_terameter   Tm2  {};
            inline constexpr square_petameter   Pm2  {};
            inline constexpr square_exameter    Em2  {};
            inline constexpr square_zettameter  Zm2  {};
            inline constexpr square_yottameter  Ym2  {};
            inline constexpr square_ronnameter  Rm2  {};
            inline constexpr square_quettameter Qm2  {};

        }

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_LITERAL(square_quektometer, qm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_rontometer , rm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_yoktometer , ym2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_zeptometer , zm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_attometer  , am2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_femtometer , fm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_picometer  , pm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_nanometer  , nm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_micrometer , micm2)
            ZOLLSTOCK_DEFINE_LITERAL(square_millimeter , mm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_centimeter , cm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_decimeter  , dm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_meter      , m2   )
            ZOLLSTOCK_DEFINE_LITERAL(square_decameter  , dam2 )
            ZOLLSTOCK_DEFINE_LITERAL(square_hectometer , hm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_kilometer  , km2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_megameter  , Mm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_gigameter  , Gm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_terameter  , Tm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_petameter  , Pm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_exameter   , Em2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_zettameter , Zm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_yottameter , Ym2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_ronnameter , Rm2  )
            ZOLLSTOCK_DEFINE_LITERAL(square_quettameter, Qm2  )

        }

    }

}


#endif //__ZOLLSTOCK_AREA_UNITS_HPP__
