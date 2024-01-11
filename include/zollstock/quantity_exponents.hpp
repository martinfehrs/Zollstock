#ifndef __ZOLLSTOCK_QUANTITY_EXPONENTS_HPP__
#define __ZOLLSTOCK_QUANTITY_EXPONENTS_HPP__


#include <zollstock/quantity_data_concept.hpp>


namespace zollstock
{

    struct quantity_exponents
    {
        int length;
        int time;

        int angle;
    };

    template <std::size_t... indices>
    [[nodiscard]] constexpr quantity_exponents add(
        const quantity_exponents& exponents_1,
        const quantity_exponents& exponents_2,
        std::index_sequence<indices...>
    ) noexcept
    {
        return { (get<indices>(exponents_1) + get<indices>(exponents_2))... };
    }

    [[nodiscard]] constexpr auto operator+(
        const quantity_exponents& exponents_1,
        const quantity_exponents& exponents_2
    ) noexcept
    {
        return add(exponents_1, exponents_2, make_quantity_index_sequence{});
    }

    template <std::size_t... indices>
    [[nodiscard]] constexpr quantity_exponents sub(
        const quantity_exponents& exponents_1,
        const quantity_exponents& exponents_2,
        std::index_sequence<indices...>
    ) noexcept
    {
        return { (get<indices>(exponents_1) - get<indices>(exponents_2))... };
    }

    [[nodiscard]] constexpr auto operator-(
        const quantity_exponents& exponents_1,
        const quantity_exponents& exponents_2
    ) noexcept
    {
        return sub(exponents_1, exponents_2, make_quantity_index_sequence{});
    }

    template <std::size_t... indices>
    [[nodiscard]] constexpr quantity_exponents mul(
        const quantity_exponents& exponents,
        int factor,
        std::index_sequence<indices...>
    ) noexcept
    {
        return { (get<indices>(exponents) * factor)... };
    }

    [[nodiscard]] constexpr auto operator*(
        const quantity_exponents& exponents,
        int factor
    ) noexcept
    {
        return mul(exponents, factor, make_quantity_index_sequence{});
    }
}


#endif //__ZOLLSTOCK_QUANTITY_EXPONENTS_HPP__
