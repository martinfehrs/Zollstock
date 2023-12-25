#ifndef __ZOLLSTOCK_UNIT_ALGORITHMS_HPP__
#define __ZOLLSTOCK_UNIT_ALGORITHMS_HPP__


#include "unit_concept.hpp"
#include "dimensionless_units.hpp"

#include <string>
#include <iostream>


namespace zollstock
{

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

        template <std::size_t pos, typename Char, typename Unit>
        [[nodiscard]] std::basic_string<Char> unit_entry_to_string(const Unit& unit)
        {
            std::basic_string<Char> unit_representation;

            const auto& exponent = get<pos>(unit.exponents);
            const auto& symbol = get<pos>(unit.symbols);

            if(exponent != 0)
            {
                std::string_view symbol_string{ symbol.c_str() };

                unit_representation.append(symbol_string.begin(), symbol_string.end());

                if(exponent != 1)
                    unit_representation += exponent_to_string<Char>(exponent);
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

        template <typename Char, typename Unit, std::size_t... indices>
        [[nodiscard]] std::basic_string<Char> to_basic_string_impl(
            const Unit& unit, std::index_sequence<indices...>
            )
        {
            return detail::basic_concatenator<Char>{ '*' }(
                detail::unit_entry_to_string<indices, Char>(unit)...
            );
        }

    }

    template <typename Char, typename Unit>
    [[nodiscard]] std::basic_string<Char> to_basic_string(const Unit& unit)
    {
        return detail::basic_concatenator<Char>{ "*" }(
            detail::to_basic_string_impl<Char>(unit, make_derived_dimension_index_sequence{}),
            detail::to_basic_string_impl<Char>(unit, make_base_dimension_index_sequence{})
        );
    }

    template <typename Unit, typename = std::enable_if_t<is_unit_v<Unit>>>
    [[nodiscard]] std::string to_string(Unit unit)
    {
        return to_basic_string<char>(unit);
    }

    template <typename Unit, typename = std::enable_if_t<is_unit_v<Unit>>>
    [[nodiscard]] std::wstring to_wstring(Unit unit)
    {
        return to_basic_string<wchar_t>(unit);
    }

    template <typename Char, typename Unit, typename = std::enable_if_t<is_unit_v<Unit>>>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, Unit unit)
    {
        return os << to_basic_string<Char>(unit);
    }


    template <
        typename Unit1,
        typename Unit2,
        typename = std::enable_if_t<is_unit_v<Unit1> && is_unit_v<Unit2>>
    >
    [[nodiscard]] constexpr unit_product<Unit1, Unit2> operator*(Unit1, Unit2) noexcept
    {
        return {};
    }

    template <
        typename Unit1,
        typename Unit2,
        typename = std::enable_if_t<is_unit_v<Unit1> && is_unit_v<Unit2>>
    >
    [[nodiscard]] constexpr unit_division<Unit1, Unit2> operator/(Unit1, Unit2) noexcept
    {
        return {};
    }

    template <
        int exponent,
        typename Unit,
        typename = std::enable_if_t<is_unit_v<Unit>>
    >
    [[nodiscard]] constexpr auto pow(Unit unit) noexcept
    {
        if constexpr(exponent == 0)
        {
            return _1;
        }
        else if constexpr(exponent > 0)
        {
            return unit * pow<exponent - 1>(unit);
        }
        else if constexpr(exponent < 0)
        {
            return (_1 / unit) * pow<exponent + 1>(unit);
        }

    }

    namespace detail
    {
        template <
            typename Unit1,
            typename Unit2,
            std::size_t... indices,
            typename = std::enable_if_t<is_unit_v<Unit1> && is_unit_v<Unit2>>
        >
        [[nodiscard]] constexpr bool equal(
            const Unit1& unit_1, const Unit2& unit_2, std::index_sequence<indices...>
        ) noexcept
        {
            return (... && (get<indices>(unit_1.exponents) == get<indices>(unit_2.exponents)))
                && (... && (get<indices>(unit_1.factors  ) == get<indices>(unit_2.factors  )))
                && (... && (get<indices>(unit_1.symbols  ) == get<indices>(unit_2.symbols  )));
        }
    }

    template <
        typename Unit1,
        typename Unit2,
        typename = std::enable_if_t<is_unit_v<Unit1> && is_unit_v<Unit2>>
    >
    [[nodiscard]] constexpr bool operator==(const Unit1& unit_1, const Unit2& unit_2) noexcept
    {
        return detail::equal(unit_1, unit_2, make_dimension_index_sequence{});
    }

}


#endif //__ZOLLSTOCK_UNIT_ALGORITHMS_HPP__
