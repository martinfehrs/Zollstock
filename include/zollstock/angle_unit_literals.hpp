#ifndef __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__


#include <zollstock/angle_unit_types.hpp>
#include <zollstock/definition_helpers.hpp>
#include <zollstock/scalar.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_SI_LITERALS(,radian, rad)

            ZOLLSTOCK_DEFINE_LITERAL(degree        , deg   )
            ZOLLSTOCK_DEFINE_LITERAL(arcminute     , arcmin)
            ZOLLSTOCK_DEFINE_LITERAL(arcsecond     , arcsec)
            ZOLLSTOCK_DEFINE_LITERAL(milliarcsecond, mas   )
            ZOLLSTOCK_DEFINE_LITERAL(microarcsecond, micas )

        }

    }

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
