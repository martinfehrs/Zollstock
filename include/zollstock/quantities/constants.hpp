#ifndef __ZOLLSTOCK_QUANTITIES_CONSTANTS_HPP__
#define __ZOLLSTOCK_QUANTITIES_CONSTANTS_HPP__


#include <zollstock/quantities/template.hpp>
#include <zollstock/units/constants/planar_angle.hpp>

#include <numbers>


namespace zollstock::inline quantities::inline constants
{

    template <number_c Number>
    constexpr quantity<units::_1, Number> pi_v{ std::numbers::pi_v<Number> };

    inline constexpr quantity<units::_1, float      > pi_f{ pi_v<float      > };
    inline constexpr quantity<units::_1, double     > pi  { pi_v<double     > };
    inline constexpr quantity<units::_1, long double> pi_l{ pi_v<long double> };


    template <number_c Number>
    constexpr quantity<units::_1, Number> pi_1_v{ std::numbers::pi_v<Number> };

    inline constexpr quantity<units::_1, float      > pi_f_1{ pi_1_v<float      > };
    inline constexpr quantity<units::_1, double     > pi_1  { pi_1_v<double     > };
    inline constexpr quantity<units::_1, long double> pi_l_1{ pi_1_v<long double> };


    template <number_c Number>
    constexpr quantity<units::rad, Number> pi_rad_v{ std::numbers::pi_v<Number> };

    inline constexpr quantity<units::rad, float      > pi_f_rad{ pi_rad_v<float      > };
    inline constexpr quantity<units::rad, double     > pi_rad  { pi_rad_v<double     > };
    inline constexpr quantity<units::rad, long double> pi_l_rad{ pi_rad_v<long double> };

}


#endif //__ZOLLSTOCK_QUANTITIES_CONSTANTS_HPP__
