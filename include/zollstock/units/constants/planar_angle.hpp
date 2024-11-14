#ifndef __ZOLLSTOCK_UNITS_CONSTANTS_PLANAR_ANGLE_HPP__
#define __ZOLLSTOCK_UNITS_CONSTANTS_PLANAR_ANGLE_HPP__


#include <zollstock/units/constants/definition_helpers.hpp>

#include <numbers>


namespace zollstock::units::inline constants
{

    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(_1, rad )
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(_1, gon )
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(_1, asec)

    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(_1, deg , std::numbers::pi/180.0L )
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(_1, amin, std::numbers::pi/10.8e3L)

}


#endif //__ZOLLSTOCK_UNITS_CONSTANTS_PLANAR_ANGLE_HPP__
