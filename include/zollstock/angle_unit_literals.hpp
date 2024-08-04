#ifndef __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__


#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>
#include <zollstock/scalar.hpp>

#include <limits>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(rad)

    ZOLLSTOCK_DEFINE_LITERAL(deg, deg)

    ZOLLSTOCK_DEFINE_LITERAL(amin, amin)

    ZOLLSTOCK_DEFINE_SI_LITERALS(asec)

    ZOLLSTOCK_DEFINE_SI_LITERALS(gon)

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
