#ifndef __ZOLLSTOCK_SCALAR_HPP__
#define __ZOLLSTOCK_SCALAR_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_algorithms.hpp>


namespace zollstock
{

    template <unit_c auto this_unit>
    class scalar
    {

        using unit_type = decltype(this_unit);
        using this_type = scalar<this_unit>;

    public:

        constexpr scalar() noexcept
            : value_{}
        {}

        constexpr scalar(double value) noexcept
            : value_{ value }
        {}

        [[nodiscard]] constexpr double& value() noexcept
        {
            return this->value_;
        }

        [[nodiscard]] constexpr const double& value() const noexcept
        {
            return this->value_;
        }

        [[nodiscard]] constexpr const double& cvalue() const noexcept
        {
            return this->value_;
        }

        [[nodiscard]] static constexpr const unit_type& unit() noexcept
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
        [[nodiscard]] constexpr scalar<that_unit> as() const noexcept
        {
            return this->as_impl<that_unit>(make_quantity_index_sequence{});
        }

        template <unit_c auto that_unit> requires convertible_units_c<unit_type, decltype(that_unit)>
        [[nodiscard]] constexpr operator scalar<that_unit>() const noexcept
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
        [[nodiscard]] constexpr auto operator*(ThatUnit) && noexcept
        {
            return scalar<multiply_units_v<unit_type, ThatUnit>{}>{ this->value_ };
        }

        template <unit_c ThatUnit>
        [[nodiscard]] constexpr auto operator/(ThatUnit) && noexcept
        {
            return scalar<divide_units_v<unit_type, ThatUnit>{}>{ this->value_ };
        }

        [[nodiscard]] constexpr this_type operator*(double that) const noexcept
        {
            return { this->cvalue() * that };
        }

        template <unit_c auto that_unit>
        [[nodiscard]] constexpr auto operator*(scalar<that_unit> that) const noexcept
        {
            return scalar<multiply_units_v<unit_type, decltype(that_unit)>{}>{ this->cvalue() * that.cvalue() };
        }

        template <unit_c auto that_unit>
        [[nodiscard]] constexpr auto operator/(scalar<that_unit> that) const noexcept
        {
            return scalar<divide_units_v<unit_type, decltype(that_unit)>{}>{ this->cvalue() / that.cvalue() };
        }

    private:

        template <unit_c auto that_unit, std::size_t pos>
        [[nodiscard]] constexpr double dimension_factor() const noexcept
        {
            // muss der Exponent mit einbezogen werden?

            constexpr auto this_exponent = get<pos>(this_unit.exponents);
            constexpr auto that_exponent = get<pos>(that_unit.exponents);

            if constexpr(this_exponent != 0 && that_exponent != 0)
            {
                return std::pow(get<pos>(this_unit.factors), this_exponent) /
                       std::pow(get<pos>(that_unit.factors), that_exponent);
            }
            else if constexpr(get<pos>(this_unit.exponents) != 0)
            {
                return get<pos>(this_unit.factors);
            }
            else
            {
                return 1.0;
            }
        }

        template <unit_c auto that_unit, std::size_t... indices>
        [[nodiscard]] constexpr scalar<that_unit> as_impl(
            std::index_sequence<indices...>
        ) const noexcept
        {
            return { (this->value_ * ... * this->dimension_factor<that_unit, indices>()) };
        }

        double value_;

    };

    template <unit_c Unit>
    [[nodiscard]] constexpr auto operator*(double factor, Unit) noexcept
    {
        return scalar<Unit{}>{ factor };
    }


    template <unit_c auto unit>
    [[nodiscard]] constexpr auto operator*(double factor_1, scalar<unit> factor_2) noexcept
    {
        return scalar<unit>{ factor_1 * factor_2.cvalue() };
    }

    template <unit_c auto unit>
    [[nodiscard]] constexpr auto operator/(scalar<unit> dividend, double divisor) noexcept
    {
        return scalar<unit>{ dividend.cvalue() / divisor };
    }

    template <typename Char, unit_c auto unit>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, scalar<unit> scalar)
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
