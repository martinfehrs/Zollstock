#ifndef __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/si_prefixes.hpp>
#include <zollstock/math_constants.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock::inline units::inline constants
{

    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(quantities::theta, rad )
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(quantities::theta, gon )
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(quantities::theta, asec)

    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(quantities::theta, deg , pi/180.0L )
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(quantities::theta, amin, pi/10.8e3L)

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
