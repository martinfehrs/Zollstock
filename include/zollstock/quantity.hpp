#ifndef __ZOLLSTOCK_QUANTITY_HPP__
#define __ZOLLSTOCK_QUANTITY_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/number_utilities.hpp>

#include <concepts>


namespace zollstock
{

    template <unit_c auto this_unit, number_c ThisValue = double>
    class quantity
    {

        using value_type = ThisValue;
        using unit_type = decltype(this_unit);
        using this_type = quantity<this_unit, ThisValue>;

    public:

        constexpr quantity() noexcept
            : value_{}
        {}

        template <number_c ThatValue>
        explicit constexpr quantity(
            ThatValue value
        ) noexcept(lossless_convertible_v<ThatValue, ThisValue>)
            : value_{ narrow<ThisValue>(value) }
        {}

        template <number_c ThatValue>
        constexpr quantity(
            quantity<this_unit, ThatValue> that
        ) noexcept(lossless_convertible_v<ThatValue, ThisValue>)
            : quantity{ that.cvalue() }
        { }

        [[nodiscard]] constexpr value_type& value() noexcept
        {
            return this->value_;
        }

        [[nodiscard]] constexpr const value_type& value() const noexcept
        {
            return this->value_;
        }

        [[nodiscard]] constexpr const value_type& cvalue() const noexcept
        {
            return this->value_;
        }

        [[nodiscard]] static consteval const unit_type& unit() noexcept
        {
            return this_unit;
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator==(
            const quantity<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_equal(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator!=(
            const quantity<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_not_equal(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator<(
            const quantity<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_less(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator>(
            const quantity<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_greater(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator<=(
            const quantity<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_less_equal(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator>=(
            const quantity<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_greater_equal(this->value_, that.cvalue());
        }

        [[nodiscard]] constexpr this_type operator-() const noexcept
            requires(std::is_signed_v<ThisValue>)
        {
            return this_type{ -this->value_ };
        }

        template <unit_c auto that_unit> requires(convertible_units(this_unit, that_unit))
        [[nodiscard]] constexpr quantity<that_unit, value_type> as() const noexcept
        {
            return this->as_impl<that_unit>(make_unit_index_sequence{});
        }

        template <unit_c auto that_unit> requires(convertible_units(this_unit, that_unit))
        [[nodiscard]] constexpr operator quantity<that_unit, value_type>() const noexcept
        {
            return this->as<that_unit>();
        }

        constexpr this_type& operator+=(this_type that) noexcept
        {
            this->value_ += that.value_;

            return *this;
        }

        constexpr this_type& operator-=(this_type that) noexcept
        {
            this->value_ += that.value_;

            return *this;
        }

        template <unit_c ThatUnit>
        [[nodiscard]] consteval auto operator*(ThatUnit) && noexcept
        {
            return quantity<this_unit * ThatUnit{}, value_type>{ this->value_ };
        }

        template <unit_c ThatUnit>
        [[nodiscard]] consteval auto operator/(ThatUnit) && noexcept
        {
            return quantity<this_unit / ThatUnit{}, value_type>{ this->value_ };
        }

    private:

        template <unit_c auto that_unit, std::size_t pos>
        [[nodiscard]] constexpr value_type dimension_factor() const noexcept
        {
            constexpr auto this_exponent = get<pos>(this_unit.exponents);
            constexpr auto that_exponent = get<pos>(that_unit.exponents);

            if constexpr(this_exponent != 0 && that_exponent != 0)
            {
                return std::pow(get<pos>(this_unit.factors), this_exponent) /
                       std::pow(get<pos>(that_unit.factors), that_exponent);
            }
            else
            {
                return value_type{ 1.0L };
            }
        }

        template <unit_c auto that_unit, std::size_t... indices>
        [[nodiscard]] constexpr quantity<that_unit, value_type> as_impl(
            std::index_sequence<indices...>
        ) const noexcept
        {
            return { (this->value_ * ... * this->dimension_factor<that_unit, indices>()) };
        }

        value_type value_;

    };



    template <unit_c auto unit = _1>
    using int_t = quantity<unit, int>;

    template <unit_c auto unit = _1>
    using unsigned_int_t = quantity<unit, unsigned int>;

    template <unit_c auto unit = _1>
    using unsigned_t = quantity<unit, unsigned>;


    template <unit_c auto unit = _1>
    using short_int_t = quantity<unit, short int>;

    template <unit_c auto unit = _1>
    using short_t= quantity<unit, short>;

    template <unit_c auto unit = _1>
    using unsigned_short_int_t= quantity<unit, unsigned short int>;

    template <unit_c auto unit = _1>
    using unsigned_short_t= quantity<unit, unsigned short>;


    template <unit_c auto unit = _1>
    using long_int_t = quantity<unit, long int>;

    template <unit_c auto unit = _1>
    using long_t= quantity<unit, long>;

    template <unit_c auto unit = _1>
    using unsigned_long_int_t= quantity<unit, unsigned long int>;

    template <unit_c auto unit = _1>
    using unsigned_long_t= quantity<unit, unsigned long>;


    template <unit_c auto unit = _1>
    using long_long_int_t = quantity<unit, long long int>;

    template <unit_c auto unit = _1>
    using long_long_t= quantity<unit, long long>;

    template <unit_c auto unit = _1>
    using unsigned_long_long_int_t= quantity<unit, unsigned long long int>;

    template <unit_c auto unit = _1>
    using unsigned_long_long_t= quantity<unit, unsigned long long>;


    template <unit_c auto unit = _1>
    using float_t = quantity<unit, float>;

    template <unit_c auto unit = _1>
    using double_t = quantity<unit, double>;

    template <unit_c auto unit = _1>
    using long_double_t = quantity<unit, long double>;



    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto make_scalar(Value value) noexcept
    {
        return quantity<unit, Value>{ value };
    }


    template <unit_c auto unit, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator+(
        quantity<unit, Value1> summand_1, quantity<unit, Value2> summand_2) noexcept
    {
        return make_scalar<unit>(summand_1.cvalue() + summand_2.cvalue());
    }

    template <unit_c auto unit, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator-(
        quantity<unit, Value1> minuend, quantity<unit, Value2> subtrahend
    ) noexcept
    {
        return make_scalar<unit>(minuend.cvalue() - subtrahend.cvalue());
    }

    template <unit_c Unit>
    [[nodiscard]] consteval auto operator*(number_c auto&& factor, Unit) noexcept
    {
        return make_scalar<Unit{}>(factor);
    }

    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator*(
        quantity<unit, Value> factor_1, number_c auto factor_2
    ) noexcept
    {
        return make_scalar<unit>(factor_1.cvalue() * factor_2);
    }

    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator*(
        number_c auto factor_1, quantity<unit, Value> factor_2
    ) noexcept
    {
        return make_scalar<unit>(factor_1 * factor_2.cvalue());
    }

    template <unit_c auto unit_1, unit_c auto unit_2, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator*(
        quantity<unit_1, Value1> factor_1, quantity<unit_2, Value2> factor_2
    ) noexcept
    {
        return make_scalar<unit_1 * unit_2>(factor_1.cvalue() * factor_2.cvalue());
    }

    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator/(
        quantity<unit, Value> dividend, number_c auto divisor
    ) noexcept
    {
        return make_scalar<unit>(dividend.cvalue() / divisor);
    }

    template <unit_c auto unit_1, unit_c auto unit_2, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator/(
        quantity<unit_1, Value1> dividend, quantity<unit_2, Value2> divisor
    ) noexcept
    {
        return make_scalar<unit_1 / unit_2>(dividend.cvalue() / divisor.cvalue());
    }


    template <typename Char, unit_c auto unit, number_c Value>
    std::basic_ostream<Char>& operator<<(
        std::basic_ostream<Char>& os, quantity<unit, Value> quantity
    )
    {
        const std::basic_string<Char> unit_representation = to_basic_string<Char>(unit);

        const std::size_t unit_width = unit_representation.size();
        const std::size_t unit_width_including_space = unit_width + 1U;

        if (
            unit_width > 0 &&
            os.width() >= static_cast<std::streamsize>(unit_width_including_space)
        )
            os.width(os.width() - unit_width_including_space);

        os << quantity.cvalue();

        if(unit_width > 0)
            os << " " << unit;

        return os;
    }

}


#endif //__ZOLLSTOCK_QUANTITY_HPP__
