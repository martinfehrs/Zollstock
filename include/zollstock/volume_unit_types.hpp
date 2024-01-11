#ifndef __ZOLLSTOCK_VOLUME_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_VOLUME_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/length_unit_types.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            using cubic_quektometer = unit_exponentiation<quektometer, 3>;
            using cubic_rontometer  = unit_exponentiation<rontometer , 3>;
            using cubic_yoktometer  = unit_exponentiation<yoktometer , 3>;
            using cubic_zeptometer  = unit_exponentiation<zeptometer , 3>;
            using cubic_attometer   = unit_exponentiation<attometer  , 3>;
            using cubic_femtometer  = unit_exponentiation<femtometer , 3>;
            using cubic_picometer   = unit_exponentiation<picometer  , 3>;
            using cubic_nanometer   = unit_exponentiation<nanometer  , 3>;
            using cubic_micrometer  = unit_exponentiation<micrometer , 3>;
            using cubic_millimeter  = unit_exponentiation<millimeter , 3>;
            using cubic_centimeter  = unit_exponentiation<centimeter , 3>;
            using cubic_decimeter   = unit_exponentiation<decimeter  , 3>;
            using cubic_meter       = unit_exponentiation<meter      , 3>;
            using cubic_decameter   = unit_exponentiation<decameter  , 3>;
            using cubic_hectometer  = unit_exponentiation<hectometer , 3>;
            using cubic_kilometer   = unit_exponentiation<kilometer  , 3>;
            using cubic_megameter   = unit_exponentiation<megameter  , 3>;
            using cubic_gigameter   = unit_exponentiation<gigameter  , 3>;
            using cubic_terameter   = unit_exponentiation<terameter  , 3>;
            using cubic_petameter   = unit_exponentiation<petameter  , 3>;
            using cubic_exameter    = unit_exponentiation<exameter   , 3>;
            using cubic_zettameter  = unit_exponentiation<zettameter , 3>;
            using cubic_yottameter  = unit_exponentiation<yottameter , 3>;
            using cubic_ronnameter  = unit_exponentiation<ronnameter , 3>;
            using cubic_quettameter = unit_exponentiation<quettameter, 3>;

        }

    }

}


#endif //__ZOLLSTOCK_VOLUME_UNIT_TYPES_HPP__
