#ifndef __ZOLLSTOCK_TRIGONOMETRIC_FUNCTIONS_HPP__
#define __ZOLLSTOCK_TRIGONOMETRIC_FUNCTIONS_HPP__


#include <zollstock/angle_units.hpp>
#include <zollstock/angle_unit_math_constants.hpp>
#include <zollstock/unit_one.hpp>

#include <cmath>


namespace zollstock
{

    template <number_c Number>
    auto sin(scalar<units::rad, Number> angle)
    {
        return scalar<units::_1, Number>{ std::sin(angle.value()) };
    }

    template <number_c Number>
    auto cos(scalar<units::rad, Number> angle)
    {
        return scalar<units::_1, Number>{ std::cos(angle.value()) };
    }

    template <number_c Number>
    auto tan(scalar<units::rad, Number> angle)
    {
        return scalar<units::_1, Number>{ std::tan(angle.value()) };
    }

    template <number_c Number>
    auto asin(scalar<units::_1, Number> num)
    {
        return scalar<units::rad, Number>{ std::asin(num.value()) };
    }

    template <number_c Number>
    auto acos(scalar<units::_1, Number> num)
    {
        return scalar<units::rad, Number>{ std::acos(num.value()) };
    }

    template <number_c Number>
    auto atan(scalar<units::_1, Number> num)
    {
        return scalar<units::rad, Number>{ std::atan(num.value()) };
    }

}


#endif //__ZOLLSTOCK_TRIGONOMETRIC_FUNCTIONS_HPP__
