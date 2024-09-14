#ifndef __ZOLLSTOCK_QUANTITY_CONSTANTS_HPP__
#define __ZOLLSTOCK_QUANTITY_CONSTANTS_HPP__


#include <zollstock/quantity.hpp>

#include <numbers>


namespace zollstock::inline quantity_constants
{

    template <number_c Number>
    constexpr quantity<units::rad, Number> pi_v{ std::numbers::pi_v<Number> };

    inline constexpr quantity<units::rad, float      > pi_f_rad{ pi_v<float      > };
    inline constexpr quantity<units::rad, double     > pi_rad  { pi_v<double     > };
    inline constexpr quantity<units::rad, long double> pi_l_rad{ pi_v<long double> };

}


#endif //__ZOLLSTOCK_QUANTITY_CONSTANTS_HPP__
