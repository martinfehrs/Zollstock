#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/quantity_data.hpp>

#include <type_traits>
#include <concepts>


namespace zollstock
{

    enum class unit_type
    {
        basic,
        exponentiation,
        product
    };



    template <typename Candidate>
    concept unit_c = std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;

    template <typename Candidate>
    concept typed_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::type } -> std::same_as<const unit_type&>;
    };

    template <typename Candidate>
    concept length_member_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::length } -> std::same_as<const quantity_data&>;
    };

    template <typename Candidate>
    concept length_function_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::length() } -> std::same_as<quantity_data>;
    };

    template <typename Candidate>
    concept time_member_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::time } -> std::same_as<const quantity_data&>;
    };

    template <typename Candidate>
    concept time_function_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::time() } -> std::same_as<quantity_data>;
    };

    template <typename Candidate>
    concept angle_member_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::angle } -> std::same_as<const quantity_data&>;
    };

    template <typename Candidate>
    concept angle_function_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::angle() } -> std::same_as<quantity_data>;
    };

    template <typename Candidate>
    concept base_unit_c = unit_c<Candidate> && type_of(Candidate{}) == unit_type::basic;

    template <typename Candidate>
    concept raised_unit_c = unit_c<Candidate> && type_of(Candidate{}) == unit_type::exponentiation;

    template <typename Candidate>
    concept multiplied_unit_c = unit_c<Candidate> && type_of(Candidate{}) == unit_type::product;

    template <typename Candidate>
    concept homogeneous_unit_c = unit_c<Candidate> && type_of(Candidate{}) != unit_type::product;



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
    [[nodiscard]] consteval quantity_data length_of(Unit unit) noexcept
    {
        if constexpr(length_member_based_unit_c<Unit>)
        {
            return unit.length;
        }
        else if constexpr(length_function_based_unit_c<Unit>)
        {
            return unit.length();
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data time_of(Unit unit) noexcept
    {
        if constexpr(time_member_based_unit_c<Unit>)
        {
            return unit.time;
        }
        else if constexpr(time_function_based_unit_c<Unit>)
        {
            return unit.time();
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data angle_of(Unit unit) noexcept
    {
        if constexpr(angle_member_based_unit_c<Unit>)
        {
            return unit.angle;
        }
        else if constexpr(angle_function_based_unit_c<Unit>)
        {
            return unit.angle();
        }
        else
        {
            return {};
        }
    }



    template <quantity quantity_>
    [[nodiscard]] consteval quantity_data data_of(unit_c auto unit) noexcept
    {
        if constexpr(quantity_ == quantity::length)
        {
            return length_of(unit);
        }
        else if constexpr(quantity_ == quantity::time)
        {
            return time_of(unit);
        }
        else if constexpr(quantity_ == quantity::angle)
        {
            return angle_of(unit);
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
                (data_of<quantities>(unit_1).exponent ==
                 data_of<quantities>(unit_2).exponent)
            );
        }

    }

    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return detail::convertible_units_impl(unit_1, unit_2, make_quantity_sequence());
    }



    template <base_unit_c auto base_unit_, int exponent_>
    struct unit_exponentiation
    {
        static constexpr auto type = unit_type::exponentiation;
        static constexpr auto base_unit = base_unit_;
        static constexpr auto exponent = exponent_;

        static consteval auto length() noexcept
        {
            return pow(length_of(base_unit_), exponent_);
        }

        static consteval auto time() noexcept
        {
            return pow(time_of(base_unit_), exponent_);
        }

        static consteval auto angle() noexcept
        {
            return pow(angle_of(base_unit_), exponent_);
        }

    };


    template<homogeneous_unit_c auto... base_units>
    struct unit_product
    {
        static constexpr auto type = unit_type::product;
        static constexpr auto size = sizeof...(base_units);

        static consteval auto length() noexcept
        {
            return (... * length_of(base_units));
        }

        static consteval auto time() noexcept
        {
            return (... * time_of(base_units));
        }

        static consteval auto angle() noexcept
        {
            return (... *  angle_of(base_units));
        }
    };



    template <base_unit_c auto unit, int exponent_>
    inline constexpr auto unit_exponentiation_v = unit_exponentiation<unit, exponent_>{};

    template <homogeneous_unit_c auto... units>
    inline constexpr auto unit_product_v = unit_product<units...>{};

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
