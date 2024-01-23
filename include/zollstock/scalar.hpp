#ifndef __ZOLLSTOCK_SCALAR_HPP__
#define __ZOLLSTOCK_SCALAR_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_algorithms.hpp>

#include <concepts>


namespace zollstock
{

    template <unit_c auto this_unit, std::floating_point ThisValue = double>
    class scalar
    {

        using value_type = ThisValue;
        using unit_type = decltype(this_unit);
        using this_type = scalar<this_unit, ThisValue>;

    public:

        constexpr scalar() noexcept
            : value_{}
        {}

        constexpr scalar(value_type value) noexcept
            : value_{ value }
        {}

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

        [[nodiscard]] constexpr bool operator==(const this_type& that) const noexcept = default;

        [[nodiscard]] constexpr std::partial_ordering operator<=>(
            const this_type& that
        ) const noexcept = default;

        [[nodiscard]] constexpr this_type operator-() const noexcept
        {
            return -this->value_;
        }

        template <unit_c auto that_unit> requires convertible_units_c<unit_type, decltype(that_unit)>
        [[nodiscard]] constexpr scalar<that_unit, value_type> as() const noexcept
        {
            return this->as_impl<that_unit>(make_quantity_index_sequence{});
        }

        template <unit_c auto that_unit> requires convertible_units_c<unit_type, decltype(that_unit)>
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

        [[nodiscard]] constexpr this_type operator+(this_type that) const noexcept
        {
            return { this->cvalue() + that.cvalue() };
        }

        [[nodiscard]] constexpr this_type operator-(this_type that) const noexcept
        {
            return { this->cvalue() - that.cvalue() };
        }

        template <unit_c ThatUnit>
        [[nodiscard]] consteval auto operator*(ThatUnit) && noexcept
        {
            return scalar<this_unit * ThatUnit{}, value_type>{ this->value_ };
        }

        template <unit_c ThatUnit>
        [[nodiscard]] consteval auto operator/(ThatUnit) && noexcept
        {
            return scalar<this_unit / ThatUnit{}, value_type>{ this->value_ };
        }

        [[nodiscard]] constexpr this_type operator*(value_type that) const noexcept
        {
            return { this->cvalue() * that };
        }

        template <unit_c auto that_unit>
        [[nodiscard]] constexpr auto operator*(scalar<that_unit, value_type> that) const noexcept
        {
            return scalar<this_unit * that_unit, value_type>{ this->cvalue() * that.cvalue() };
        }

        template <unit_c auto that_unit>
        [[nodiscard]] constexpr auto operator/(scalar<that_unit, value_type> that) const noexcept
        {
            return scalar<this_unit / that_unit, value_type>{ this->cvalue() / that.cvalue() };
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
        [[nodiscard]] constexpr scalar<that_unit, value_type> as_impl(
            std::index_sequence<indices...>
        ) const noexcept
        {
            return { (this->value_ * ... * this->dimension_factor<that_unit, indices>()) };
        }

        value_type value_;

    };

    template <unit_c Unit, std::floating_point Factor>
    [[nodiscard]] consteval auto operator*(Factor&& factor, Unit) noexcept
    {
        return scalar<Unit{}, Factor>{ factor };
    }

    template <unit_c auto unit, std::floating_point Value>
    [[nodiscard]] constexpr auto operator*(Value factor_1, scalar<unit, Value> factor_2) noexcept
    {
        return scalar<unit, Value>{ factor_1 * factor_2.cvalue() };
    }

    template <unit_c auto unit, std::floating_point Value>
    [[nodiscard]] constexpr auto operator/(scalar<unit, Value> dividend, Value divisor) noexcept
    {
        return scalar<unit, Value>{ dividend.cvalue() / divisor };
    }

    template <typename Char, unit_c auto unit, std::floating_point Value>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, scalar<unit, Value> scalar)
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


#endif //__ZOLLSTOCK_SCALAR_HPP__
