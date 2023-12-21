#ifndef __ZOLLSTOCK_UNIT_EXPONENTS_HPP__
#define __ZOLLSTOCK_UNIT_EXPONENTS_HPP__


#include "unit_data_concept.hpp"


namespace zollstock
{

    struct unit_exponents
    {
        int length;
        int time;

        int angle;
    };

    template <std::size_t... indices>
    [[nodiscard]] constexpr unit_exponents add(
        const unit_exponents& exponents_1,
        const unit_exponents& exponents_2,
        std::index_sequence<indices...>
    ) noexcept
    {
        return { (get<indices>(exponents_1) + get<indices>(exponents_2))... };
    }

    [[nodiscard]] constexpr auto operator+(
        const unit_exponents& exponents_1,
        const unit_exponents& exponents_2
    ) noexcept
    {
        return add(exponents_1, exponents_2, make_dimension_index_sequence{});
    }

    template <std::size_t... indices>
    [[nodiscard]] constexpr unit_exponents sub(
        const unit_exponents& exponents_1,
        const unit_exponents& exponents_2,
        std::index_sequence<indices...>
    ) noexcept
    {
        return { (get<indices>(exponents_1) - get<indices>(exponents_2))... };
    }

    [[nodiscard]] constexpr auto operator-(
        const unit_exponents& exponents_1,
        const unit_exponents& exponents_2
    ) noexcept
    {
        return sub(exponents_1, exponents_2, make_dimension_index_sequence{});
    }

}


#endif //__ZOLLSTOCK_UNIT_EXPONENTS_HPP__
