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

            using cubic_quektometer = raise_unit_v<quektometer, 3>;
            using cubic_rontometer  = raise_unit_v<rontometer , 3>;
            using cubic_yoktometer  = raise_unit_v<yoktometer , 3>;
            using cubic_zeptometer  = raise_unit_v<zeptometer , 3>;
            using cubic_attometer   = raise_unit_v<attometer  , 3>;
            using cubic_femtometer  = raise_unit_v<femtometer , 3>;
            using cubic_picometer   = raise_unit_v<picometer  , 3>;
            using cubic_nanometer   = raise_unit_v<nanometer  , 3>;
            using cubic_micrometer  = raise_unit_v<micrometer , 3>;
            using cubic_millimeter  = raise_unit_v<millimeter , 3>;
            using cubic_centimeter  = raise_unit_v<centimeter , 3>;
            using cubic_decimeter   = raise_unit_v<decimeter  , 3>;
            using cubic_meter       = raise_unit_v<meter      , 3>;
            using cubic_decameter   = raise_unit_v<decameter  , 3>;
            using cubic_hectometer  = raise_unit_v<hectometer , 3>;
            using cubic_kilometer   = raise_unit_v<kilometer  , 3>;
            using cubic_megameter   = raise_unit_v<megameter  , 3>;
            using cubic_gigameter   = raise_unit_v<gigameter  , 3>;
            using cubic_terameter   = raise_unit_v<terameter  , 3>;
            using cubic_petameter   = raise_unit_v<petameter  , 3>;
            using cubic_exameter    = raise_unit_v<exameter   , 3>;
            using cubic_zettameter  = raise_unit_v<zettameter , 3>;
            using cubic_yottameter  = raise_unit_v<yottameter , 3>;
            using cubic_ronnameter  = raise_unit_v<ronnameter , 3>;
            using cubic_quettameter = raise_unit_v<quettameter, 3>;

        }

    }

}


#endif //__ZOLLSTOCK_VOLUME_UNIT_TYPES_HPP__
