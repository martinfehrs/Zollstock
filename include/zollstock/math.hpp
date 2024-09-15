#ifndef __ZOLLSTOCK_MATH_HPP__
#define __ZOLLSTOCK_MATH_HPP__


#include <zollstock/angle_units.hpp>
#include <zollstock/numbers.hpp>
#include <zollstock/unit_one.hpp>

#include <cmath>


namespace zollstock
{

    template <number_c Number>
    [[nodiscard]] auto sin(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::sin(angle.value()) };
    }

    template <number_c Number>
    [[nodiscard]] auto cos(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::cos(angle.value()) };
    }

    template <number_c Number>
    [[nodiscard]] auto tan(quantity<units::rad, Number> angle)
    {
        return quantity<units::_1, Number>{ std::tan(angle.value()) };
    }

    template <number_c Number>
    [[nodiscard]] auto asin(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::asin(num.value()) };
    }

    template <number_c Number>
    [[nodiscard]] auto acos(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::acos(num.value()) };
    }

    template <number_c Number>
    [[nodiscard]] auto atan(quantity<units::_1, Number> num)
    {
        return quantity<units::rad, Number>{ std::atan(num.value()) };
    }

    template <number_c Number, unit_c auto unit>
    [[nodiscard]] bool signbit(quantity<unit, Number> num)
    {
        return std::signbit(num.value());
    }

}


#endif //__ZOLLSTOCK_MATH_HPP__
