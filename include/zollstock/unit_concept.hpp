#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include "unit_exponents.hpp"
#include "unit_factors.hpp"
#include "unit_symbols.hpp"

#include <cassert>
#include <cmath>
#include <sstream>
#include <type_traits>
#include <string>
#include <string_view>


namespace zollstock
{

    template <typename Candidate, typename = void>
    inline constexpr bool has_exponents_v = false;

    template <typename Candidate>
    inline constexpr bool has_exponents_v<
        Candidate,  
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::exponents)>, unit_exponents>>
    > = true;


    template <typename Candidate, typename = void>
    inline constexpr bool has_factors_v = false;

    template <typename Candidate>
    inline constexpr bool has_factors_v<
        Candidate,
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::factors)>, unit_factors>>
    > = true;


    template <typename Candidate, typename = void>
    inline constexpr bool has_symbols_v = false;

    template <typename Candidate>
    inline constexpr bool has_symbols_v<
        Candidate,
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::symbols)>, unit_symbols>>
    > = true;


    template <typename Candidate>
    inline constexpr bool is_unit_v = std::is_constructible_v<Candidate>
                                    && has_exponents_v<Candidate>
                                    && has_factors_v<Candidate>
                                    && has_symbols_v<Candidate>;


    template <typename Unit1, typename Unit2, typename IndexSequence, typename = void>
    struct convertible_units_impl;

    template <
        typename Unit1,
        typename Unit2,
        template <typename, std::size_t...> typename IndexSequence,
        std::size_t... indices
    >
    struct convertible_units_impl<
        Unit1,
        Unit2,
        IndexSequence<std::size_t, indices...>,
        std::enable_if_t<is_unit_v<Unit1> &&  is_unit_v<Unit2>>
    >
        : std::bool_constant<(true && ... && (get<indices>(Unit1::exponents) == get<indices>(Unit2::exponents)))>
    {};

    template <typename Unit1, typename Unit2>
    inline constexpr bool convertible_units_v = convertible_units_impl<Unit1, Unit2, make_base_dimension_index_sequence>::value;


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
    [[nodiscard]] std::basic_string<Char> to_basic_string_impl(const Unit& unit, std::index_sequence<indices...>)
    {
        return basic_concatenator<Char>{ '*' }(unit_entry_to_string<indices, Char>(unit)...);
    }

    template <typename Char, typename Unit>
    [[nodiscard]] std::basic_string<Char> to_basic_string(const Unit& unit)
    {
        return basic_concatenator<Char>{ "*" }(
            to_basic_string_impl<Char>(unit, make_derived_dimension_index_sequence{}),
            to_basic_string_impl<Char>(unit, make_base_dimension_index_sequence{})
        );
    }

    template<typename Unit1, typename Unit2> 
    struct unit_product
    {
        static constexpr unit_exponents exponents = Unit1::exponents + Unit2::exponents;
        static constexpr unit_factors factors{ Unit1::factors };
        static constexpr unit_symbols symbols{ select_symbols(exponents, Unit1::symbols, Unit2::symbols) }; 
    };        

    template<typename Unit1, typename Unit2>
    struct unit_division
    {
        static constexpr unit_exponents exponents = Unit1::exponents - Unit2::exponents;
        static constexpr unit_factors factors{ combined(Unit1::factors, Unit2::factors) };
        static constexpr unit_symbols symbols{ select_symbols(exponents, Unit1::symbols, Unit2::symbols) };
    };


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

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__