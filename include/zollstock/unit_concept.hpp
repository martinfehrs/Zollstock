#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/quantities.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/tuple_utils.hpp>

#include <tuple>
#include <type_traits>
#include <concepts>
#include <string>
#include <iostream>


namespace zollstock
{

    template <typename Candidate>
    concept unit_factor_c = requires
    {
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        requires quantities::quantity_c<std::remove_cvref_t<decltype(Candidate::quantity)>>;
        { Candidate::symbol         } -> std::same_as<const static_string&>;
        { Candidate::scaling_factor } -> std::same_as<const long double&>;
        { Candidate::exponent       } -> std::same_as<const int&>;
    };

    template<class Candidate, std::size_t index>
    concept has_unit_factor_tuple_element_c = requires (Candidate candidate)
    {
        requires unit_factor_c<typename std::tuple_element<index, Candidate>::type>;
        { get<index>(candidate) } -> std::convertible_to<std::tuple_element_t<index, Candidate>&>;
    };

    template<class Candidate>
    concept is_unit_factor_tuple_like_c = requires
    {
        requires []<std::size_t... indices>(std::index_sequence<indices...>)
        {
            return (has_unit_factor_tuple_element_c<Candidate, indices> && ...);
        }
        (std::make_index_sequence<std::tuple_size_v<Candidate>>{});

    };

    template <typename Candidate>
    concept unit_c = requires
    {
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        requires is_unit_factor_tuple_like_c<std::remove_cvref_t<decltype(Candidate::factors)>>;
    };

    template <typename Candidate>
    concept base_unit_c = unit_c<Candidate> && Candidate::size == 1;

    template <typename Candidate>
    concept derived_unit_c = unit_c<Candidate> && Candidate::size != 1;



    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return tuple_equal(
            unit_1.factors,
            unit_2.factors,
            [](const auto& factor_1, const auto& factor_2)
            {
                return factor_1.quantity == factor_2.quantity
                    && factor_1.exponent == factor_2.exponent;
            }
        );
    }


    template<
        quantities::quantity_c auto quantity_,
        static_string symbol_,
        long double scaling_factor_,
        int exponent_
    >
    struct unit_factor
    {
        static constexpr auto quantity = quantity_;
        static constexpr auto symbol = symbol_;
        static constexpr auto scaling_factor = scaling_factor_;
        static constexpr auto exponent = exponent_;
    };



    template<unit_factor_c... Factors>
    struct unit_product
    {
        static constexpr auto factors = std::tuple{ Factors{}... };
        static constexpr std::size_t size = sizeof...(Factors);
    };

    template <unit_factor_c... Factors>
    inline constexpr auto unit_product_v = unit_product<Factors...>{};

    template <unit_factor_c FirstFactor, unit_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto unit_product_head(
        unit_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return unit_product_v<FirstFactor>;
    }

    template <unit_factor_c FirstFactor, unit_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto unit_product_tail(
        unit_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return unit_product_v<RemainingFactors...>;
    }

    namespace detail
    {

        template <unit_factor_c ... Factors1, unit_factor_c... Factors2>
        [[nodiscard]] consteval auto unit_product_concat(
            unit_product<Factors1...>, unit_product<Factors2...>
        ) noexcept
        {
            return unit_product_v<Factors1..., Factors2...>;
        }

    }

    inline namespace units
    {

        inline namespace constants
        {

            inline constexpr unit_product<> _1{};

        }

    }


    template <
        quantities::quantity_c auto quantity,
        static_string symbol,
        long double scaling_factor, int exponent = 1
    >
    using unit = unit_product<unit_factor<quantity, symbol, scaling_factor, exponent>>;

    template <
        quantities::quantity_c auto quantity,
        static_string symbol,
        long double scaling_factor,
        int exponent = 1
    >
    inline constexpr auto unit_v = unit<quantity, symbol, scaling_factor, exponent>{};



    template <
        quantities::quantity_c auto quantity,
        static_string symbol,
        prefix_c auto prefix,
        int exponent = 1
    >
    using prefixed_unit = unit<quantity, prefix.symbol + symbol, prefix.factor, exponent>;

    template <
        quantities::quantity_c auto quantity,
        static_string symbol,
        prefix_c auto prefix,
        int exponent = 1
    >
    inline constexpr auto prefixed_unit_v = prefixed_unit<quantity, symbol, prefix, exponent>{};



    namespace detail
    {

        template <typename Char>
        [[nodiscard]] std::basic_string<Char> exponent_to_string(int exponent)
        {
            std::basic_string<Char> string_representation;

            string_representation += '^';

            std::basic_stringstream<Char> ss;

            ss << exponent;

            string_representation += ss.str();

            return string_representation;
        }

    }

    template <typename Char>
    [[nodiscard]] std::basic_string<Char> to_basic_string(unit_c auto unit)
    {
        using namespace std::string_literals;

        return tuple_transform_reduce(
            unit.factors,
            ""s,
            [](std::string lhs, const std::string& rhs)
            {
                if (!lhs.empty() && lhs.back() != '*')
                    lhs += '*';

                return lhs += rhs;
            },
            [](const unit_factor_c auto& factor)
            {
                std::string symbol{ factor.symbol.c_str() };

                if(factor.exponent != 1)
                    symbol += detail::exponent_to_string<Char>(factor.exponent);

                return symbol;
            }
        );
    }

    [[nodiscard]] std::string to_string(unit_c auto unit)
    {
        return to_basic_string<char>(unit);
    }

    [[nodiscard]] std::wstring to_wstring(unit_c auto unit)
    {
        return to_basic_string<wchar_t>(unit);
    }

    template <typename Char>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, unit_c auto unit)
    {
        return os << to_basic_string<Char>(unit);
    }



    namespace detail
    {

        template<int exponent> requires(exponent == 0)
        [[nodiscard]] consteval auto pow(unit_c auto unit) noexcept
        {
            return _1;
        }

        template<int exponent> requires(exponent == 1)
        [[nodiscard]] consteval auto pow(unit_c auto unit) noexcept
        {
            return unit;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(base_unit_c auto unit) noexcept
        {
            const auto factor = std::get<0>(unit.factors);

            return unit_v<
                factor.quantity,
                factor.symbol,
                factor.scaling_factor,
                factor.exponent * exponent
            >;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(derived_unit_c auto unit) noexcept
        {
            if constexpr (unit.size == 0)
            {
                return unit;
            }
            else
            {
                return pow<exponent>(unit_product_head(unit))
                     * pow<exponent>(unit_product_tail(unit));
            }
        }

    }

    template<unit_c auto unit, int exponent>
    inline constexpr unit_c auto pow_v = detail::pow<exponent>(unit);



    [[nodiscard]] consteval auto operator*(base_unit_c auto unit_1, base_unit_c auto unit_2)
    {
        const unit_factor_c auto factor_1 = std::get<0>(unit_1.factors);
        const unit_factor_c auto factor_2 = std::get<0>(unit_2.factors);

        if constexpr(factor_1.quantity < factor_2.quantity)
        {
            return detail::unit_product_concat(unit_1, unit_2);
        }
        else
        if constexpr(factor_2.quantity < factor_1.quantity)
        {
            return detail::unit_product_concat(unit_2, unit_1);
        }
        else
        if constexpr(factor_1.exponent + factor_2.exponent == 0)
        {
            return _1;
        }
        else
        {
            if (factor_1.scaling_factor != factor_2.scaling_factor)
                throw "incompatible factors";

            if (factor_1.symbol != factor_2.symbol)
                throw "incompatible symbols";

            return unit_v<
                factor_1.quantity,
                factor_1.symbol,
                factor_1.scaling_factor,
                factor_1.exponent + factor_2.exponent
            >;
        }
    }

    [[nodiscard]] consteval auto operator*(derived_unit_c auto unit_1, base_unit_c auto unit_2)
    {
        if constexpr(unit_1.size == 0)
        {
            return unit_2;
        }
        else
        {
            const auto factor_2 = std::get<0>(unit_2.factors);
            const auto head = unit_product_head(unit_1);
            const auto head_factor = std::get<0>(head);

            if constexpr (factor_2.quantity < head_factor.quantity)
            {
                return detail::unit_product_concat(unit_2, unit_1);
            }
            else
            if constexpr (
                const auto tail = unit_product_tail(unit_1);
                factor_2.quantity == head_factor.quantity
            )
            {
                if (factor_2.scaling_factor != head_factor.scaling_factor)
                    throw "incompatible factors";

                if (factor_2.symbol != head_factor.symbol)
                    throw "incompatible symbols";

                return detail::unit_product_concat(head * unit_2, tail);
            }
            else
            {
                return detail::unit_product_concat(head, tail * unit_2);
            }
        }
    }

    [[nodiscard]] consteval auto operator*(base_unit_c auto unit_1, derived_unit_c auto unit_2)
    {
        return unit_2 * unit_1;
    }

    [[nodiscard]] consteval auto operator*(derived_unit_c auto unit_1, derived_unit_c auto unit_2)
    {
        if constexpr (unit_1.size == 0)
        {
            return unit_2;
        }
        else
        if constexpr (unit_2.size == 0)
        {
            return unit_1;
        }
        else
        {
            return unit_product_head(unit_1) * (unit_product_tail(unit_1) * unit_2);
        }
    }



    [[nodiscard]] consteval auto operator/(unit_c auto unit_1, unit_c auto unit_2)
    {
        return unit_1 * pow_v<unit_2, -1>;
    }



    [[nodiscard]] consteval bool operator==(
        unit_factor_c auto factor_1, unit_factor_c auto factor_2
    ) noexcept
    {
        return factor_1.quantity       == factor_2.quantity
            && factor_1.symbol         == factor_2.symbol
            && factor_1.scaling_factor == factor_2.scaling_factor
            && factor_1.exponent       == factor_2.exponent;
    }

    [[nodiscard]] consteval bool operator!=(
        unit_factor_c auto factor_1, unit_factor_c auto factor_2
    ) noexcept
    {
        return !(factor_1 == factor_2);
    }



    [[nodiscard]] consteval bool operator==(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return tuple_equal(unit_1.factors, unit_2.factors);
    }

    [[nodiscard]] consteval bool operator!=(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return !(unit_1 == unit_2);
    }

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
