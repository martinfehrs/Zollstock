#ifndef __ZOLLSTOCK_QUANTITIES_TEMPLATE_HPP__
#define __ZOLLSTOCK_QUANTITIES_TEMPLATE_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>
#  include <zollstock/numbers.hpp>
#  include <zollstock/quantities/concepts.hpp>
#  include <zollstock/units/concepts/unit.hpp>
#  include <zollstock/units/constants/one.hpp>

#  include <algorithm>
#  include <cmath>
#  include <format>
#  include <iostream>
#  include <format>
#  include <utility>
#endif


namespace zollstock
{

    ZOLLSTOCK_MODULE_EXPORT struct uninitialized_
    {
        consteval uninitialized_() noexcept = default;
        uninitialized_(const uninitialized_&) = delete;
        uninitialized_& operator=(const uninitialized_&) = delete;
    };

    ZOLLSTOCK_MODULE_EXPORT inline constexpr uninitialized_ uninitialized{};


    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto this_unit, number_c ThisValue = double>
    class quantity
    {

        template <unit_c auto, number_c>
        friend class quantity;

        using this_type = quantity<this_unit, ThisValue>;

    public:

        using unit_type = decltype(this_unit);
        using value_type = ThisValue;

#if !defined(ZOLLSTOCK_QUANTITY_AGGREGATE_INITIALIZATION)

        explicit constexpr quantity(const uninitialized_&) noexcept
        {}

        constexpr quantity() noexcept
            : value_{}
        {}

        template <number_c ThatValue>
        explicit constexpr quantity(
            ThatValue value
        ) noexcept(lossless_convertible_v<ThatValue, ThisValue>)
            : value_{ narrow<ThisValue>(value) }
        {}

        template <auto that_unit, number_c ThatValue>
            requires(convertible_units(this_unit, that_unit))
        explicit(!lossless_convertible_v<ThatValue, ThisValue>)
        constexpr quantity(
            quantity<that_unit, ThatValue> that
        ) noexcept(lossless_convertible_v<ThatValue, ThisValue>)
            : value_{ narrow<ThisValue>(that.value_) }
        {
            if constexpr(this_unit != that_unit)
            {
                this->value_ = this->value_ * unit_scaling_factor(that_unit)
                                            / unit_scaling_factor(this_unit);
            }
        }

#endif //!defined(ZOLLSTOCK_QUANTITY_AGGREGATE_INITIALIZATION)

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

        [[nodiscard]] static consteval const auto& unit() noexcept
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

        [[nodiscard]] constexpr this_type operator+() const noexcept
            requires(std::is_signed_v<ThisValue>)
        {
            return *this;
        }

        [[nodiscard]] constexpr this_type operator-() const noexcept
            requires(std::is_signed_v<ThisValue>)
        {
            return this_type{ -this->value_ };
        }

        constexpr this_type& operator+=(this_type that) noexcept
        {
            this->value_ += that.value_;

            return *this;
        }

        constexpr this_type& operator-=(this_type that) noexcept
        {
            this->value_ -= that.value_;

            return *this;
        }

        [[nodiscard]] consteval auto operator*(unit_c auto that_unit) && noexcept
        {
            return quantity<this_unit * that_unit, value_type>{ this->value_ };
        }

        [[nodiscard]] consteval auto operator/(unit_c auto that_unit) && noexcept
        {
            return quantity<this_unit / that_unit, value_type>{ this->value_ };
        }

        constexpr this_type& operator*=(value_type that_value) noexcept
        {
            this->value_ *= that_value;

            return (*this);
        }

        constexpr this_type& operator/=(value_type that_value) noexcept
        {
            this->value_ /= that_value;

            return (*this);
        }

    private:

        [[nodiscard]] static constexpr long double pow_impl(
            long double base, unsigned int exponent
        ) noexcept
        {
            if (exponent == 0)
                return 1.0L;

            return base * pow(base, exponent - 1);
        }

        // Eigene Implementierung von pow, da die Standardimplementierung std::pow
        // nicht bei allen unterstützten Compilern innerhalb konstanter Ausdrücke verwendet
        // werden kann.
        [[nodiscard]] static constexpr long double pow(long double base, int exponent) noexcept
        {
            if (exponent < 0)
                return 1.0L/pow_impl(base, -exponent);

            return pow_impl(base, exponent);
        }

#if defined(ZOLLSTOCK_QUANTITY_AGGREGATE_INITIALIZATION) || defined(ZOLLSTOCK_QUANTITY_PUBLIC_MEMBERS)
    public:
#endif //defined(ZOLLSTOCK_QUANTITY_AGGREGATE_INITIALIZATION) || defined(ZOLLSTOCK_QUANITY_PUBLIC_MEMBERS)

        value_type value_;

    };



    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using int_t = quantity<unit, int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_int_t = quantity<unit, unsigned int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_t = quantity<unit, unsigned>;


    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using short_int_t = quantity<unit, short int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using short_t= quantity<unit, short>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_short_int_t= quantity<unit, unsigned short int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_short_t= quantity<unit, unsigned short>;


    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using long_int_t = quantity<unit, long int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using long_t= quantity<unit, long>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_long_int_t= quantity<unit, unsigned long int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_long_t= quantity<unit, unsigned long>;


    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using long_long_int_t = quantity<unit, long long int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using long_long_t= quantity<unit, long long>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_long_long_int_t= quantity<unit, unsigned long long int>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using unsigned_long_long_t= quantity<unit, unsigned long long>;


    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using float_t = quantity<unit, float>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using double_t = quantity<unit, double>;

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit = units::_1>
    using long_double_t = quantity<unit, long double>;



    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto make_quantity(Value value) noexcept
    {
        return quantity<unit, Value>{ value };
    }


    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator+(
        quantity<unit, Value1> summand_1, quantity<unit, Value2> summand_2) noexcept
    {
        return make_quantity<unit>(summand_1.cvalue() + summand_2.cvalue());
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit, number_c Value1, number_c Value2>
    [[nodiscard]] constexpr auto operator-(
        quantity<unit, Value1> minuend, quantity<unit, Value2> subtrahend
    ) noexcept
    {
        return make_quantity<unit>(minuend.cvalue() - subtrahend.cvalue());
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto operator*(
        number_c auto&& factor, unit_c auto unit
    ) noexcept
    {
        return make_quantity<unit>(factor);
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator*(
        quantity<unit, Value> factor_1, number_c auto factor_2
    ) noexcept
    {
        return make_quantity<unit>(factor_1.cvalue() * factor_2);
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator*(
        number_c auto factor_1, quantity<unit, Value> factor_2
    ) noexcept
    {
        return make_quantity<unit>(factor_1 * factor_2.cvalue());
    }

    ZOLLSTOCK_MODULE_EXPORT template <
        unit_c auto unit_1, unit_c auto unit_2, number_c Value1, number_c Value2
    >
    [[nodiscard]] constexpr auto operator*(
        quantity<unit_1, Value1> factor_1, quantity<unit_2, Value2> factor_2
    ) noexcept
    {
        return make_quantity<unit_1 * unit_2>(factor_1.cvalue() * factor_2.cvalue());
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr auto operator/(
        quantity<unit, Value> dividend, number_c auto divisor
    ) noexcept
    {
        return make_quantity<unit>(dividend.cvalue() / divisor);
    }

    ZOLLSTOCK_MODULE_EXPORT template <
        unit_c auto unit_1, unit_c auto unit_2, number_c Value1, number_c Value2
    >
    [[nodiscard]] constexpr auto operator/(
        quantity<unit_1, Value1> dividend, quantity<unit_2, Value2> divisor
    ) noexcept
    {
        return make_quantity<unit_1 / unit_2>(dividend.cvalue() / divisor.cvalue());
    }


    ZOLLSTOCK_MODULE_EXPORT template <typename Char, unit_c auto unit, number_c Value>
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


    ZOLLSTOCK_MODULE_EXPORT template <
        unit_c auto target_unit, unit_c auto source_unit, number_c Value
    >
    [[nodiscard]] constexpr quantity<target_unit, Value> in(
        quantity<source_unit, Value> source
    ) noexcept
    {
        return quantity<target_unit, Value>{ source };
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit, number_c Value>
    [[nodiscard]] constexpr quantity<unit, Value> as(
        Value source
    ) noexcept
    {
        return quantity<unit, Value>{ source };
    }



    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit>
    [[nodiscard]] auto stof(const std::string& str, std::size_t* idx = 0)
    {
        return float_t<unit>{ std::stof(str, idx) };
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit>
    [[nodiscard]] auto stod(const std::string& str, std::size_t* idx = 0)
    {
        return double_t<unit>{ std::stod(str, idx) };
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_c auto unit>
    [[nodiscard]] auto stold(const std::string& str, std::size_t* idx = 0)
    {
        return long_double_t<unit>{ std::stold(str, idx) };
    }

}


ZOLLSTOCK_MODULE_EXPORT template<zollstock::unit_c auto this_unit, zollstock::number_c ThisValue>
struct std::formatter<zollstock::quantity<this_unit, ThisValue>, char>
{

    std::formatter<ThisValue, char> value_formatter;

    template<typename ParseContext>
    constexpr ParseContext::iterator parse(ParseContext& ctx)
    {
        return value_formatter.parse(ctx);
    }

    template<typename FmtContext>
    FmtContext::iterator format(
        zollstock::quantity<this_unit, ThisValue> quantity, FmtContext& ctx
    ) const
    {
        auto it = value_formatter.format(quantity.cvalue(), ctx);

        if(const auto unit_representation = to_string(this_unit); unit_representation.size() > 0)
            it = std::format_to(it, " {}", unit_representation);

        return it;
    }

};


#endif //__ZOLLSTOCK_QUANTITIES_TEMPLATE_HPP__
