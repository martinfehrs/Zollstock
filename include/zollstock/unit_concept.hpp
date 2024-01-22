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

    template <unit_c Unit, int exponent_>
    struct unit_exponentiation
    {
        static constexpr unit_type type = unit_type::exponentiation;
        using base_unit = Unit;
        static constexpr int exponent = exponent_;

        static constexpr quantity_exponents exponents = Unit::exponents * exponent;
        static constexpr quantity_factors factors{ Unit::factors };
        static constexpr quantity_symbols symbols{ Unit::symbols };
    };



    template<unit_c Unit1, unit_c Unit2>
    struct unit_product
    {
        static constexpr unit_type type = unit_type::product;
        using base_unit_1 = Unit1;
        using base_unit_2 = Unit2;

        static constexpr quantity_exponents exponents = Unit1::exponents + Unit2::exponents;
        static constexpr quantity_factors factors{ combined(Unit1::factors, Unit2::factors) };
        static constexpr quantity_symbols symbols{ select_symbols(exponents, Unit1::symbols, Unit2::symbols) };
    };


}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
