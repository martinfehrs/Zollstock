#ifndef __ZOLLSTOCK_QUANTITIES_CONSTANTS_HPP__
#define __ZOLLSTOCK_QUANTITIES_CONSTANTS_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>
#  include <zollstock/numbers.hpp>
#  include <zollstock/quantities/template.hpp>
#  include <zollstock/units/constants/planar_angle.hpp>

#  include <numbers>
#endif


namespace zollstock::inline quantities::inline constants
{

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    constexpr quantity<units::_1, Number> pi_v{ std::numbers::pi_v<Number> };

    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_f = pi_v<float      >;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi   = pi_v<double     >;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_l = pi_v<long double>;

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    constexpr quantity<units::_1, Number> pi_1_v{ std::numbers::pi_v<Number> };

    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_f_1 = pi_1_v<float      >;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_1   = pi_1_v<double     >;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_l_1 = pi_1_v<long double>;


    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    constexpr quantity<units::rad, Number> pi_rad_v{ std::numbers::pi_v<Number> };

    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_f_rad = pi_rad_v<float      >;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_rad   = pi_rad_v<double     >;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr auto pi_l_rad = pi_rad_v<long double>;

}


#endif //__ZOLLSTOCK_QUANTITIES_CONSTANTS_HPP__
