#ifndef __ZOLLSTOCK_AREA_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_AREA_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/length_unit_types.hpp>


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

    }

}


#endif //__ZOLLSTOCK_AREA_UNIT_TYPES_HPP__
