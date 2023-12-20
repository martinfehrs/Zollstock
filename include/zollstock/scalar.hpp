#ifndef __ZOLLSTOCK_SCALAR_HPP__
#define __ZOLLSTOCK_SCALAR_HPP__


#include "unit_concept.hpp" 
#include "unit_algorithms.hpp"


namespace zollstock
{

    namespace detail
    {

        [[nodiscard]] constexpr long double pow(long double base, int exponent) noexcept
        {
            if (exponent > 0)
            {
                long double result = 1;

                while(exponent > 0)
                {
                    result *= base;
                    --exponent;
                }

                return result;
            }
            else if (exponent < 0)
            {
                long double result = 1;

                while(exponent < 0)
                {
                    result /= base;
                    ++exponent;
                }

                return result;
            }
            else
            {
                return 1.0L;
            }
        }
    
    }

    template <typename ThisUnit>
    class scalar
    {

        static_assert(is_unit_v<ThisUnit>);

        using this_type = scalar<ThisUnit>;

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

        [[nodiscard]] static constexpr const ThisUnit& unit() noexcept
        {
            return unit_;
        }

        [[nodiscard]] constexpr bool operator==(const this_type& that) const noexcept
        {
            return this->value == that.value;
        }

        [[nodiscard]] constexpr bool operator!=(const this_type& that) const noexcept
        {
            return this->value != that.value;
        }

        [[nodiscard]] constexpr bool operator<(const this_type& that) const noexcept
        {
            return this->value < that.value;
        }

        [[nodiscard]] constexpr bool operator>(const this_type& that) const noexcept
        {
            return this->value > that.value;
        }

        [[nodiscard]] constexpr bool operator<=(const this_type& that) const noexcept
        {
            return this->value > that.value;
        }

        [[nodiscard]] constexpr bool operator>=(const this_type& that) const noexcept
        {
            return this->value > that.value;
        }

        [[nodiscard]] constexpr this_type operator-() const noexcept
        {
            return -this->value_;
        }

        template <
            typename ThatUnit,
            typename = std::enable_if_t<convertible_units_v<ThisUnit, ThatUnit>>
        >
        [[nodiscard]] constexpr scalar<ThatUnit> as() const noexcept
        {
            return this->as_impl<ThatUnit>(make_dimension_index_sequence{});
        }

        template <
            typename ThatUnit,
            typename = std::enable_if_t<convertible_units_v<ThisUnit, ThatUnit>>
        >
        [[nodiscard]] constexpr operator scalar<ThatUnit>() const noexcept
        {
            return this->as<ThatUnit>();
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

        template <typename ThatUnit, typename = std::enable_if_t<is_unit_v<ThatUnit>>>
        [[nodiscard]] constexpr auto operator*(ThatUnit) const noexcept
        {
            return scalar<unit_product<ThisUnit, ThatUnit>>{ this->value_ };
        }  

        template <typename ThatUnit, typename = std::enable_if_t<is_unit_v<ThatUnit>>>
        [[nodiscard]] constexpr auto operator/(ThatUnit) const noexcept
        {
            return scalar<unit_division<ThisUnit, ThatUnit>>{ this->value_ };
        }  

        [[nodiscard]] constexpr this_type operator*(double that) const noexcept
        {
            return { this->cvalue() * that };
        }

        template <typename ThatUnit, typename = std::enable_if_t<is_unit_v<ThatUnit>>>
        [[nodiscard]] constexpr auto operator*(scalar<ThatUnit> that) const noexcept
        {
            return scalar<unit_product<ThisUnit, ThatUnit>>{ this->cvalue() * that.cvalue() };
        }

        template <typename ThatUnit, typename = std::enable_if_t<is_unit_v<ThatUnit>>>
        [[nodiscard]] constexpr auto operator/(scalar<ThatUnit> that) const noexcept
        {
            return scalar<unit_division<ThisUnit, ThatUnit>>{ this->cvalue() / that.cvalue() };
        }

    private:

        template <typename ThatUnit, std::size_t pos>
        [[nodiscard]] constexpr double dimension_factor() const noexcept
        {
            // muss der Exponent mit einbezogen werden?

            constexpr auto this_exponent = get<pos>(ThisUnit::exponents);
            constexpr auto that_exponent = get<pos>(ThatUnit::exponents);

            if constexpr(this_exponent != 0 && that_exponent != 0)
            {
                return detail::pow(get<pos>(ThisUnit::factors), this_exponent) /
                       detail::pow(get<pos>(ThatUnit::factors), that_exponent);
            }
            else if constexpr(get<pos>(ThisUnit::exponents) != 0)
            {
                return get<pos>(ThisUnit::factors);
            }
            else
            {
                return 1.0;
            }
        }

        template <typename ThatUnit, std::size_t... indices>
        [[nodiscard]] constexpr scalar<ThatUnit> as_impl(std::index_sequence<indices...>) const noexcept
        {
            return { (this->value_ * ... * this->dimension_factor<ThatUnit, indices>()) };
        }

        double value_;
        static constexpr ThisUnit unit_{};

    };

    template <typename Unit, typename = std::enable_if_t<is_unit_v<Unit>>>
    [[nodiscard]] constexpr auto operator*(double factor, Unit) noexcept
    {
        return scalar<Unit>{ factor };
    }


    template <typename Unit, typename = std::enable_if_t<is_unit_v<Unit>>>
    [[nodiscard]] constexpr auto operator*(double factor_1, scalar<Unit> factor_2) noexcept
    {
        return scalar<Unit>{ factor_1 * factor_2.cvalue() };
    }

    template <typename Unit, typename = std::enable_if_t<is_unit_v<Unit>>>
    [[nodiscard]] constexpr auto operator/(scalar<Unit> dividend, double divisor) noexcept
    {
        return scalar<Unit>{ dividend.cvalue() / divisor };
    }

    template <typename Char, typename Unit, typename = std::enable_if_t<is_unit_v<Unit>>>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, scalar<Unit> scalar)
    {
        static constexpr Unit unit{};

        const std::basic_string<Char> unit_representation = to_basic_string<Char>(unit);

        const std::size_t unit_width = unit_representation.size();
        const std::size_t unit_width_including_space = unit_width + 1U;

        if (unit_width > 0 && os.width() >= static_cast<std::streamsize>(unit_width_including_space))
            os.width(os.width() - unit_width_including_space);

        os << scalar.cvalue();

        if(unit_width > 0)
            os << " " << unit;

        return os;
    }

}


#endif //__ZOLLSTOCK_SCALAR_HPP__
