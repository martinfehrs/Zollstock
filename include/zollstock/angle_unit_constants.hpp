#ifndef __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/si_prefixes.hpp>
#include <zollstock/math_constants.hpp>
#include <zollstock/constant_definition_helpers.hpp>


namespace zollstock::units::inline constants
{

    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(dimensions::_1, rad )
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(dimensions::_1, gon )
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(dimensions::_1, asec)

    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimensions::_1, deg , pi/180.0L )
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimensions::_1, amin, pi/10.8e3L)

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
