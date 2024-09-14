#ifndef __ZOLLSTOCK_TRIGONOMETRIC_FUNCTIONS_HPP__
#define __ZOLLSTOCK_TRIGONOMETRIC_FUNCTIONS_HPP__


#include <zollstock/angle_units.hpp>
#include <zollstock/angle_unit_math_constants.hpp>
#include <zollstock/unit_one.hpp>

#include <cmath>


namespace zollstock
{

    template <number_c Number>
    auto sin(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::sin(angle.value()) };
    }

    template <number_c Number>
    auto cos(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::cos(angle.value()) };
    }

    template <number_c Number>
    auto tan(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::tan(angle.value()) };
    }

    template <number_c Number>
    auto asin(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::asin(num.value()) };
    }

    template <number_c Number>
    auto acos(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::acos(num.value()) };
    }

    template <number_c Number>
    auto atan(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::atan(num.value()) };
    }

}


#endif //__ZOLLSTOCK_TRIGONOMETRIC_FUNCTIONS_HPP__
