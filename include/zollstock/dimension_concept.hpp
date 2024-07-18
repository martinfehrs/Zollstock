#ifndef __ZOLLSTOCK_DIMENSION_CONCEPT_HPP__
#define __ZOLLSTOCK_DIMENSION_CONCEPT_HPP__


#include <zollstock/static_string.hpp>
#include <zollstock/tuple_utils.hpp>

#include <cstddef>
#include <concepts>
#include <type_traits>


namespace zollstock::dimensions
{

    template <typename Candidate>
    concept dimension_factor_c = requires
    {
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        { Candidate::symbol         } -> std::same_as<const static_string&>;
        { Candidate::exponent       } -> std::same_as<const int&>;
    };

    template<class Candidate, std::size_t index>
    concept has_dimension_factor_tuple_element_c = requires (Candidate candidate)
    {
        requires dimension_factor_c<typename std::tuple_element<index, Candidate>::type>;
        { get<index>(candidate) } -> std::convertible_to<std::tuple_element_t<index, Candidate>&>;
    };

    template<class Candidate>
    concept is_dimension_factor_tuple_like_c = requires
    {
        requires []<std::size_t... indices>(std::index_sequence<indices...>)
        {
            return (has_dimension_factor_tuple_element_c<Candidate, indices> && ...);
        }
        (std::make_index_sequence<std::tuple_size_v<Candidate>>{});
    };

    struct dimension_tag;

    template <typename Candidate>
    concept dimension_c = requires
    {
        requires std::same_as<typename Candidate::type, dimension_tag>;
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        requires is_dimension_factor_tuple_like_c<std::remove_cvref_t<decltype(Candidate::factors)>>;
    };

    template <typename Candidate>
    concept base_dimension_c = dimension_c<Candidate> && Candidate::size == 1;

    template <typename Candidate>
    concept derived_dimension_c = dimension_c<Candidate> && Candidate::size != 1;



    template<static_string symbol_, int exponent_>
    struct dimension_factor
    {
        static constexpr auto symbol = symbol_;
        static constexpr auto exponent = exponent_;
    };



    template<dimension_factor_c... Factors>
    struct dimension_product
    {
        using type = dimension_tag;
        static constexpr auto factors = std::tuple{ Factors{}... };
        static constexpr std::size_t size = sizeof...(Factors);
    };

    template <dimension_factor_c... Factors>
    inline constexpr auto dimension_product_v = dimension_product<Factors...>{};

    template <dimension_factor_c FirstFactor, dimension_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto dimension_product_head(
        dimension_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return dimension_product_v<FirstFactor>;
    }

    template <dimension_factor_c FirstFactor, dimension_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto dimension_product_tail(
        dimension_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return dimension_product_v<RemainingFactors...>;
    }

    namespace detail
    {

        template <dimension_factor_c ... Factors1, dimension_factor_c... Factors2>
        [[nodiscard]] consteval auto dimension_product_concat(
            dimension_product<Factors1...>, dimension_product<Factors2...>
        ) noexcept
        {
            return dimension_product_v<Factors1..., Factors2...>;
        }

    }

    inline constexpr dimension_product<> _1{};



    template <static_string symbol, int exponent = 1>
    using dimension_t = dimension_product<dimension_factor<symbol, exponent>>;

    template <static_string symbol, int exponent = 1>
    inline constexpr auto dimension_v = dimension_t<symbol, exponent>{};



    namespace detail
    {

        template<int exponent> requires(exponent == 0)
        [[nodiscard]] consteval auto pow(dimension_c auto dimension) noexcept
        {
            return _1;
        }

        template<int exponent> requires(exponent == 1)
        [[nodiscard]] consteval auto pow(dimension_c auto dimension) noexcept
        {
            return dimension;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(base_dimension_c auto dimension) noexcept
        {
            const auto factor = std::get<0>(dimension.factors);

            return dimension_v<factor.symbol, factor.exponent * exponent>;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(derived_dimension_c auto dimension) noexcept
        {
            if constexpr (dimension.size == 0)
            {
                return dimension;
            }
            else
            {
                return pow<exponent>(dimension_product_head(dimension))
                    * pow<exponent>(dimension_product_tail(dimension));
            }
        }

    }

    template<dimension_c auto dimension, int exponent>
    inline constexpr dimension_c auto pow_v = detail::pow<exponent>(dimension);



    [[nodiscard]] consteval auto operator*(
        base_dimension_c auto dimension_1, base_dimension_c auto dimension_2
    ) noexcept
    {
        const dimension_factor_c auto factor_1 = std::get<0>(dimension_1.factors);
        const dimension_factor_c auto factor_2 = std::get<0>(dimension_2.factors);

        if constexpr(factor_1.symbol < factor_2.symbol)
        {
            return detail::dimension_product_concat(dimension_1, dimension_2);
        }
        else
        if constexpr(factor_2.symbol < factor_1.symbol)
        {
            return detail::dimension_product_concat(dimension_2, dimension_1);
        }
        else
        if constexpr(factor_1.exponent + factor_2.exponent == 0)
        {
            return _1;
        }
        else
        {
            return dimension_v<factor_1.symbol, factor_1.exponent + factor_2.exponent>;
        }
    }

    [[nodiscard]] consteval auto operator*(
        derived_dimension_c auto dimension_1, base_dimension_c auto dimension_2
    )
    {
        if constexpr(dimension_1.size == 0)
        {
            return dimension_2;
        }
        else
        {
            const auto factor_2 = std::get<0>(dimension_2.factors);
            const auto head = dimension_product_head(dimension_1);
            const auto head_factor = std::get<0>(head);

            if constexpr (factor_2.symbol < head_factor.symbol)
            {
                return detail::dimension_product_concat(dimension_2, dimension_1);
            }
            else
            if constexpr (
                const auto tail = dimension_product_tail(dimension_1);
                factor_2.dimension == head_factor.dimension
            )
            {
                if (factor_2.symbol != head_factor.symbol)
                    throw "incompatible symbols";

                return detail::dimension_product_concat(head * dimension_2, tail);
            }
            else
            {
                return detail::dimension_product_concat(head, tail * dimension_2);
            }
        }
    }

    [[nodiscard]] consteval auto operator*(
        base_dimension_c auto dimension_1, derived_dimension_c auto dimension_2
    )
    {
        return dimension_2 * dimension_1;
    }

    [[nodiscard]] consteval auto operator*(
        derived_dimension_c auto dimension_1, derived_dimension_c auto dimension_2
    )
    {
        if constexpr (dimension_1.size == 0)
        {
            return dimension_2;
        }
        else
        if constexpr (dimension_2.size == 0)
        {
            return dimension_1;
        }
        else
        {
            return dimension_product_head(dimension_1)
                 * (dimension_product_tail(dimension_1) * dimension_2);
        }
    }



    [[nodiscard]] consteval auto operator/(
        dimension_c auto dimension_1, dimension_c auto dimension_2
    )
    {
        return dimension_1 * pow_v<dimension_2, -1>;
    }



    [[nodiscard]] consteval bool operator==(
        dimension_factor_c auto factor_1, dimension_factor_c auto factor_2
    ) noexcept
    {
        return factor_1.symbol   == factor_2.symbol
            && factor_1.exponent == factor_2.exponent;
    }

    [[nodiscard]] consteval bool operator!=(
        dimension_factor_c auto factor_1, dimension_factor_c auto factor_2
    ) noexcept
    {
        return !(factor_1 == factor_2);
    }

    [[nodiscard]] consteval bool operator<(
        dimension_factor_c auto factor_1, dimension_factor_c auto factor_2
    ) noexcept
    {
        return factor_1.symbol < factor_2.symbol
            || factor_1.symbol == factor_2.symbol
            && factor_1.exponent < factor_2.exponent;
    }



    template <dimension_c Dimension1, dimension_c Dimension2>
    [[nodiscard]] consteval bool operator==(Dimension1 dimension_1, Dimension2 dimension_2) noexcept
    {
        return tuple_equal(dimension_1.factors, dimension_2.factors);
    }

    template <dimension_c Dimension1, dimension_c Dimension2>
    [[nodiscard]] consteval bool operator!=(Dimension1 dimension_1, Dimension2 dimension_2) noexcept
    {
        return !(dimension_1 == dimension_2);
    }

    template <dimension_c Dimension1, dimension_c Dimension2>
    [[nodiscard]] consteval bool operator<(Dimension1 dimension_1, Dimension2 dimension_2) noexcept
    {
        return tuple_lexicographical_compare_three_way(dimension_1.factors, dimension_2.factors) < 0;
    }

}


#endif //__ZOLLSTOCK_DIMENSION_CONCEPT_HPP__
