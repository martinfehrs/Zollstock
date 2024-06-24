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
    concept unit_c = std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;

    template <typename Candidate>
    concept named_unit_c = requires
    {
        requires unit_c<Candidate>;
        { Candidate::symbol } -> std::same_as<const static_string&>;
    };

    template <typename Candidate>
    concept base_unit_c = requires
    {
        requires named_unit_c<Candidate>;
        { Candidate::quantity } -> std::same_as<const quantity_t&>;
        { Candidate::factor } -> std::same_as<const long double&>;
        { Candidate::exponent } -> std::same_as<const int&>;
    };

    template<class Candidate, std::size_t index>
    concept has_base_unit_tuple_element_c = requires (Candidate candidate)
    {
        requires base_unit_c<typename std::tuple_element<index, Candidate>::type>;
        { get<index>(candidate) } -> std::convertible_to<std::tuple_element_t<index, Candidate>&>;
    };

    template<class Candidate>
    concept is_base_unit_tuple_like_c = requires
    {
        requires []<std::size_t... indices>(std::index_sequence<indices...>)
        {
            return (has_base_unit_tuple_element_c<Candidate, indices> && ...);
        }
        (std::make_index_sequence<std::tuple_size_v<Candidate>>{});

    };

    template <typename Candidate>
    concept unit_product_c = requires
    {
        requires unit_c<Candidate>;
        requires is_base_unit_tuple_like_c<std::remove_cvref_t<decltype(Candidate::base_units)>>;
    };



    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return tuple_equal(
            base_units(unit_1),
            base_units(unit_2),
            [](const auto& base_unit_1, const auto& base_unit_2)
            {
                return base_unit_1.quantity == base_unit_2.quantity
                    && base_unit_1.exponent == base_unit_2.exponent;
            }
        );
    }


    template<quantity_t quantity_, static_string symbol_, long double factor_, int exponent_ = 1>
    struct unit
    {
        static constexpr auto quantity = quantity_;
        static constexpr auto symbol = symbol_;
        static constexpr auto factor = factor_;
        static constexpr auto exponent = exponent_;
    };

    template <quantity_t quantity, static_string symbol, long double factor, int exponent = 1>
    inline constexpr auto unit_v = unit<quantity, symbol, factor, exponent>{};

    template <quantity_t quantity, static_string symbol, prefix_c auto prefix, int exponent = 1>
    inline constexpr auto prefixed_unit_v = unit<
        quantity,
        prefix.symbol + symbol,
        prefix.factor,
        exponent
    >{};



    template<base_unit_c auto... base_units_>
    struct unit_product
    {
        static constexpr auto base_units = std::tuple{ base_units_... };
        static constexpr std::size_t size = sizeof...(base_units_);
    };

    template <base_unit_c auto... units>
    inline constexpr auto unit_product_v = unit_product<units...>{};



    inline namespace units
    {

        inline namespace constants
        {

            inline constexpr unit_product<> _1{};

        }

    }



    [[nodiscard]] consteval auto base_units(base_unit_c auto unit) noexcept
    {
        return std::tuple{ unit };
    }

    [[nodiscard]] consteval auto base_units(unit_product_c auto unit) noexcept
    {
        return unit.base_units;
    }



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
            base_units(unit),
            ""s,
            [](std::string lhs, const std::string& rhs)
            {
                if (!lhs.empty() && lhs.back() != '*')
                    lhs += '*';

                return lhs += rhs;
            },
            [](const base_unit_c auto& base_unit)
            {
                std::string symbol{ base_unit.symbol.c_str() };

                if(base_unit.exponent != 1)
                    symbol += detail::exponent_to_string<Char>(base_unit.exponent);

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



    template <base_unit_c auto first_base_unit, base_unit_c auto... remaining_base_units>
    [[nodiscard]] consteval auto unit_product_head(
        unit_product<first_base_unit, remaining_base_units...>
    ) noexcept
    {
        return first_base_unit;
    }



    template <base_unit_c auto first_base_unit, base_unit_c auto... remaining_base_units>
    [[nodiscard]] consteval auto unit_product_tail(
        unit_product<first_base_unit, remaining_base_units...>
    ) noexcept
    {
        return unit_product_v<remaining_base_units...>;
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
            return unit_v<
                unit.quantity,
                unit.symbol,
                unit.factor,
                unit.exponent * exponent
            >;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(unit_product_c auto unit) noexcept
        {
            return [=]<std::size_t... indices>(std::index_sequence<indices...>)
            {
                return unit_product_v<pow<exponent>(std::get<indices>(unit.base_units))...>;
            }
            (std::make_index_sequence<unit.size>{});
        }

    }

    template<unit_c auto unit, int exponent>
    inline constexpr unit_c auto pow_v = detail::pow<exponent>(unit);



    namespace detail
    {

        template <base_unit_c auto... factors>
        [[nodiscard]] consteval auto unit_product_prepend(
            unit_product<factors...>, base_unit_c auto factor
        ) noexcept
        {
            return unit_product_v<factor, factors...>;
        }

    }



    [[nodiscard]] consteval auto operator*(
        base_unit_c auto unit_1, base_unit_c auto unit_2
    ) noexcept
    {
        if constexpr(unit_1.quantity == unit_2.quantity)
        {
            if constexpr(unit_1.exponent + unit_2.exponent == 0)
            {
                return _1;
            }
            else
            {
                if (unit_1.factor != unit_2.factor)
                    throw "incompatible factors";

                if (unit_1.symbol != unit_2.symbol)
                    throw "incompatible symbols";

                return unit_v<
                    unit_1.quantity,
                    unit_1.symbol,
                    unit_1.factor,
                    unit_1.exponent + unit_2.exponent
                >;
            }
        }
        else
        {
            return unit_product_v<unit_1> * unit_2;
        }
    }

    [[nodiscard]] consteval auto operator*(
        unit_product_c auto unit_1, base_unit_c auto unit_2
    ) noexcept
    {
        if constexpr(unit_1.size == 0)
        {
            return unit_product_v<unit_2>;
        }
        else
        if constexpr (
            const auto head = unit_product_head(unit_1);
            unit_2.quantity < head.quantity
        )
        {
            return detail::unit_product_prepend(unit_1, unit_2);
        }
        else
        if constexpr (
            const auto tail = unit_product_tail(unit_1);
            unit_2.quantity == head.quantity
        )
        {
            if (unit_2.factor != head.factor)
                throw "incompatible factors";

            if (unit_2.symbol != head.symbol)
                throw "incompatible symbols";

            return detail::unit_product_prepend(tail, head * unit_2);
        }
        else
        {
            return detail::unit_product_prepend(tail * unit_2, head);
        }
    }

    [[nodiscard]] consteval auto operator*(
        base_unit_c auto unit_1, unit_product_c auto unit_2
    ) noexcept
    {
        return unit_2 * unit_1;
    }

    [[nodiscard]] consteval auto operator*(
        unit_product_c auto unit_1, unit_product_c auto unit_2
    ) noexcept
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



    [[nodiscard]] consteval auto operator/(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return unit_1 * pow_v<unit_2, -1>;
    }



    [[nodiscard]] consteval bool operator==(
        const base_unit_c auto unit_1, const base_unit_c auto unit_2
    ) noexcept
    {
        return unit_1.quantity == unit_2.quantity
            && unit_1.symbol   == unit_2.symbol
            && unit_1.factor   == unit_2.factor
            && unit_1.exponent == unit_2.exponent;
    }

    [[nodiscard]] constexpr bool operator==(unit_product_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return tuple_equal(base_units(unit_1), base_units(unit_2));
    }

    [[nodiscard]] consteval bool operator==(
        base_unit_c auto unit_1, unit_product_c auto unit_2
    ) noexcept
    {
        return unit_2 == unit_1;
    }



    [[nodiscard]] consteval bool operator!=(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return !(unit_1 == unit_2);
    }

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
