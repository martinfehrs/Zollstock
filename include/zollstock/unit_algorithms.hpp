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

        template <quantity quantity_, typename Char>
        [[nodiscard]] std::basic_string<Char> quantity_entry_to_string(unit_c auto unit)
        {
            std::basic_string<Char> unit_representation;

            constexpr quantity_data data = data_of<quantity_>(unit);

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

        template <typename Char, quantity... quantities>
        [[nodiscard]] std::basic_string<Char> to_basic_string_impl(
            unit_c auto unit, quantity_sequence<quantities...>
        )
        {
            return detail::basic_concatenator<Char>{ '*' }(
                detail::quantity_entry_to_string<quantities, Char>(unit)...
            );
        }

    }

    template <typename Char>
    [[nodiscard]] std::basic_string<Char> to_basic_string(unit_c auto unit)
    {
        return detail::basic_concatenator<Char>{ "*" }(
            detail::to_basic_string_impl<Char>(unit, make_derived_quantity_sequence()),
            detail::to_basic_string_impl<Char>(unit, make_base_quantity_sequence())
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

    [[nodiscard]] consteval auto operator*(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        if constexpr(
            type_of(unit_1) == unit_type::exponentiation &&
            type_of(unit_2) == unit_type::exponentiation
        )
        {
            if constexpr(unit_1.base_unit == unit_2.base_unit)
            {
                return unit_exponentiation_v<unit_1.base_unit, unit_1.exponent + unit_2.exponent>;
            }
            else
            {
                return unit_product_v<unit_1, unit_2>;
            }
        }
        else
        if constexpr(
            type_of(unit_1) == unit_type::exponentiation &&
            type_of(unit_2) == unit_type::basic
        )
        {
            if constexpr(unit_1.base_unit == unit_2)
            {
                return unit_exponentiation_v<unit_1.base_unit, unit_1.exponent + 1>;
            }
            else
            {
                return unit_product_v<unit_1, unit_2>;
            }
        }
        else
        if constexpr(
            type_of(unit_1) == unit_type::basic &&
            type_of(unit_2) == unit_type::exponentiation
        )
        {
            if constexpr(unit_2.base_unit == unit_1)
            {
                return unit_exponentiation_v<unit_2.base_unit, unit_2.exponent + 1>;
            }
            else
            {
                return unit_product_v<unit_1, unit_2>;
            }
        }
        else
        if constexpr(
            type_of(unit_1) == unit_type::exponentiation &&
            type_of(unit_2) == unit_type::product
        )
        {
            if constexpr(unit_1.base_unit == unit_2.base_unit_1)
            {
                return unit_product_v<
                    unit_exponentiation_v<unit_1.base_unit, unit_1.exponent + 1>,
                    unit_2.base_unit_2
                >;
            }
            else
            if constexpr(unit_1.base_unit == unit_2.base_unit_2)
            {
                return unit_product_v<
                    unit_exponentiation_v<unit_1.base_unit, unit_1.exponent + 1>,
                    unit_2.base_unit_1
                >;
            }
            else
            {
                return unit_product_v<unit_1, unit_2>;
            }
        }
        else
        if constexpr(
            type_of(unit_1) == unit_type::product &&
            type_of(unit_2) == unit_type::exponentiation
        )
        {
            if constexpr(unit_1.base_unit_1 == unit_2.base_unit)
            {
                return unit_product_v<
                    unit_exponentiation_v<unit_2.base_unit, unit_2.exponent + 1>,
                    unit_2.base_unit_2
                >;
            }
            else
            if constexpr(unit_1.base_unit_2, unit_2.base_unit)
            {
                return unit_product_v<
                    unit_exponentiation_v<unit_2.base_unit, unit_2.exponent + 1>,
                    unit_2.base_unit_1
                >;
            }
            else
            {
                return unit_product_v<unit_1, unit_2>;
            }
        }
        if constexpr(type_of(unit_1) == unit_type::product && type_of(unit_2) == unit_type::product)
        {
            if constexpr(
                unit_1.base_unit_1 == unit_2.base_unit_1 &&
                unit_1.base_unit_2 == unit_2.base_unit_2 ||
                unit_1.base_unit_1 == unit_2.base_unit_2 &&
                unit_1.base_unit_2 == unit_2.base_unit_1
            )
            {
                return unit_product_v<
                    unit_exponentiation_v<unit_1.base_unit_1, 2>,
                    unit_exponentiation_v<unit_1.base_unit_2, 2>
                >;
            }
            else
            {
                return unit_product_v<unit_1, unit_2>;
            }
        }

        return unit_product_v<unit_1, unit_2>;
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
            else if constexpr(type_of(unit) == unit_type::exponentiation)
            {
                return unit_exponentiation_v<unit.base_unit, unit.exponent * exponent>;
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



    namespace detail
    {

        template <quantity... quantities>
        [[nodiscard]] consteval bool equal(
            unit_c auto unit_1, unit_c auto unit_2, quantity_sequence<quantities...>
        ) noexcept
        {
            return (
                ... &&
                (data_of<quantities>(unit_1) == data_of<quantities>(unit_2))
            );
        }

    }

    [[nodiscard]] consteval bool operator==(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return detail::equal(unit_1, unit_2, make_quantity_sequence());
    }

    [[nodiscard]] consteval bool operator!=(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return !detail::equal(unit_1, unit_2, make_quantity_sequence());
    }

}


#endif //__ZOLLSTOCK_UNIT_ALGORITHMS_HPP__
