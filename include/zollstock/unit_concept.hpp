#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/unit_exponents.hpp>
#include <zollstock/unit_factors.hpp>
#include <zollstock/unit_symbols.hpp>

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
        { Candidate::type      } -> std::same_as<const unit_type     &>;
        { Candidate::exponents } -> std::same_as<const unit_exponents&>;
        { Candidate::factors   } -> std::same_as<const unit_factors  &>;
        { Candidate::symbols   } -> std::same_as<const unit_symbols  &>;
    };

    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return unit_1.exponents == unit_2.exponents;
    }

    template <unit_c Unit, int exponent_>
    struct unit_exponentiation
    {
        static constexpr unit_type type = unit_type::exponentiation;
        using base_unit = Unit;
        static constexpr int exponent = exponent_;

        static constexpr unit_exponents exponents = Unit::exponents * exponent;
        static constexpr unit_factors factors{ Unit::factors };
        static constexpr unit_symbols symbols{ Unit::symbols };
    };



    template<unit_c Unit1, unit_c Unit2>
    struct unit_product
    {
        static constexpr unit_type type = unit_type::product;
        using base_unit_1 = Unit1;
        using base_unit_2 = Unit2;

        static constexpr unit_exponents exponents = Unit1::exponents + Unit2::exponents;
        static constexpr unit_factors factors{ combined(Unit1::factors, Unit2::factors) };
        static constexpr unit_symbols symbols{ select_symbols(exponents, Unit1::symbols, Unit2::symbols) };
    };


}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
