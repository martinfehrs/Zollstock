#ifndef __ZOLLSTOCK_VOLUME_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_VOLUME_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/length_unit_types.hpp>
#include <zollstock/area_unit_types.hpp>


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

    }

}


#endif //__ZOLLSTOCK_VOLUME_UNIT_TYPES_HPP__
