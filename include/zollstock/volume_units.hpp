#ifndef __ZOLLSTOCK_VOLUME_UNITS_HPP__
#define __ZOLLSTOCK_VOLUME_UNITS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/scalar.hpp>
#include <zollstock/length_units.hpp>
#include <zollstock/area_units.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using cubic_quektometer = unit_product<square_quektometer, quektometer>;
            using cubic_rontometer  = unit_product<square_rontometer , rontometer >;
            using cubic_yoktometer  = unit_product<square_yoktometer , yoktometer >;
            using cubic_zeptometer  = unit_product<square_zeptometer , zeptometer >;
            using cubic_attometer   = unit_product<square_attometer  , attometer  >;
            using cubic_femtometer  = unit_product<square_femtometer , femtometer >;
            using cubic_picometer   = unit_product<square_picometer  , picometer  >;
            using cubic_nanometer   = unit_product<square_nanometer  , nanometer  >;
            using cubic_micrometer  = unit_product<square_micrometer , micrometer >;
            using cubic_millimeter  = unit_product<square_millimeter , millimeter >;
            using cubic_centimeter  = unit_product<square_centimeter , centimeter >;
            using cubic_decimeter   = unit_product<square_decimeter  , decimeter  >;
            using cubic_meter       = unit_product<square_meter      , meter      >;
            using cubic_decameter   = unit_product<square_decameter  , decameter  >;
            using cubic_hectometer  = unit_product<square_hectometer , hectometer >;
            using cubic_kilometer   = unit_product<square_kilometer  , kilometer  >;
            using cubic_megameter   = unit_product<square_megameter  , megameter  >;
            using cubic_gigameter   = unit_product<square_gigameter  , gigameter  >;
            using cubic_terameter   = unit_product<square_terameter  , terameter  >;
            using cubic_petameter   = unit_product<square_petameter  , petameter  >;
            using cubic_exameter    = unit_product<square_exameter   , exameter   >;
            using cubic_zettameter  = unit_product<square_zettameter , zettameter >;
            using cubic_yottameter  = unit_product<square_yottameter , yottameter >;
            using cubic_ronnameter  = unit_product<square_ronnameter , ronnameter >;
            using cubic_quettameter = unit_product<square_quettameter, quettameter>;

        }

        inline namespace constants
        {

            inline constexpr cubic_quektometer qm3  {};
            inline constexpr cubic_rontometer  rm3  {};
            inline constexpr cubic_yoktometer  ym3  {};
            inline constexpr cubic_zeptometer  zm3  {};
            inline constexpr cubic_attometer   am3  {};
            inline constexpr cubic_femtometer  fm3  {};
            inline constexpr cubic_picometer   pm3  {};
            inline constexpr cubic_nanometer   nm3  {};
            inline constexpr cubic_micrometer  micm3{};
            inline constexpr cubic_millimeter  mm3  {};
            inline constexpr cubic_centimeter  cm3  {};
            inline constexpr cubic_decimeter   dm3  {};
            inline constexpr cubic_meter       m3   {};
            inline constexpr cubic_decameter   dam3 {};
            inline constexpr cubic_hectometer  hm3  {};
            inline constexpr cubic_kilometer   km3  {};
            inline constexpr cubic_megameter   Mm3  {};
            inline constexpr cubic_gigameter   Gm3  {};
            inline constexpr cubic_terameter   Tm3  {};
            inline constexpr cubic_petameter   Pm3  {};
            inline constexpr cubic_exameter    Em3  {};
            inline constexpr cubic_zettameter  Zm3  {};
            inline constexpr cubic_yottameter  Ym3  {};
            inline constexpr cubic_ronnameter  Rm3  {};
            inline constexpr cubic_quettameter Qm3  {};

        }

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_LITERAL(cubic_quektometer, qm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_rontometer , rm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_yoktometer , ym3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_zeptometer , zm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_attometer  , am3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_femtometer , fm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_picometer  , pm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_nanometer  , nm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_micrometer , micm3)
            ZOLLSTOCK_DEFINE_LITERAL(cubic_millimeter , mm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_centimeter , cm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_decimeter  , dm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_meter      , m3   )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_decameter  , dam3 )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_hectometer , hm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_kilometer  , km3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_megameter  , Mm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_gigameter  , Gm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_terameter  , Tm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_petameter  , Pm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_exameter   , Em3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_zettameter , Zm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_yottameter , Ym3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_ronnameter , Rm3  )
            ZOLLSTOCK_DEFINE_LITERAL(cubic_quettameter, Qm3  )

        }

    }

}


#endif //__ZOLLSTOCK_VOLUME_UNITS_HPP__
