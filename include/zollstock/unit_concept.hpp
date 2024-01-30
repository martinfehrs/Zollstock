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

        [[nodiscard]] consteval bool operator==(const unit_data&) const noexcept = default;

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
        { Candidate::type } -> std::same_as<const unit_type&>;
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



    template <unit_c Unit>
    [[nodiscard]] consteval bool length_based_unit(Unit) noexcept
    {
        return length_based_unit_c<Unit>;
    }

    template <unit_c Unit>
    [[nodiscard]] consteval bool time_based_unit(Unit) noexcept
    {
        return time_based_unit_c<Unit>;
    }

    template <unit_c Unit>
    [[nodiscard]] consteval bool angle_based_unit(Unit) noexcept
    {
        return angle_based_unit_c<Unit>;
    }



    [[nodiscard]] consteval unit_data unit_length(unit_c auto unit) noexcept
    {
        if constexpr(length_based_unit(unit))
        {
            return unit.length;
        }
        else
        {
            return {};
        }
    }

    [[nodiscard]] consteval unit_data unit_time(unit_c auto unit) noexcept
    {
        if constexpr(time_based_unit(unit))
        {
            return unit.time;
        }
        else
        {
            return {};
        }
    }

    [[nodiscard]] consteval unit_data unit_angle(unit_c auto unit) noexcept
    {
        if constexpr(angle_based_unit(unit))
        {
            return unit.angle;
        }
        else
        {
            return {};
        }
    }



    template <std::size_t pos> requires(pos < unit_count)
    [[nodiscard]] consteval unit_data unit_data_at(unit_c auto unit) noexcept
    {
        if constexpr(pos == 0)
        {
            return unit_length(unit);
        }
        else if constexpr(pos == 1)
        {
            return unit_time(unit);
        }
        else if constexpr(pos == 2)
        {
            return unit_angle(unit);
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

        template <std::size_t... indices>
        [[nodiscard]] consteval bool convertible_units_impl(
            unit_c auto unit_1, unit_c auto unit_2, std::index_sequence<indices...>
        ) noexcept
        {
            return (
                ... &&
                (unit_data_at<indices>(unit_1).exponent == unit_data_at<indices>(unit_2).exponent)
            );
        }

    }

    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return detail::convertible_units_impl(unit_1, unit_2, make_unit_index_sequence{});
    }



    template <unit_c auto unit, int exponent_>
    struct unit_exponentiation
    {
        static constexpr auto type = unit_type::exponentiation;
        static constexpr auto base_unit = unit;
        static constexpr auto exponent = exponent_;

        static constexpr auto length = pow(unit_length(unit), exponent_);
        static constexpr auto time   = pow(unit_time  (unit), exponent_);
        static constexpr auto angle  = pow(unit_angle (unit), exponent_);
    };

    template <unit_c auto unit, int exponent_>
    inline constexpr auto unit_exponentiation_v = unit_exponentiation<unit, exponent_>{};



    template<unit_c auto unit_1, unit_c auto unit_2>
    struct unit_product
    {
        static constexpr auto type = unit_type::product;
        static constexpr auto base_unit_1 = unit_1;
        static constexpr auto base_unit_2 = unit_2;

        static constexpr auto length = unit_length(unit_1) * unit_length(unit_2);
        static constexpr auto time   = unit_time  (unit_1) * unit_time  (unit_2);
        static constexpr auto angle  = unit_angle (unit_1) * unit_angle (unit_2);
    };

    template <unit_c auto unit, int exponent_>
    inline constexpr auto unit_product_v = unit_product<unit, exponent_>{};

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
