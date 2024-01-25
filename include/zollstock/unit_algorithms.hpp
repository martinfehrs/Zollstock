#ifndef __ZOLLSTOCK_UNIT_ALGORITHMS_HPP__
#define __ZOLLSTOCK_UNIT_ALGORITHMS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/dimensionless_unit_constants.hpp>

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

        template <std::size_t pos, typename Char, unit_c Unit>
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

        template <typename Char, unit_c Unit, std::size_t... indices>
        [[nodiscard]] std::basic_string<Char> to_basic_string_impl(
            const Unit& unit, std::index_sequence<indices...>
            )
        {
            return detail::basic_concatenator<Char>{ '*' }(
                detail::unit_entry_to_string<indices, Char>(unit)...
            );
        }

    }

    template <typename Char, unit_c Unit>
    [[nodiscard]] std::basic_string<Char> to_basic_string(const Unit& unit)
    {
        return detail::basic_concatenator<Char>{ "*" }(
            detail::to_basic_string_impl<Char>(unit, make_derived_unit_index_sequence{}),
            detail::to_basic_string_impl<Char>(unit, make_base_unit_index_sequence{})
        );
    }

    template <unit_c Unit>
    [[nodiscard]] std::string to_string(Unit unit)
    {
        return to_basic_string<char>(unit);
    }

    template <unit_c Unit>
    [[nodiscard]] std::wstring to_wstring(Unit unit)
    {
        return to_basic_string<wchar_t>(unit);
    }

    template <typename Char, unit_c Unit>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, Unit unit)
    {
        return os << to_basic_string<Char>(unit);
    }

    template <unit_c Unit1, unit_c Unit2>
    [[nodiscard]] consteval auto operator*(Unit1, Unit2) noexcept
    {
        if constexpr(
            Unit1::type == unit_type::exponentiation &&
            Unit2::type == unit_type::exponentiation
        )
        {
            if constexpr(std::same_as<typename Unit1::base_unit, typename Unit2::base_unit>)
            {
                return unit_exponentiation<
                    typename Unit1::base_unit,
                    Unit1::exponent + Unit2::exponent
                >{};
            }
            else
            {
                return unit_product<Unit1, Unit2>{};
            }
        }
        else
        if constexpr(Unit1::type == unit_type::exponentiation && Unit2::type == unit_type::basic)
        {
            if constexpr(std::same_as<typename Unit1::base_unit, Unit2>)
            {
                return unit_exponentiation<typename Unit1::base_unit, Unit1::exponent + 1>{};
            }
            else
            {
                return unit_product<Unit1, Unit2>{};
            }
        }
        else
        if constexpr(Unit1::type == unit_type::basic && Unit2::type == unit_type::exponentiation)
        {
            if constexpr(std::same_as<typename Unit2::base_unit, Unit1>)
            {
                return unit_exponentiation<typename Unit2::base_unit, Unit2::exponent + 1>{};
            }
            else
            {
                return unit_product<Unit1, Unit2>{};
            }
        }
        else
        if constexpr(Unit1::type == unit_type::exponentiation && Unit2::type == unit_type::product)
        {
            if constexpr(std::same_as<typename Unit1::base_unit, typename Unit2::base_unit_1>)
            {
                return unit_product<
                    unit_exponentiation<typename Unit1::base_unit, Unit1::exponent + 1>,
                    typename Unit2::base_unit_2
                >{};
            }
            else
            if constexpr(std::same_as<typename Unit1::base_unit, typename Unit2::base_unit_2>)
            {
                return unit_product<
                    unit_exponentiation<typename Unit1::base_unit, Unit1::exponent + 1>,
                    typename Unit2::base_unit_1
                >{};
            }
            else
            {
                return unit_product<Unit1, Unit2>{};
            }
        }
        else
        if constexpr(Unit1::type == unit_type::product && Unit2::type == unit_type::exponentiation)
        {
            if constexpr(std::same_as<typename Unit1::base_unit_1, typename Unit2::base_unit>)
            {
                return unit_product<
                    unit_exponentiation<typename Unit2::base_unit, Unit2::exponent + 1>,
                    typename Unit2::base_unit_2
                >{};
            }
            else
            if constexpr(std::same_as<typename Unit1::base_unit_2, typename Unit2::base_unit>)
            {
                return unit_product<
                    unit_exponentiation<typename Unit2::base_unit, Unit2::exponent + 1>,
                    typename Unit2::base_unit_1
                >{};
            }
            else
            {
                return unit_product<Unit1, Unit2>{};
            }
        }
        else
        if constexpr(Unit1::type == unit_type::product && Unit2::type == unit_type::product)
        {
            if constexpr(
                std::same_as<typename Unit1::base_unit_1, typename Unit2::base_unit_1> &&
                std::same_as<typename Unit1::base_unit_2, typename Unit2::base_unit_2> ||
                std::same_as<typename Unit1::base_unit_1, typename Unit2::base_unit_2> &&
                std::same_as<typename Unit1::base_unit_2, typename Unit2::base_unit_1>
            )
            {
                return unit_product<
                    unit_exponentiation<typename Unit1::base_unit_1, 2>,
                    unit_exponentiation<typename Unit1::base_unit_2, 2>
                >{};
            }
            else
            {
                return unit_product<Unit1, Unit2>{};
            }
        }
    }

    namespace detail
    {

        template<int exponent, unit_c Unit>
        [[nodiscard]] consteval auto pow(Unit unit) noexcept
        {
            if constexpr(exponent == 0 || std::same_as<Unit, one>)
            {
                return _1;
            }
            else if constexpr(exponent == 1)
            {
                return unit;
            }
            else if constexpr(Unit::type == unit_type::exponentiation)
            {
                return unit_exponentiation<typename Unit::base_unit, Unit::exponent * exponent>{};
            }
            else
            {
                return unit_exponentiation<Unit, exponent>{};
            }
        }

    }

    template<unit_c auto unit, int exponent>
    inline constexpr unit_c auto pow_v = detail::pow<exponent>(unit);

    template <unit_c Unit1, unit_c Unit2>
    [[nodiscard]] consteval auto operator/(Unit1 unit_1, Unit2 unit_2) noexcept
    {
        return unit_1 * pow_v<unit_2, -1>;
    }

    template <unit_c Unit1, unit_c Unit2>
    [[nodiscard]] constexpr bool operator==(const Unit1& unit_1, const Unit2& unit_2) noexcept
    {
        return unit_1.exponents == unit_2.exponents
            && unit_1.factors   == unit_2.factors
            && unit_1.symbols   == unit_2.symbols;
    }

}


#endif //__ZOLLSTOCK_UNIT_ALGORITHMS_HPP__
