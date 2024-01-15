#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/quantity_exponents.hpp>
#include <zollstock/quantity_factors.hpp>
#include <zollstock/quantity_symbols.hpp>

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
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::exponents)>, quantity_exponents>>
    > = true;


    template <typename Candidate, typename = void>
    inline constexpr bool has_factors_v = false;

    template <typename Candidate>
    inline constexpr bool has_factors_v<
        Candidate,
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::factors)>, quantity_factors>>
    > = true;


    template <typename Candidate, typename = void>
    inline constexpr bool has_symbols_v = false;

    template <typename Candidate>
    inline constexpr bool has_symbols_v<
        Candidate,
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::symbols)>, quantity_symbols>>
    > = true;


    template <typename Candidate>
    inline constexpr bool is_unit_v = std::is_constructible_v<Candidate>
                                   && has_exponents_v<Candidate>
                                   && has_factors_v<Candidate>
                                   && has_symbols_v<Candidate>;

    namespace detail
    {

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

    }

    template <typename Unit1, typename Unit2>
    inline constexpr bool convertible_units_v = detail::convertible_units_impl<Unit1, Unit2, make_base_quantity_index_sequence>::value;


    template <typename Unit, int exponent>
    struct unit_exponentiation
    {
        static constexpr quantity_exponents exponents = Unit::exponents * exponent;
        static constexpr quantity_factors factors{ Unit::factors };
        static constexpr quantity_symbols symbols{ Unit::symbols };
    };

    template <typename Unit, int exponent>
    struct raise_unit
    {
        using type = unit_exponentiation<Unit, exponent>;
    };

    template <typename Unit, int exponent>
    using raise_unit_v = typename raise_unit<Unit, exponent>::type;


    template<typename Unit1, typename Unit2>
    struct unit_product
    {
        static constexpr quantity_exponents exponents = Unit1::exponents + Unit2::exponents;
        static constexpr quantity_factors factors{ combined(Unit1::factors, Unit2::factors) };
        static constexpr quantity_symbols symbols{ select_symbols(exponents, Unit1::symbols, Unit2::symbols) };
    };

    template <typename Unit1, typename Unit2>
    struct multiply_units
    {
        using type = unit_product<Unit1, Unit2>;
    };

    template <typename Unit1, typename Unit2>
    using multiply_units_v = typename multiply_units<Unit1, Unit2>::type;


    template<typename Unit1, typename Unit2>
    using unit_fraction = multiply_units_v<Unit1, raise_unit_v<Unit2, -1>>;

    template <typename Unit1, typename Unit2>
    struct divide_units
    {
        using type = unit_fraction<Unit1, Unit2>;
    };

    template <typename Unit1, typename Unit2>
    using divide_units_v = typename divide_units<Unit1, Unit2>::type;

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
