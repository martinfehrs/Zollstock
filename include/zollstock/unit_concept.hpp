#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/quantity_data.hpp>

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
        { Candidate::symbol } -> std::same_as<const unit_symbol&>;
    };

    template <typename Candidate>
    concept base_unit_c = requires
    {
        requires named_unit_c<Candidate>;
        { Candidate::quantity_ } -> std::same_as<const quantity&>;
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
    concept heterogeneous_unit_c = requires(Candidate candidate)
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
    [[nodiscard]] consteval bool is_heterogeneous_unit(Unit unit) noexcept
    {
        return heterogeneous_unit_c<Unit>;
    }



    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        bool convertible = true;

        for (const quantity quantity_ : quantities)
            convertible = convertible && (data_of(quantity_, unit_1).exponent == data_of(quantity_, unit_2).exponent);

        return convertible;
    }



    template <base_unit_c auto base_unit_, int exponent_>
    struct unit_exponentiation
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
    inline constexpr auto unit_exponentiation_v = unit_exponentiation<unit, exponent_>{};

    template <homogeneous_unit_c auto... units>
    inline constexpr auto unit_product_v = unit_product<units...>{};


    inline namespace units
    {

        inline namespace types
        {

            using one = unit_product<>;

        }

        inline namespace constants
        {

            inline constexpr one _1{};

        }

    }

    [[nodiscard]] consteval auto unit_quantities(base_unit_c auto unit) noexcept
    {
        return std::array{ unit.quantity_ };
    }

    [[nodiscard]] consteval auto unit_quantities(raised_unit_c auto unit) noexcept
    {
        return unit_quantities(unit.base_unit);
    }

    namespace detail
    {

        [[nodiscard]] consteval auto unit_quantity(base_unit_c auto unit) noexcept
        {
            return unit.quantity_;
        }

        [[nodiscard]] consteval auto unit_quantity(raised_unit_c auto unit) noexcept
        {
            return unit_quantity(unit.base_unit);
        }

        [[nodiscard]] consteval auto units_quantities(homogeneous_unit_c auto... units) noexcept
        {
            std::array quantities{ unit_quantitiy(units)... };

            std::ranges::sort(quantities);

            return quantities;
        }

    }

    [[nodiscard]] consteval auto unit_quantities(heterogeneous_unit_c auto unit) noexcept
    {
        return std::apply(detail::units_quantities, unit.base_units);
    }



    [[nodiscard]] consteval quantity_data data_of(
        quantity quantity_, base_unit_c auto unit
    ) noexcept
    {
        if (quantity_ == unit.quantity_)
        {
            return { 1, unit.factor, unit.symbol };
        }
        else
        {
            return {};
        }
    }

    [[nodiscard]] consteval quantity_data data_of(
        quantity quantity_, raised_unit_c auto unit
    ) noexcept
    {
        if (quantity_ == unit.base_unit.quantity_)
        {
            return { unit.exponent, unit.base_unit.factor, unit.base_unit.symbol };
        }
        else
        {
            return {};
        }
    }

    namespace detail
    {
        template <std::size_t... indices>
        [[nodiscard]] consteval quantity_data data_of_impl(
            quantity quantity_, heterogeneous_unit_c auto unit, std::index_sequence<indices...>
        ) noexcept
        {
            return (
                quantity_data{} * ... * data_of(quantity_, std::get<indices>(unit.base_units))
            );
        }
    }

    [[nodiscard]] consteval quantity_data data_of(
        quantity quantity_, heterogeneous_unit_c auto unit
    ) noexcept
    {
        return detail::data_of_impl(quantity_, unit, std::make_index_sequence<unit.size>{});
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

        template <quantity quantity_, typename Char>
        [[nodiscard]] std::basic_string<Char> quantity_entry_to_string(unit_c auto unit)
        {
            std::basic_string<Char> unit_representation;

            constexpr quantity_data data = data_of(quantity_, unit);

            if(data.exponent != 0)
            {
                std::string_view symbol_string{ data.symbol.c_str() };

                unit_representation.append(symbol_string.begin(), symbol_string.end());

                if(data.exponent != 1)
                    unit_representation += exponent_to_string<Char>(data.exponent);
            }

            return unit_representation;
        }

        template <typename Char>
        class basic_concatenator
        {

        public:

            template <typename Separator>
            explicit basic_concatenator(const Separator& separator)
                : separator{ stringify(separator) }
            {
            }

            template <typename FirstToken, typename... RemainingTokens>
            [[nodiscard]] std::basic_string<Char> operator()(
                const FirstToken& first_token,
                const RemainingTokens&... remaining_tokens
            )
            {
                if constexpr (sizeof...(RemainingTokens) == 0)
                {
                    return stringify(first_token);
                }
                else
                {
                    std::basic_string result = stringify(first_token);

                    const std::basic_string tail = (*this)(remaining_tokens...);

                    if(result.size() > 0 && tail.size() > 0)
                        result += this->separator;

                    result += tail;

                    return result;
                }
            }

        private:

            template <typename Token>
            static std::basic_string<Char> stringify(const Token& token)
            {
                if constexpr(std::is_same_v<Token, std::basic_string<Char>>)
                {
                    return token;
                }
                else
                {
                    std::basic_stringstream<Char> sstream;

                    sstream << token;

                    return sstream.str();
                }
            }

            std::basic_string<Char> separator;

        };

        template <const auto& quantities, typename Char>
        [[nodiscard]] std::basic_string<Char> to_basic_string_impl(unit_c auto unit)
        {
            return [unit]<std::size_t... indices>(std::index_sequence<indices...>)
            {
                return detail::basic_concatenator<Char>{ '*' }(
                    detail::quantity_entry_to_string<quantities[indices], Char>(unit)...
                );
            }
            (std::make_index_sequence<std::size(quantities)>{});
        }

    }

    template <typename Char>
    [[nodiscard]] std::basic_string<Char> to_basic_string(unit_c auto unit)
    {
        return detail::basic_concatenator<Char>{ "*" }(
            detail::to_basic_string_impl<derived_quantities, Char>(unit),
            detail::to_basic_string_impl<base_quantities, Char>(unit)
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



    template <
        homogeneous_unit_c auto first_base_unit,
        homogeneous_unit_c auto... remaining_base_units
    >
    [[nodiscard]] consteval auto head(
        unit_product<first_base_unit, remaining_base_units...>
    ) noexcept
    {
        return first_base_unit;
    }

    template <
        homogeneous_unit_c auto first_base_unit,
        homogeneous_unit_c auto... remaining_base_units
    >
    [[nodiscard]] consteval auto tail(
        unit_product<first_base_unit, remaining_base_units...>
    ) noexcept
    {
        return unit_product_v<remaining_base_units...>;
    }



    namespace detail
    {

        template <homogeneous_unit_c auto... base_units>
        [[nodiscard]] consteval auto append_to_product_raw(
            homogeneous_unit_c auto base_unit, unit_product<base_units...>
        ) noexcept
        {
            return unit_product_v<base_units..., base_unit>;
        }

        template <homogeneous_unit_c auto... base_units>
        [[nodiscard]] consteval auto prepend_to_product_raw(
            homogeneous_unit_c auto base_unit, unit_product<base_units...>
        ) noexcept
        {
            return unit_product_v<base_unit, base_units...>;
        }

        template <homogeneous_unit_c auto... base_units_1, homogeneous_unit_c auto... base_units_2>
        [[nodiscard]] consteval auto concat_products_raw(
            unit_product<base_units_1...>,
            unit_product<base_units_2...>
        ) noexcept
        {
            return unit_product_v<base_units_1..., base_units_2...>;
        }



        template <unit_c Unit>
        struct erasure_result
        {
            Unit unit;
            int exponent;
        };

        template <unit_c Unit>
        erasure_result(Unit, int) -> erasure_result<Unit>;


        [[nodiscard]] consteval auto erase_product_base(
            base_unit_c auto base_unit, unit_product<> unit
        ) noexcept
        {
            return erasure_result{ unit, 0 };
        }

        template <
            homogeneous_unit_c auto first_base_unit,
            homogeneous_unit_c auto... remaining_base_units
        >
        [[nodiscard]] consteval auto erase_product_base(
            base_unit_c auto base_unit, unit_product<first_base_unit, remaining_base_units...> unit
        ) noexcept
        {
            auto[cleared_tail, exponent] = erase_product_base(
                base_unit, unit_product_v<remaining_base_units...>
            );

            if constexpr(is_raised_unit(first_base_unit))
            {
                if constexpr(first_base_unit.base_unit == base_unit)
                {
                    return erasure_result{
                        cleared_tail,
                        exponent + first_base_unit.exponent
                    };
                }
                else
                {
                    return erasure_result{ unit, exponent };
                }
            }
            else if constexpr (is_base_unit(first_base_unit))
            {
                if constexpr(first_base_unit == base_unit)
                {
                    return erasure_result{ cleared_tail, exponent + 1 };
                }
                else
                {
                    return erasure_result{ unit, exponent };
                }
            }

        }



        [[nodiscard]] consteval auto combine_redundant_product_bases(
            heterogeneous_unit_c auto unit
        ) noexcept
        {
            if constexpr(unit.size <= 1)
            {
                return unit;
            }
            else
            {
                auto first = head(unit);

                if constexpr (is_base_unit(first))
                {
                    constexpr auto erasure_result = erase_product_base(
                        first,
                        combine_redundant_product_bases(tail(unit))
                    );

                    if constexpr(erasure_result.exponent != 0)
                    {
                        return prepend_to_product_raw(
                            unit_exponentiation_v<first, erasure_result.exponent + 1>,
                            erasure_result.unit
                        );
                    }
                    else
                    {
                        return prepend_to_product_raw(first, erasure_result.unit);
                    }
                }
                else if constexpr(is_raised_unit(first))
                {
                    constexpr auto erasure_result = erase_product_base(
                        first.base_unit,
                        combine_redundant_product_bases(tail(unit))
                    );

                    if constexpr(erasure_result.exponent != 0)
                    {
                        return prepend_to_product_raw(
                            unit_exponentiation_v<
                                first.base_unit,
                                first.exponent + erasure_result.exponent
                            >,
                            erasure_result.unit
                        );
                    }
                    else
                    {
                        return prepend_to_product_raw(first, erasure_result.unit);
                    }
                }
            }
        }



        [[nodiscard]] consteval auto simplify_combined_unit(unit_c auto unit) noexcept
        {
            if constexpr(is_base_unit(unit))
            {
                return unit;
            }
            else if constexpr(is_raised_unit(unit))
            {
                if constexpr(unit.exponent == 0)
                {
                    return _1;
                }
                else if constexpr(unit.exponent == 1)
                {
                    return unit.base_unit;
                }
                else
                {
                    return unit;
                }
            }
            else if constexpr(is_heterogeneous_unit(unit))
            {
                if constexpr(unit.size == 0)
                {
                    return _1;
                }
                else if constexpr(unit.size == 1)
                {
                    return simplify_combined_unit(head(unit));
                }
                else
                {
                    constexpr auto reduced_unit = combine_redundant_product_bases(unit);

                    if constexpr(reduced_unit.size <= 1)
                    {
                        return simplify_combined_unit(reduced_unit);
                    }
                    else
                    {
                        return reduced_unit;
                    }
                }
            }
        }



        [[nodiscard]] consteval auto append_to_product(
            homogeneous_unit_c auto base_unit, heterogeneous_unit_c auto unit
        ) noexcept
        {
            return simplify_combined_unit(append_to_product_raw(base_unit, unit));
        }

        [[nodiscard]] consteval auto prepend_to_product(
            homogeneous_unit_c auto base_unit, heterogeneous_unit_c auto unit
        ) noexcept
        {
            return simplify_combined_unit(prepend_to_product_raw(base_unit, unit));
        }

        [[nodiscard]] consteval auto concat_products(
            heterogeneous_unit_c auto unit_1, heterogeneous_unit_c auto unit_2
        ) noexcept
        {
            return simplify_combined_unit(concat_products_raw(unit_1, unit_2));
        }

    }

    [[nodiscard]] consteval auto operator*(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        if constexpr(is_heterogeneous_unit(unit_1) && is_heterogeneous_unit(unit_2))
        {
            return detail::concat_products(unit_1, unit_2);
        }
        else
        if constexpr(is_heterogeneous_unit(unit_1))
        {
            return detail::append_to_product(unit_2, unit_1);
        }
        else
        if constexpr(is_heterogeneous_unit(unit_2))
        {
            return detail::prepend_to_product(unit_1, unit_2);
        }
        else
        {
            return detail::simplify_combined_unit(unit_product_v<unit_1, unit_2>);
        }
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
                return unit_exponentiation_v<unit.base_unit, unit.exponent * exponent>;
            }
            else if constexpr(is_heterogeneous_unit(unit))
            {
                return [=]<std::size_t... indices>(std::index_sequence<indices...>)
                {
                    return unit_product_v<pow<exponent>(std::get<indices>(unit.base_units))...>;
                }
                (std::make_index_sequence<unit.size>{});
            }
            else
            {
                return unit_exponentiation_v<unit, exponent>;
            }
        }

    }

    template<unit_c auto unit, int exponent>
    inline constexpr unit_c auto pow_v = detail::pow<exponent>(unit);



    [[nodiscard]] consteval auto operator/(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return unit_1 * pow_v<unit_2, -1>;
    }



    [[nodiscard]] consteval bool operator==(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        bool equal = true;

        for(const quantity quantity_ : quantities)
            equal = equal && data_of(quantity_, unit_1) == data_of(quantity_, unit_2);

        return equal;
    }

    [[nodiscard]] consteval bool operator!=(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return !(unit_1 == unit_2);
    }

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
