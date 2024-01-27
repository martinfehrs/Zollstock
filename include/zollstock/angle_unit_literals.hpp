#ifndef __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__


#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/definition_helpers.hpp>
#include <zollstock/quantity.hpp>


namespace zollstock::inline unit::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(rad)

    ZOLLSTOCK_DEFINE_LITERAL(deg, deg)

    ZOLLSTOCK_DEFINE_LITERAL(arcmin, arcmin)

    ZOLLSTOCK_DEFINE_LITERAL(arcsec, arcsec)
    ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(as)

    ZOLLSTOCK_DEFINE_SI_LITERALS(gon)

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
