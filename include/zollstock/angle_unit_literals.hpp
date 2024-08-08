#ifndef __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__


#include <zollstock/angle_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(rad)

    ZOLLSTOCK_DEFINE_LITERALS(deg, deg)

    ZOLLSTOCK_DEFINE_LITERALS(amin, amin)

    ZOLLSTOCK_DEFINE_SI_LITERALS(asec)

    ZOLLSTOCK_DEFINE_SI_LITERALS(gon)

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_LITERALS_HPP__
