#ifndef __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__


#include <zollstock/angle_unit_types.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock::inline units::inline constants
{

    ZOLLSTOCK_DEFINE_SI_BASE_UNIT_CONSTANTS(radian, rad)

    inline constexpr degree deg{};

    inline constexpr arcminute amin{};

    ZOLLSTOCK_DEFINE_SI_BASE_UNIT_CONSTANTS(arcsecond, asec)

    ZOLLSTOCK_DEFINE_SI_BASE_UNIT_CONSTANTS(gradian, gon)

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_CONSTANTS_HPP__
