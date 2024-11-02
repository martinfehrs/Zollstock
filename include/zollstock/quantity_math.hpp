#ifndef __ZOLLSTOCK_QUANTITY_MATH_HPP__
#define __ZOLLSTOCK_QUANTITY_MATH_HPP__


#include <zollstock/planar_angle_units.hpp>
#include <zollstock/quantity_constants.hpp>
#include <zollstock/length_concept.hpp>
#include <zollstock/unit_one.hpp>

#include <cmath>
#include <version>


#if __cpp_lib_constexpr_cmath >= 202202L
    #define ZOLLSTOCK_CONSTEXPR_MATH_23 constexpr
#else
    #define ZOLLSTOCK_CONSTEXPR_MATH_23
#endif

#if __cpp_lib_constexpr_cmath >= 202306L
    #define ZOLLSTOCK_CONSTEXPR_MATH_26 constexpr
#else
    #define ZOLLSTOCK_CONSTEXPR_MATH_26
#endif


namespace zollstock
{

    template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto sin(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::sin(angle.value()) };
    }

    template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto cos(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::cos(angle.value()) };
    }

    template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto tan(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::tan(angle.value()) };
    }

    template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto asin(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::asin(num.value()) };
    }

    template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto acos(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::acos(num.value()) };
    }

    template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto atan(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::atan(num.value()) };
    }

    template <length_c Length>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto atan2(Length x, Length y)
    {
        return quantity<units::rad, typename Length::value_type>{
            std::atan2(x.value(), y.value())
        };
    }

    template <number_c Number, unit_c auto unit>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 bool signbit(quantity<unit, Number> num)
    {
        return std::signbit(num.value());
    }

}


#endif //__ZOLLSTOCK_QUANTITY_MATH_HPP__
