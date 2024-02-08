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

    enum class quantity
    {
        length,
        time,
        angle
    };

    template <quantity... quantities>
    struct quantity_sequence
    {
        using value_type = quantity;

        static constexpr std::size_t size() noexcept
        {
            return sizeof...(quantities);
        }
    };

    consteval auto make_quantity_sequence() noexcept
    {
        return quantity_sequence<quantity::length, quantity::time, quantity::angle>{};
    }

    consteval auto make_base_quantity_sequence() noexcept
    {
        return quantity_sequence<quantity::length, quantity::time>{};
    }

    consteval auto make_derived_quantity_sequence() noexcept
    {
        return quantity_sequence<quantity::angle>{};
    }


    struct quantity_data
    {
        int exponent;
        long double factor;
        unit_symbol symbol;

        [[nodiscard]] consteval bool operator==(const quantity_data&) const noexcept = default;

        [[nodiscard]] consteval quantity_data operator*(const quantity_data& that) const
        {
            return {
                this->exponent + that.exponent,
                this->factor != 0 ? this->factor : that.factor,
                this->select_symbol(that)
            };
        }

    private:

        [[nodiscard]] consteval unit_symbol select_symbol(const quantity_data& that) const
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

    [[nodiscard]] consteval quantity_data pow(const quantity_data& udat, int exponent) noexcept
    {
        return { udat.exponent * exponent, udat.factor, udat.symbol };
    }

    [[nodiscard]] consteval quantity_data operator/(
        const quantity_data& udat_1,const quantity_data& udat_2
    ) noexcept
    {
        return udat_1 * pow(udat_2, -1);
    }

    inline constexpr std::size_t base_quantity_count = 2;
    inline constexpr std::size_t derived_quantity_count = 1;
    inline constexpr std::size_t quantity_count = base_quantity_count + derived_quantity_count;



    enum class unit_type
    {
        basic,
        exponentiation,
        product
    };

    template <typename Candidate>
    concept unit_c = requires()
    {
        requires std::is_trivial_v<Candidate>;
        requires std::is_empty_v<Candidate>;
    };

    template <typename Candidate>
    concept typed_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::type } -> std::same_as<const unit_type&>;
    };

    template <typename Candidate>
    concept length_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::length } -> std::same_as<const quantity_data&>;
    };

    template <typename Candidate>
    concept time_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::time } -> std::same_as<const quantity_data&>;
    };

    template <typename Candidate>
    concept angle_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::angle } -> std::same_as<const quantity_data&>;
    };



    template <unit_c Unit>
    [[nodiscard]] consteval unit_type type_of(Unit unit) noexcept
    {
        if constexpr(typed_unit_c<Unit>)
        {
            return unit.type;
        }
        else
        {
            return unit_type::basic;
        }
    }



    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data unit_length(Unit unit) noexcept
    {
        if constexpr(length_based_unit_c<Unit>)
        {
            return unit.length;
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data unit_time(Unit unit) noexcept
    {
        if constexpr(time_based_unit_c<Unit>)
        {
            return unit.time;
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data unit_angle(Unit unit) noexcept
    {
        if constexpr(angle_based_unit_c<Unit>)
        {
            return unit.angle;
        }
        else
        {
            return {};
        }
    }



    template <quantity quantity_>
    [[nodiscard]] consteval quantity_data quantity_data_for(unit_c auto unit) noexcept
    {
        if constexpr(quantity_ == quantity::length)
        {
            return unit_length(unit);
        }
        else if constexpr(quantity_ == quantity::time)
        {
            return unit_time(unit);
        }
        else if constexpr(quantity_ == quantity::angle)
        {
            return unit_angle(unit);
        }
    }



    namespace detail
    {

        template <quantity... quantities>
        [[nodiscard]] consteval bool convertible_units_impl(
            unit_c auto unit_1, unit_c auto unit_2, quantity_sequence<quantities...>
        ) noexcept
        {
            return (
                ... &&
                (quantity_data_for<quantities>(unit_1).exponent ==
                 quantity_data_for<quantities>(unit_2).exponent)
            );
        }

    }

    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return detail::convertible_units_impl(unit_1, unit_2, make_quantity_sequence());
    }



    template <unit_c auto base_unit_, int exponent_>
    struct unit_exponentiation
    {
        static constexpr auto type = unit_type::exponentiation;
        static constexpr auto base_unit = base_unit_;
        static constexpr auto exponent = exponent_;

        static constexpr auto length = pow(unit_length(base_unit), exponent_);
        static constexpr auto time   = pow(unit_time  (base_unit), exponent_);
        static constexpr auto angle  = pow(unit_angle (base_unit), exponent_);
    };

    template<unit_c auto base_unit_1_, unit_c auto base_unit_2_>
    struct unit_product
    {
        static constexpr auto type = unit_type::product;
        static constexpr auto base_unit_1 = base_unit_1_;
        static constexpr auto base_unit_2 = base_unit_2_;

        static constexpr auto length = unit_length(base_unit_1) * unit_length(base_unit_2);
        static constexpr auto time   = unit_time  (base_unit_1) * unit_time  (base_unit_2);
        static constexpr auto angle  = unit_angle (base_unit_1) * unit_angle (base_unit_2);
    };



    template <unit_c auto unit, int exponent_>
    inline constexpr auto unit_exponentiation_v = unit_exponentiation<unit, exponent_>{};

    template <unit_c auto unit_1, unit_c auto unit_2>
    inline constexpr auto unit_product_v = unit_product<unit_1, unit_2>{};

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
