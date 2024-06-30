#ifndef __ZOLLSTOCK_QUANTITY_CONCEPT_HPP__
#define __ZOLLSTOCK_QUANTITY_CONCEPT_HPP__


#include <zollstock/static_string.hpp>

#include <cstddef>
#include <concepts>
#include <type_traits>


namespace zollstock
{

    struct quantity_tag {};

    template <typename Candidate>
    concept quantity_c = requires
    {
        requires std::is_trivial_v<Candidate>;
        requires std::is_empty_v<Candidate>;

        { Candidate::tag    } -> std::same_as<const quantity_tag&>;
        { Candidate::symbol } -> std::same_as<const static_string&>;
    };



    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator==(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return quantity_1.symbol == quantity_2.symbol;
    }

    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator!=(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return quantity_1.symbol != quantity_2.symbol;
    }

    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator<(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return quantity_1.symbol < quantity_2.symbol;
    }

    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator>(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return quantity_1.symbol > quantity_2.symbol;
    }

    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator<=(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return quantity_1.symbol <= quantity_2.symbol;
    }

    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator>=(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return quantity_1.symbol >= quantity_2.symbol;
    }



    template <static_string symbol_>
    struct quantity_t
    {
        static constexpr quantity_tag tag{};
        static constexpr static_string symbol = symbol_;
    };

}


#endif //__ZOLLSTOCK_QUANTITY_CONCEPT_HPP__
