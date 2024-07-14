#ifndef __ZOLLSTOCK_QUANTITY_CONCEPT_HPP__
#define __ZOLLSTOCK_QUANTITY_CONCEPT_HPP__


#include <zollstock/static_string.hpp>
#include <zollstock/tuple_utils.hpp>

#include <cstddef>
#include <concepts>
#include <type_traits>


namespace zollstock::quantities
{

    template <typename Candidate>
    concept quantity_factor_c = requires
    {
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        { Candidate::symbol         } -> std::same_as<const static_string&>;
        { Candidate::exponent       } -> std::same_as<const int&>;
    };

    template<class Candidate, std::size_t index>
    concept has_quantity_factor_tuple_element_c = requires (Candidate candidate)
    {
        requires quantity_factor_c<typename std::tuple_element<index, Candidate>::type>;
        { get<index>(candidate) } -> std::convertible_to<std::tuple_element_t<index, Candidate>&>;
    };

    template<class Candidate>
    concept is_quantity_factor_tuple_like_c = requires
    {
        requires []<std::size_t... indices>(std::index_sequence<indices...>)
        {
            return (has_quantity_factor_tuple_element_c<Candidate, indices> && ...);
        }
        (std::make_index_sequence<std::tuple_size_v<Candidate>>{});
    };

    struct quantity_tag;

    template <typename Candidate>
    concept quantity_c = requires
    {
        requires std::same_as<typename Candidate::type, quantity_tag>;
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        requires is_quantity_factor_tuple_like_c<std::remove_cvref_t<decltype(Candidate::factors)>>;
    };

    template <typename Candidate>
    concept base_quantity_c = quantity_c<Candidate> && Candidate::size == 1;

    template <typename Candidate>
    concept derived_quantity_c = quantity_c<Candidate> && Candidate::size != 1;



    template<static_string symbol_, int exponent_>
    struct quantity_factor
    {
        static constexpr auto symbol = symbol_;
        static constexpr auto exponent = exponent_;
    };



    template<quantity_factor_c... Factors>
    struct quantity_product
    {
        using type = quantity_tag;
        static constexpr auto factors = std::tuple{ Factors{}... };
        static constexpr std::size_t size = sizeof...(Factors);
    };

    template <quantity_factor_c... Factors>
    inline constexpr auto quantity_product_v = quantity_product<Factors...>{};

    template <quantity_factor_c FirstFactor, quantity_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto quantity_product_head(
        quantity_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return quantity_product_v<FirstFactor>;
    }

    template <quantity_factor_c FirstFactor, quantity_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto quantity_product_tail(
        quantity_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return quantity_product_v<RemainingFactors...>;
    }

    namespace detail
    {

        template <quantity_factor_c ... Factors1, quantity_factor_c... Factors2>
        [[nodiscard]] consteval auto quantity_product_concat(
            quantity_product<Factors1...>, quantity_product<Factors2...>
        ) noexcept
        {
            return quantity_product_v<Factors1..., Factors2...>;
        }

    }

    inline constexpr quantity_product<> _1{};



    template <static_string symbol, int exponent = 1>
    using quantity_t = quantity_product<quantity_factor<symbol, exponent>>;

    template <static_string symbol, int exponent = 1>
    inline constexpr auto quantity_v = quantity_t<symbol, exponent>{};



    namespace detail
    {

        template<int exponent> requires(exponent == 0)
        [[nodiscard]] consteval auto pow(quantity_c auto quantity) noexcept
        {
            using namespace quantities;

            return _1;
        }

        template<int exponent> requires(exponent == 1)
        [[nodiscard]] consteval auto pow(quantity_c auto quantity) noexcept
        {
            return quantity;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(base_quantity_c auto quantity) noexcept
        {
            const auto factor = std::get<0>(quantity.factors);

            return quantity_v<factor.symbol, factor.exponent * exponent>;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(derived_quantity_c auto quantity) noexcept
        {
            if constexpr (quantity.size == 0)
            {
                return quantity;
            }
            else
            {
                return pow<exponent>(quantity_product_head(quantity))
                    * pow<exponent>(quantity_product_tail(quantity));
            }
        }

    }

    template<quantity_c auto quantity, int exponent>
    inline constexpr quantity_c auto pow_v = detail::pow<exponent>(quantity);



    [[nodiscard]] consteval auto operator*(
        base_quantity_c auto quantity_1, base_quantity_c auto quantity_2
    ) noexcept
    {
        const quantity_factor_c auto factor_1 = std::get<0>(quantity_1.factors);
        const quantity_factor_c auto factor_2 = std::get<0>(quantity_2.factors);

        if constexpr(factor_1.symbol < factor_2.symbol)
        {
            return detail::quantity_product_concat(quantity_1, quantity_2);
        }
        else
        if constexpr(factor_2.symbol < factor_1.symbol)
        {
            return detail::quantity_product_concat(quantity_2, quantity_1);
        }
        else
        if constexpr(factor_1.exponent + factor_2.exponent == 0)
        {
            return _1;
        }
        else
        {
            return quantity_v<factor_1.symbol, factor_1.exponent + factor_2.exponent>;
        }
    }

    [[nodiscard]] consteval auto operator*(
        derived_quantity_c auto quantity_1, base_quantity_c auto quantity_2
    )
    {
        if constexpr(quantity_1.size == 0)
        {
            return quantity_2;
        }
        else
        {
            const auto factor_2 = std::get<0>(quantity_2.factors);
            const auto head = quantity_product_head(quantity_1);
            const auto head_factor = std::get<0>(head);

            if constexpr (factor_2.symbol < head_factor.symbol)
            {
                return detail::quantity_product_concat(quantity_2, quantity_1);
            }
            else
            if constexpr (
                const auto tail = quantity_product_tail(quantity_1);
                factor_2.quantity == head_factor.quantity
            )
            {
                if (factor_2.symbol != head_factor.symbol)
                    throw "incompatible symbols";

                return detail::quantity_product_concat(head * quantity_2, tail);
            }
            else
            {
                return detail::quantity_product_concat(head, tail * quantity_2);
            }
        }
    }

    [[nodiscard]] consteval auto operator*(
        base_quantity_c auto quantity_1, derived_quantity_c auto quantity_2
    )
    {
        return quantity_2 * quantity_1;
    }

    [[nodiscard]] consteval auto operator*(
        derived_quantity_c auto quantity_1, derived_quantity_c auto quantity_2
    )
    {
        if constexpr (quantity_1.size == 0)
        {
            return quantity_2;
        }
        else
        if constexpr (quantity_2.size == 0)
        {
            return quantity_1;
        }
        else
        {
            return quantity_product_head(quantity_1)
                 * (quantity_product_tail(quantity_1) * quantity_2);
        }
    }



    [[nodiscard]] consteval auto operator/(
        quantity_c auto quantity_1, quantity_c auto quantity_2
    )
    {
        return quantity_1 * pow_v<quantity_2, -1>;
    }



    [[nodiscard]] consteval bool operator==(
        quantity_factor_c auto factor_1, quantity_factor_c auto factor_2
    ) noexcept
    {
        return factor_1.symbol   == factor_2.symbol
            && factor_1.exponent == factor_2.exponent;
    }

    [[nodiscard]] consteval bool operator!=(
        quantity_factor_c auto factor_1, quantity_factor_c auto factor_2
    ) noexcept
    {
        return !(factor_1 == factor_2);
    }

    [[nodiscard]] consteval bool operator<(
        quantity_factor_c auto factor_1, quantity_factor_c auto factor_2
    ) noexcept
    {
        return factor_1.symbol < factor_2.symbol
            || factor_1.symbol == factor_2.symbol
            && factor_1.exponent < factor_2.exponent;
    }



    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator==(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return tuple_equal(quantity_1.factors, quantity_2.factors);
    }

    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator!=(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return !(quantity_1 == quantity_2);
    }

    template <quantity_c Quantity1, quantity_c Quantity2>
    [[nodiscard]] consteval bool operator<(Quantity1 quantity_1, Quantity2 quantity_2) noexcept
    {
        return tuple_lexicographical_compare_three_way(quantity_1.factors, quantity_2.factors) < 0;
    }

}


#endif //__ZOLLSTOCK_QUANTITY_CONCEPT_HPP__
