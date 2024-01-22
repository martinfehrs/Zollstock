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

    enum class unit_type
    {
        basic,
        exponentiation,
        product
    };

    template <typename Candidate>
    concept unit_c = requires()
    {
        requires std::is_constructible_v<Candidate>;
        { Candidate::type      } -> std::same_as<const unit_type         &>;
        { Candidate::exponents } -> std::same_as<const quantity_exponents&>;
        { Candidate::factors   } -> std::same_as<const quantity_factors  &>;
        { Candidate::symbols   } -> std::same_as<const quantity_symbols  &>;
    };

    template <typename Unit1, typename Unit2>
    concept convertible_units_c = unit_c<Unit1>
                               && unit_c<Unit2>
                               && Unit1::exponents == Unit2::exponents;

    template <unit_c Unit, int exponent>
    struct unit_exponentiation
    {
        static constexpr unit_type type = unit_type::exponentiation;
        static constexpr quantity_exponents exponents = Unit::exponents * exponent;
        static constexpr quantity_factors factors{ Unit::factors };
        static constexpr quantity_symbols symbols{ Unit::symbols };
    };

    template <unit_c Unit, int exponent>
    struct raise_unit
    {
        using type = unit_exponentiation<Unit, exponent>;
    };

    template <unit_c Unit>
    struct raise_unit<Unit, 1>
    {
        using type = Unit;
    };

    template <unit_c Unit, int exponent_1, int exponent_2>
    struct raise_unit<unit_exponentiation<Unit, exponent_1>, exponent_2>
    {
        using type = unit_exponentiation<Unit, exponent_1 * exponent_2>;
    };

    template <unit_c Unit, int exponent>
    using raise_unit_v = typename raise_unit<Unit, exponent>::type;


    template<unit_c Unit1, unit_c Unit2>
    struct unit_product
    {
        static constexpr unit_type type = unit_type::product;
        static constexpr quantity_exponents exponents = Unit1::exponents + Unit2::exponents;
        static constexpr quantity_factors factors{ combined(Unit1::factors, Unit2::factors) };
        static constexpr quantity_symbols symbols{ select_symbols(exponents, Unit1::symbols, Unit2::symbols) };
    };

    template <unit_c Unit1, unit_c Unit2>
    struct multiply_units
    {
        using type = unit_product<Unit1, Unit2>;
    };

    template <unit_c Unit>
    struct multiply_units<Unit, Unit>
    {
        using type = raise_unit_v<Unit, 2>;
    };

    template <unit_c Unit, int exponent>
    struct multiply_units<Unit, unit_exponentiation<Unit, exponent>>
    {
        using type = raise_unit_v<Unit, exponent + 1>;
    };

    template <unit_c Unit, int exponent>
    struct multiply_units<unit_exponentiation<Unit, exponent>, Unit>
    {
        using type = raise_unit_v<Unit, exponent + 1>;
    };

    template <unit_c Unit, int exponent_1, int exponent_2>
    struct multiply_units<unit_exponentiation<Unit, exponent_1>, unit_exponentiation<Unit, exponent_2>>
    {
        using type = raise_unit_v<Unit, exponent_1 + exponent_2>;
    };

    template <unit_c Unit1, unit_c Unit2>
    using multiply_units_v = typename multiply_units<Unit1, Unit2>::type;


    template<unit_c Unit1, unit_c Unit2>
    using unit_fraction = multiply_units_v<Unit1, raise_unit_v<Unit2, -1>>;

    template <unit_c Unit1, unit_c Unit2>
    struct divide_units
    {
        using type = unit_fraction<Unit1, Unit2>;
    };

    template <unit_c Unit1, unit_c Unit2>
    using divide_units_v = typename divide_units<Unit1, Unit2>::type;

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
