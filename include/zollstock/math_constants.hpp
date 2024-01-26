#ifndef __ZOLLSTOCK_MATH_CONSTANTS_HPP__
#define __ZOLLSTOCK_MATH_CONSTANTS_HPP__


#include <numbers>


namespace zollstock::inline math_constants
{

    inline constexpr float       pi_f  { std::numbers::pi_v<float      > };
    inline constexpr double      pi    { std::numbers::pi_v<double     > };
    inline constexpr long double pi_l  { std::numbers::pi_v<long double> };

}


#endif //__ZOLLSTOCK_MATH_CONSTANTS_HPP__
