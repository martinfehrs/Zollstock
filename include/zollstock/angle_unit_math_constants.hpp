#ifndef __ZOLLSTOCK_ANGLE_UNIT_MATH_CONSTANTS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_MATH_CONSTANTS_HPP__


#include <zollstock/quantity.hpp>

#include <numbers>


namespace zollstock::inline math_constants
{

    inline constexpr quantity<units::rad, float      > pi_f_rad{ std::numbers::pi_v<float      > };
    inline constexpr quantity<units::rad, double     > pi_rad  { std::numbers::pi_v<double     > };
    inline constexpr quantity<units::rad, long double> pi_l_rad{ std::numbers::pi_v<long double> };

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_MATH_CONSTANTS_HPP__
