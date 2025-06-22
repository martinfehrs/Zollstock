#ifndef __ZOLLSTOCK_QUANTITIES_MATH_HPP__
#define __ZOLLSTOCK_QUANTITIES_MATH_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>
#  include <zollstock/dimensions.hpp>
#  include <zollstock/numbers.hpp>
#  include <zollstock/quantities/constants.hpp>
#  include <zollstock/quantities/concepts.hpp>
#  include <zollstock/quantities/template.hpp>
#  include <zollstock/units/constants/planar_angle.hpp>
#  include <zollstock/units/constants/one.hpp>

#  include <cmath>
#  include <version>
#endif


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

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto sin(quantity<units::rad, Number> angle)
    {
        return as<units::_1>(std::sin(angle.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto cos(quantity<units::rad, Number> angle)
    {
        return as<units::_1>(std::cos(angle.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto tan(quantity<units::rad, Number> angle)
    {
        return as<units::_1>(std::tan(angle.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto asin(quantity<units::_1, Number> num)
    {
        return as<units::rad>(std::asin(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto acos(quantity<units::_1, Number> num)
    {
        return as<units::rad>(std::acos(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT template <number_c Number>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto atan(quantity<units::_1, Number> num)
    {
        return as<units::rad>(std::atan(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT template <of_dimension_c<dimensions::L> Length>
    [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_26 auto atan2(Length x, Length y)
    {
        return as<units::rad>(std::atan2(x.value(), y.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 bool signbit(
        quantity_c auto num
    )
    {
        return std::signbit(num.value());
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 auto abs(quantity_c auto num)
    {
        return as<num.unit()>(std::abs(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 auto ceil(quantity_c auto num)
    {
        return as<num.unit()>(std::ceil(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 auto floor(
        quantity_c auto num
    )
    {
        return as<num.unit()>(std::floor(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 auto trunc(
        quantity_c auto num
    )
    {
        return as<num.unit()>(std::trunc(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 auto round(
        quantity_c auto num
    )
    {
        return as<num.unit()>(std::round(num.value()));
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] ZOLLSTOCK_CONSTEXPR_MATH_23 auto rint(quantity_c auto num)
    {
        return as<num.unit()>(std::rint(num.value()));
    }

}


#endif //__ZOLLSTOCK_QUANTITIES_MATH_HPP__
