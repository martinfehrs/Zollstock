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

            using square_quektometer = unit_exponentiation<quektometer, 2>;
            using square_rontometer  = unit_exponentiation<rontometer , 2>;
            using square_yoktometer  = unit_exponentiation<yoktometer , 2>;
            using square_zeptometer  = unit_exponentiation<zeptometer , 2>;
            using square_attometer   = unit_exponentiation<attometer  , 2>;
            using square_femtometer  = unit_exponentiation<femtometer , 2>;
            using square_picometer   = unit_exponentiation<picometer  , 2>;
            using square_nanometer   = unit_exponentiation<nanometer  , 2>;
            using square_micrometer  = unit_exponentiation<micrometer , 2>;
            using square_millimeter  = unit_exponentiation<millimeter , 2>;
            using square_centimeter  = unit_exponentiation<centimeter , 2>;
            using square_decimeter   = unit_exponentiation<decimeter  , 2>;
            using square_meter       = unit_exponentiation<meter      , 2>;
            using square_decameter   = unit_exponentiation<decameter  , 2>;
            using square_hectometer  = unit_exponentiation<hectometer , 2>;
            using square_kilometer   = unit_exponentiation<kilometer  , 2>;
            using square_megameter   = unit_exponentiation<megameter  , 2>;
            using square_gigameter   = unit_exponentiation<gigameter  , 2>;
            using square_terameter   = unit_exponentiation<terameter  , 2>;
            using square_petameter   = unit_exponentiation<petameter  , 2>;
            using square_exameter    = unit_exponentiation<exameter   , 2>;
            using square_zettameter  = unit_exponentiation<zettameter , 2>;
            using square_yottameter  = unit_exponentiation<yottameter , 2>;
            using square_ronnameter  = unit_exponentiation<ronnameter , 2>;
            using square_quettameter = unit_exponentiation<quettameter, 2>;

        }

    }

}


#endif //__ZOLLSTOCK_AREA_UNIT_TYPES_HPP__
