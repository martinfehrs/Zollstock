#ifndef __ZOLLSTOCK_SCALAR_HPP__
#define __ZOLLSTOCK_SCALAR_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/number_utilities.hpp>
#include <zollstock/definition_helpers.hpp>

#include <cmath>


namespace zollstock
{

    template <unit_c auto this_unit, number_c ThisValue = double>
    class scalar
    {

        using this_type = scalar<this_unit, ThisValue>;

    public:

        using value_type = ThisValue;
        using unit_type = std::remove_const_t<decltype(this_unit)>;


        constexpr scalar() noexcept
            : value_{}
        {}

        template <number_c ThatValue>
        explicit constexpr scalar(
            ThatValue value
        ) noexcept(lossless_convertible_v<ThatValue, ThisValue>)
            : value_{ narrow<ThisValue>(value) }
        {}

        template <number_c ThatValue>
        constexpr scalar(
            scalar<this_unit, ThatValue> that
        ) noexcept(lossless_convertible_v<ThatValue, ThisValue>)
            : scalar{ that.cvalue() }
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
            const scalar<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_equal(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator!=(
            const scalar<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_not_equal(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator<(
            const scalar<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_less(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator>(
            const scalar<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_greater(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator<=(
            const scalar<this_unit, ThatValue>& that
        ) const noexcept
        {
            return cmp_less_equal(this->value_, that.cvalue());
        }

        template <number_c ThatValue>
        [[nodiscard]] constexpr bool operator>=(
            const scalar<this_unit, ThatValue>& that
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
        [[nodiscard]] constexpr scalar<that_unit, value_type> as() const noexcept
        {
            return this->as_impl<that_unit>(make_quantity_sequence());
        }

        template <unit_c auto that_unit> requires(convertible_units(this_unit, that_unit))
        [[nodiscard]] constexpr operator scalar<that_unit, value_type>() const noexcept
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

        [[nodiscard]] consteval auto operator*(unit_c auto that_unit) && noexcept
        {
            return scalar<this_unit * that_unit, value_type>{ this->value_ };
        }

        [[nodiscard]] consteval auto operator/(unit_c auto that_unit) && noexcept
        {
            return scalar<this_unit / that_unit, value_type>{ this->value_ };
        }

    private:

        template <unit_c auto that_unit, quantity quantity_>
        [[nodiscard]] constexpr value_type dimension_factor() const noexcept
        {
            constexpr auto this_exponent = data_of<quantity_>(this_unit).exponent;
            constexpr auto that_exponent = data_of<quantity_>(that_unit).exponent;

            if constexpr(this_exponent != 0 && that_exponent != 0)
            {
                return std::pow(data_of<quantity_>(this_unit).factor, this_exponent) /
                       std::pow(data_of<quantity_>(that_unit).factor, that_exponent);
            }
            else
            {
                return value_type{ 1.0L };
            }
        }

        template <unit_c auto that_unit, quantity... quantities>
        [[nodiscard]] constexpr scalar<that_unit, value_type> as_impl(
            quantity_sequence<quantities...>
        ) const noexcept
        {
            return { (this->value_ * ... * this->dimension_factor<that_unit, quantities>()) };
        }

        value_type value_;

    };



    template <unit_c auto unit = _1>
    using int_t = scalar<unit, int>;

    template <unit_c auto unit = _1>
    using unsigned_int_t = scalar<unit, unsigned int>;

    template <unit_c auto unit = _1>
    using unsigned_t = scalar<unit, unsigned>;


    template <unit_c auto unit = _1>
    using short_int_t = scalar<unit, short int>;

    template <unit_c auto unit = _1>
    using short_t= scalar<unit, short>;

    template <unit_c auto unit = _1>
    using unsigned_short_int_t= scalar<unit, unsigned short int>;

    template <unit_c auto unit = _1>
    using unsigned_short_t= scalar<unit, unsigned short>;


    template <unit_c auto unit = _1>
    using long_int_t = scalar<unit, long int>;

    template <unit_c auto unit = _1>
    using long_t= scalar<unit, long>;

    template <unit_c auto unit = _1>
    using unsigned_long_int_t= scalar<unit, unsigned long int>;

    template <unit_c auto unit = _1>
    using unsigned_long_t= scalar<unit, unsigned long>;


    template <unit_c auto unit = _1>
    using long_long_int_t = scalar<unit, long long int>;

    template <unit_c auto unit = _1>
    using long_long_t= scalar<unit, long long>;

    template <unit_c auto unit = _1>
    using unsigned_long_long_int_t= scalar<unit, unsigned long long int>;

    template <unit_c auto unit = _1>
    using unsigned_long_long_t= scalar<unit, unsigned long long>;


    template <unit_c auto unit = _1>
    using float_t = scalar<unit, float>;

    template <unit_c auto unit = _1>
    using double_t = scalar<unit, double>;

    template <unit_c auto unit = _1>
    using long_double_t = scalar<unit, long double>;



    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto make_scalar(Value value) noexcept
    {
        return scalar<unit, Value>{ value };
    }


    template <unit_c auto unit, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator+(
        scalar<unit, Value1> summand_1, scalar<unit, Value2> summand_2) noexcept
    {
        return make_scalar<unit>(summand_1.cvalue() + summand_2.cvalue());
    }

    template <unit_c auto unit, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator-(
        scalar<unit, Value1> minuend, scalar<unit, Value2> subtrahend
    ) noexcept
    {
        return make_scalar<unit>(minuend.cvalue() - subtrahend.cvalue());
    }

    [[nodiscard]] consteval auto operator*(number_c auto&& factor, unit_c auto unit) noexcept
    {
        return make_scalar<unit>(factor);
    }

    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator*(
        scalar<unit, Value> factor_1, number_c auto factor_2
    ) noexcept
    {
        return make_scalar<unit>(factor_1.cvalue() * factor_2);
    }

    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator*(
        number_c auto factor_1, scalar<unit, Value> factor_2
    ) noexcept
    {
        return make_scalar<unit>(factor_1 * factor_2.cvalue());
    }

    template <unit_c auto unit_1, unit_c auto unit_2, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator*(
        scalar<unit_1, Value1> factor_1, scalar<unit_2, Value2> factor_2
    ) noexcept
    {
        return make_scalar<unit_1 * unit_2>(factor_1.cvalue() * factor_2.cvalue());
    }

    template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator/(
        scalar<unit, Value> dividend, number_c auto divisor
    ) noexcept
    {
        return make_scalar<unit>(dividend.cvalue() / divisor);
    }

    template <unit_c auto unit_1, unit_c auto unit_2, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator/(
        scalar<unit_1, Value1> dividend, scalar<unit_2, Value2> divisor
    ) noexcept
    {
        return make_scalar<unit_1 / unit_2>(dividend.cvalue() / divisor.cvalue());
    }


    template <typename Char, unit_c auto unit, number_c Value>
    std::basic_ostream<Char>& operator<<(
        std::basic_ostream<Char>& os, scalar<unit, Value> scalar
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

        os << scalar.cvalue();

        if(unit_width > 0)
            os << " " << unit;

        return os;
    }

}



namespace zollstock::inline units::inline literals
{

    ZOLLSTOCK_DEFINE_LITERAL(1, _1)

}


#endif //__ZOLLSTOCK_SCALAR_HPP__
