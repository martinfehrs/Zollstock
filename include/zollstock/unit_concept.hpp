#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/unit_symbol.hpp>

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

    struct unit_data
    {
        int exponent;
        long double factor;
        unit_symbol symbol;

        [[nodiscard]] constexpr bool operator==(const unit_data&) const noexcept = default;
    };

    inline constexpr std::size_t base_unit_count = 2;
    inline constexpr std::size_t derived_unit_count = 1;
    inline constexpr std::size_t unit_count = base_unit_count + derived_unit_count;

    template <typename Candidate>
    concept unit_c = requires()
    {
        requires std::is_constructible_v<Candidate>;
        { Candidate::type   } -> std::same_as<const unit_type&>;
        { Candidate::length } -> std::same_as<const unit_data&>;
        { Candidate::time   } -> std::same_as<const unit_data&>;
        { Candidate::angle  } -> std::same_as<const unit_data&>;
    };



    template <std::size_t pos, unit_c Unit> requires(pos < unit_count)
    [[nodiscard]] constexpr const auto& get(const Unit& data)
    {
        if constexpr(pos == 0)
        {
            return data.length;
        }
        else if constexpr(pos == 1)
        {
            return data.time;
        }
        else if constexpr(pos == 2)
        {
            return data.angle;
        }
    }

    template<std::size_t pos, unit_c Unit>
    struct unit_data_element
    {
        using type = std::remove_cvref_t<decltype(get<pos>(std::declval<Unit>()))>;
    };

    template<std::size_t pos, unit_c Unit>
    using unit_data_element_t = typename unit_data_element<pos, Unit>::type;


    template <std::size_t pos, unit_c Unit> requires(pos < unit_count)
    [[nodiscard]] constexpr auto& get(Unit& unit) noexcept
    {
        return const_cast<unit_data_element_t<pos, Unit>&>(
            get<pos>(std::as_const(unit))
        );
    }

    template <typename IndexSequence, std::size_t offset>
    struct shift_right;

    template <std::size_t... indices, std::size_t offset>
    struct shift_right<std::index_sequence<indices...>, offset>
    {
        using type = std::index_sequence<(indices + offset)...>;
    };

    template <typename IndexSequence, std::size_t offset>
    using shift_right_t = typename shift_right<IndexSequence, offset>::type;


    template <std::size_t count, std::size_t first = 0U>
    using make_index_sequence = shift_right_t<std::make_index_sequence<count>, first>;

    using make_base_unit_index_sequence = make_index_sequence<base_unit_count>;

    using make_derived_unit_index_sequence = make_index_sequence<
        derived_unit_count, base_unit_count
    >;

    using make_unit_index_sequence = make_index_sequence<unit_count>;


    namespace detail
    {

        template <unit_c Unit1, unit_c Unit2, std::size_t... indices>
        [[nodiscard]] consteval bool convertible_units_impl(
            const Unit1& unit_1, const Unit2& unit_2, std::index_sequence<indices...>
        ) noexcept
        {
            return (... && (get<indices>(unit_1).exponent == get<indices>(unit_2).exponent));
        }

    }

    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return detail::convertible_units_impl(unit_1, unit_2, make_unit_index_sequence{});
    }


    [[nodiscard]] consteval unit_symbol select_symbol(
        const unit_data& unit_data_1,
        const unit_data& unit_data_2
    )
    {
        if (unit_data_1.exponent + unit_data_2.exponent == 0)
        {
            return ""_us;
        }
        else if (unit_data_1.symbol.size() == 0)
        {
            return unit_data_2.symbol;
        }
        else if (unit_data_2.symbol.size() == 0)
        {
            return unit_data_1.symbol;
        }
        else if (unit_data_1.symbol == unit_data_2.symbol)
        {
            return unit_data_1.symbol;
        }
        else
        {
            throw "incompatible symbols";
        }
    }



    template <unit_c Unit, int exponent_>
    struct unit_exponentiation
    {
        static constexpr unit_type type = unit_type::exponentiation;
        using base_unit = Unit;
        static constexpr int exponent = exponent_;

        static constexpr unit_data length{ Unit::length.exponent * exponent, Unit::length.factor, Unit::length.symbol };
        static constexpr unit_data time  { Unit::time  .exponent * exponent, Unit::time  .factor, Unit::length.symbol };
        static constexpr unit_data angle { Unit::angle .exponent * exponent, Unit::angle .factor, Unit::length.symbol };
    };



    template<unit_c Unit1, unit_c Unit2>
    struct unit_product
    {
        static constexpr unit_type type = unit_type::product;
        using base_unit_1 = Unit1;
        using base_unit_2 = Unit2;

        static constexpr unit_data length{ Unit1::length.exponent + Unit2::length.exponent, Unit1::length.factor != 0 ? Unit1::length.factor : Unit2::length.factor, select_symbol(Unit1::length, Unit2::length) };
        static constexpr unit_data time  { Unit1::time  .exponent + Unit2::time  .exponent, Unit1::time  .factor != 0 ? Unit1::time  .factor : Unit2::time  .factor, select_symbol(Unit1::time  , Unit2::time  ) };
        static constexpr unit_data angle { Unit1::angle .exponent + Unit2::angle .exponent, Unit1::angle .factor != 0 ? Unit1::angle .factor : Unit2::angle .factor, select_symbol(Unit1::angle , Unit2::angle ) };

    };

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
