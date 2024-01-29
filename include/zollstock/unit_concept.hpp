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

        [[nodiscard]] consteval unit_data operator*(const unit_data& that) const
        {
            return {
                this->exponent + that.exponent,
                this->factor != 0 ? this->factor : that.factor,
                this->select_symbol(that)
            };
        }

    private:

        [[nodiscard]] consteval unit_symbol select_symbol(const unit_data& that) const
        {
            if (this->exponent + that.exponent == 0)
            {
                return ""_us;
            }
            else if (this->symbol.size() == 0)
            {
                return that.symbol;
            }
            else if (that.symbol.size() == 0)
            {
                return this->symbol;
            }
            else if (this->symbol == that.symbol)
            {
                return this->symbol;
            }
            else
            {
                throw "incompatible symbols";
            }
        }

    };

    [[nodiscard]] consteval unit_data pow(const unit_data& udat, int exponent) noexcept
    {
        return { udat.exponent * exponent, udat.factor, udat.symbol };
    }


    inline constexpr std::size_t base_unit_count = 2;
    inline constexpr std::size_t derived_unit_count = 1;
    inline constexpr std::size_t unit_count = base_unit_count + derived_unit_count;

    template <typename Candidate>
    concept unit_c = requires()
    {
        requires std::is_constructible_v<Candidate>;
        { Candidate::type   } -> std::same_as<const unit_type&>;
    };

    template <typename Candidate>
    concept length_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::length } -> std::same_as<const unit_data&>;
    };

    template <typename Candidate>
    concept time_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::time } -> std::same_as<const unit_data&>;
    };

    template <typename Candidate>
    concept angle_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::angle } -> std::same_as<const unit_data&>;
    };

    template <std::size_t pos, unit_c Unit> requires(pos < unit_count)
    [[nodiscard]] constexpr unit_data get(Unit) noexcept
    {
        if constexpr(pos == 0 && length_based_unit_c<Unit>)
        {
            return Unit::length;
        }
        else if constexpr(pos == 1 && time_based_unit_c<Unit>)
        {
            return Unit::time;
        }
        else if constexpr(pos == 2 && angle_based_unit_c<Unit>)
        {
            return Unit::angle;
        }
        else
        {
            return {};
        }
    }


    template <unit_c Unit>
    [[nodiscard]] unit_data unit_length(Unit) noexcept
    {
        if constexpr(length_based_unit_c<Unit>)
        {
            return Unit::length;
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] unit_data unit_time(Unit) noexcept
    {
        if constexpr(time_based_unit_c<Unit>)
        {
            return Unit::time;
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] unit_data unit_angle(Unit) noexcept
    {
        if constexpr(time_based_unit_c<Unit>)
        {
            return Unit::angle;
        }
        else
        {
            return {};
        }
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



    template <unit_c Unit, int exponent_>
    struct unit_exponentiation
    {
        static constexpr unit_type type = unit_type::exponentiation;
        using base_unit = Unit;
        static constexpr int exponent = exponent_;

        static constexpr unit_data length = pow(Unit::length, exponent_);
        static constexpr unit_data time   = pow(Unit::time  , exponent_);
        static constexpr unit_data angle  = pow(Unit::time  , exponent_);
    };

    template<unit_c Unit1, unit_c Unit2>
    struct unit_product
    {
        static constexpr unit_type type = unit_type::product;
        using base_unit_1 = Unit1;
        using base_unit_2 = Unit2;

        static constexpr unit_data length = Unit1::length * Unit2::length;
        static constexpr unit_data time   = Unit1::time   * Unit2::time  ;
        static constexpr unit_data angle  = Unit1::angle  * Unit2::angle ;

    };

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
