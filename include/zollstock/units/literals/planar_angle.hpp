#ifndef __ZOLLSTOCK_UNITS_LITERALS_PLANAR_ANGLE_HPP__
#define __ZOLLSTOCK_UNITS_LITERALS_PLANAR_ANGLE_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#include <zollstock/units/constants/planar_angle.hpp>
#include <zollstock/units/literals/definition_helpers.hpp>
#endif //ZOLLSTOCK_USE_MODULES


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(rad)

    ZOLLSTOCK_DEFINE_LITERALS(deg, deg)

    ZOLLSTOCK_DEFINE_LITERALS(amin, amin)

    ZOLLSTOCK_DEFINE_SI_LITERALS(asec)

    ZOLLSTOCK_DEFINE_SI_LITERALS(gon)

}


#endif //__ZOLLSTOCK_UNITS_LITERALS_PLANAR_ANGLE_HPP__
