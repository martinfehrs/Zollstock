#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/quantity_data.hpp>
#include <zollstock/unit_prefix_concept.hpp>

#include <array>
#include <type_traits>
#include <concepts>
#include <string>
#include <string_view>
#include <iostream>
#include <sstream>


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
    };

    template <typename Candidate>
    concept raised_unit_c = requires
    {
        requires base_unit_c<std::remove_reference_t<decltype(Candidate::base_unit)>>;
        { Candidate::exponent } -> std::same_as<const int&>;
    };

    template <typename Candidate>
    concept homogeneous_unit_c = base_unit_c<Candidate >|| raised_unit_c<Candidate>;


    template<class Candidate, std::size_t index>
    concept has_base_unit_tuple_element_c = requires (Candidate candidate)
    {
        requires homogeneous_unit_c<typename std::tuple_element<index, Candidate>::type>;
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



    template <unit_c Unit>
    [[nodiscard]] consteval bool is_base_unit(Unit unit) noexcept
    {
        return base_unit_c<Unit>;
    }

    template <unit_c Unit>
    [[nodiscard]] consteval bool is_raised_unit(Unit unit) noexcept
    {
        return raised_unit_c<Unit>;
    }

    template <unit_c Unit>
    [[nodiscard]] consteval bool is_unit_product(Unit unit) noexcept
    {
        return unit_product_c<Unit>;
    }



    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        const auto unit_data_1 = unit_data(unit_1);
        const auto unit_data_2 = unit_data(unit_2);

        if(std::size(unit_data_1) != std::size(unit_data_2))
            return false;

        bool convertible = true;

        for(std::size_t i = 0; i < std::size(unit_data_1); ++i)
            convertible = convertible && unit_data_1[i].quantity == unit_data_2[i].quantity
                                      && unit_data_1[i].exponent  == unit_data_2[i].exponent;

        return convertible;
    }


    template<quantity_t quantity_, static_string symbol_, long double factor_>
    struct unit
    {
        static constexpr auto quantity = quantity_;
        static constexpr auto symbol = symbol_;
        static constexpr auto factor = factor_;
    };



    template<quantity_t quantity_, static_string symbol_, prefix_c auto prefix>
    struct prefixed_unit
    {
        static constexpr auto quantity = quantity_;
        static constexpr auto symbol = prefix.symbol + symbol_;
        static constexpr auto factor = prefix.factor;
    };


    template <base_unit_c auto base_unit_, int exponent_>
    struct raised_unit
    {
        static constexpr auto base_unit = base_unit_;
        static constexpr auto exponent = exponent_;
    };


    template<homogeneous_unit_c auto... base_units_>
    struct unit_product
    {
        static constexpr auto base_units = std::tuple{ base_units_... };
        static constexpr std::size_t size = sizeof...(base_units_);
    };

    template <base_unit_c auto unit, int exponent_>
    inline constexpr auto raised_unit_v = raised_unit<unit, exponent_>{};

    template <homogeneous_unit_c auto... units>
    inline constexpr auto unit_product_v = unit_product<units...>{};


    inline namespace units
    {

        inline namespace constants
        {

            inline constexpr unit_product<> _1{};

        }

    }

    [[nodiscard]] consteval auto unit_quantity(base_unit_c auto unit) noexcept
    {
        return unit.quantity;
    }

    [[nodiscard]] consteval auto unit_quantity(raised_unit_c auto unit) noexcept
    {
        return unit_quantity(unit.base_unit);
    }

    [[nodiscard]] consteval auto unit_quantities(base_unit_c auto unit) noexcept
    {
        return std::tuple{ unit.quantity };
    }

    [[nodiscard]] consteval auto unit_quantities(raised_unit_c auto unit) noexcept
    {
        return unit_quantities(unit.base_unit);
    }

    [[nodiscard]] consteval auto unit_quantities(unit_product_c auto unit) noexcept
    {
        return std::apply(
            [](homogeneous_unit_c auto... units)
            {
                std::tuple quantities{ unit_quantity(units)... };

                //std::ranges::sort(quantities);

                return quantities;
            },
            unit.base_units
        );
    }



    [[nodiscard]] consteval quantity_data unit_data_for(
        quantity_t quantity, base_unit_c auto unit
    ) noexcept
    {
        if (quantity == unit.quantity)
        {
            return { quantity, 1, unit.factor, unit.symbol };
        }
        else
        {
            return { quantity };
        }
    }

    [[nodiscard]] consteval quantity_data unit_data_for(
        quantity_t quantity, raised_unit_c auto unit
    ) noexcept
    {
        if (quantity == unit.base_unit.quantity)
        {
            return { quantity, unit.exponent, unit.base_unit.factor, unit.base_unit.symbol };
        }
        else
        {
            return { quantity };
        }
    }

    namespace detail
    {

        template <std::size_t... indices>
        [[nodiscard]] consteval quantity_data unit_data_for_impl(
            quantity_t quantity, unit_product_c auto unit, std::index_sequence<indices...>
        ) noexcept
        {
            return (
                quantity_data{ quantity } * ... * unit_data_for(quantity, std::get<indices>(unit.base_units))
            );
        }

    }

    [[nodiscard]] consteval quantity_data unit_data_for(
        quantity_t quantity, unit_product_c auto unit
    ) noexcept
    {
        return detail::unit_data_for_impl(quantity, unit, std::make_index_sequence<unit.size>{});
    }


    namespace detail
    {

        template <std::size_t... indices>
        [[nodiscard]] consteval auto unit_data_impl(
            unit_c auto unit, auto quantities, std::index_sequence<indices...>
        )
        {
            return std::array<quantity_data, sizeof...(indices)>{
                unit_data_for(std::get<indices>(quantities), unit)...
            };
        }

    }

    [[nodiscard]] consteval auto unit_data(unit_c auto unit) noexcept
    {
        const auto quantities = unit_quantities(unit);

        return detail::unit_data_impl(
            unit,
            quantities,
            std::make_index_sequence<std::tuple_size_v<decltype(quantities)>>{}
        );
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
        constexpr auto data = unit_data(unit);

        std::string unit_representation;

        for(std::size_t i = 0; i < std::size(data); ++i)
        {
            if(data[i].exponent != 0)
            {
                if(i > 0 && !unit_representation.empty() && unit_representation.back() != '*')
                    unit_representation += '*';

                std::string_view symbol_string{ data[i].symbol.c_str() };

                unit_representation.append(symbol_string.begin(), symbol_string.end());

                if(data[i].exponent != 1)
                    unit_representation += detail::exponent_to_string<Char>(data[i].exponent);
            }
        }

        return unit_representation;
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



    template <
        homogeneous_unit_c auto first_base_unit,
        homogeneous_unit_c auto... remaining_base_units
    >
    [[nodiscard]] consteval auto unit_product_head(
        unit_product<first_base_unit, remaining_base_units...>
    ) noexcept
    {
        return first_base_unit;
    }



    template <
        homogeneous_unit_c auto first_base_unit,
        homogeneous_unit_c auto... remaining_base_units
    >
    [[nodiscard]] consteval auto unit_product_tail(
        unit_product<first_base_unit, remaining_base_units...>
    ) noexcept
    {
        return unit_product_v<remaining_base_units...>;
    }



    namespace detail
    {

        template<int exponent>
        [[nodiscard]] consteval auto pow(unit_c auto unit) noexcept
        {
            if constexpr(exponent == 0 || unit == _1)
            {
                return _1;
            }
            else if constexpr(exponent == 1)
            {
                return unit;
            }
            else if constexpr(is_raised_unit(unit))
            {
                return raised_unit_v<unit.base_unit, unit.exponent * exponent>;
            }
            else if constexpr(is_unit_product(unit))
            {
                return [=]<std::size_t... indices>(std::index_sequence<indices...>)
                {
                    return unit_product_v<pow<exponent>(std::get<indices>(unit.base_units))...>;
                }
                (std::make_index_sequence<unit.size>{});
            }
            else
            {
                return raised_unit_v<unit, exponent>;
            }
        }

    }

    template<unit_c auto unit, int exponent>
    inline constexpr unit_c auto pow_v = detail::pow<exponent>(unit);



    namespace detail
    {

        template <homogeneous_unit_c auto... factors>
        [[nodiscard]] consteval auto unit_product_prepend(
            unit_product<factors...>, homogeneous_unit_c auto factor
        ) noexcept
        {
            return unit_product_v<factor, factors...>;
        }

    }

    [[nodiscard]] consteval auto operator*(
        base_unit_c auto unit_1, base_unit_c auto unit_2
    ) noexcept
    {
        if constexpr(unit_quantity(unit_1) == unit_quantity(unit_2))
        {
            return raised_unit_v<unit_1, 2>;
        }
        else
        {
            return unit_product_v<unit_1>;
        }
    }

    [[nodiscard]] consteval auto operator*(
        base_unit_c auto unit_1, raised_unit_c auto unit_2
    ) noexcept
    {
        if constexpr(unit_quantity(unit_1) == unit_quantity(unit_2))
        {
            return pow_v<unit_1, unit_2.exponent + 1>;
        }
        else
        {
            return unit_product_v<unit_1> * unit_2;
        }
    }

    [[nodiscard]] consteval auto operator*(
        raised_unit_c auto unit_1, base_unit_c auto unit_2
    ) noexcept
    {
        return unit_2 * unit_1;
    }

    [[nodiscard]] consteval auto operator*(
        raised_unit_c auto unit_1, raised_unit_c auto unit_2
    ) noexcept
    {
        if constexpr(unit_quantity(unit_1) == unit_quantity(unit_2))
        {
            return pow_v<unit_1.base_unit, unit_1.exponent + unit_2.exponent>;
        }
        else
        {
            return unit_product_v<unit_1> * unit_2;
        }
    }


    [[nodiscard]] consteval auto operator*(
        unit_product_c auto unit_1, homogeneous_unit_c auto unit_2
    ) noexcept
    {
        if constexpr(unit_1.size == 0)
        {
            return unit_product_v<unit_2>;
        }
        else
        if constexpr (
            const auto head = unit_product_head(unit_1);
            unit_quantity(unit_2) < unit_quantity(head)
        )
        {
            return detail::unit_product_prepend(unit_1, unit_2);
        }
        else
        if constexpr (
            const auto tail = unit_product_tail(unit_1);
            unit_quantity(unit_2) == unit_quantity(head)
        )
        {
            return detail::unit_product_prepend(tail, head * unit_2);
        }
        else
        {
            return detail::unit_product_prepend(tail * unit_2, head);
        }
    }

    [[nodiscard]] consteval auto operator*(
        homogeneous_unit_c auto unit_1, unit_product_c auto unit_2
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



    [[nodiscard]] consteval bool operator==(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        const auto unit_data_1 = unit_data(unit_1);
        const auto unit_data_2 = unit_data(unit_2);

        if(std::size(unit_data_1) != std::size(unit_data_2))
            return false;

        bool equal = true;

        for(std::size_t i = 0; i < std::size(unit_data_1); ++i)
            equal = equal && unit_data_1[i] == unit_data_2[i];

        return equal;
    }

    [[nodiscard]] consteval bool operator!=(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return !(unit_1 == unit_2);
    }

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
