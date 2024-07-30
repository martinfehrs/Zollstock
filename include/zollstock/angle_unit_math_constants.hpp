#ifndef __ZOLLSTOCK_ANGLE_UNIT_MATH_CONSTANTS_HPP__
#define __ZOLLSTOCK_ANGLE_UNIT_MATH_CONSTANTS_HPP__


#include <zollstock/math_constants.hpp>
#include <zollstock/scalar.hpp>


namespace zollstock::inline math_constants
{

    inline constexpr scalar<units::rad, float      > pi_f_rad{ pi_f };
    inline constexpr scalar<units::rad, double     > pi_rad  { pi   };
    inline constexpr scalar<units::rad, long double> pi_l_rad{ pi_l };

}


#endif //__ZOLLSTOCK_ANGLE_UNIT_MATH_CONSTANTS_HPP__
