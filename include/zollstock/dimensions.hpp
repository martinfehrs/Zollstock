#ifndef __ZOLLSTOCK_DIMENSIONS_HPP__
#define __ZOLLSTOCK_DIMENSIONS_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>

#  include <compare>
#endif


namespace zollstock::dimensions
{

    ZOLLSTOCK_MODULE_EXPORT struct dimensions_t
    {

        const int length;
        const int time;
        const int mass;
        const int electric_current;
        const int thermodynamic_temperature;
        const int amount_of_substance;
        const int luminous_intensity;

        [[nodiscard]] consteval auto operator<=>(const dimensions_t &that) const noexcept
        {
            if (auto cmp = (this->length != 0) <=> (that.length != 0); cmp != 0)
                return cmp;

            if (auto cmp = (this->time != 0) <=> (that.time != 0); cmp != 0)
                return cmp;

            if (auto cmp = (this->mass != 0) <=> (that.mass != 0); cmp != 0)
                return cmp;

            if (auto cmp = (this->electric_current != 0) <=> (that.electric_current != 0); cmp != 0)
                return cmp;

            if (
                auto cmp = (this->thermodynamic_temperature != 0) <=>
                           (that.thermodynamic_temperature != 0);
                cmp != 0
            )
            {
                return cmp;
            }

            if (
                auto cmp = (this->amount_of_substance != 0) <=> (that.amount_of_substance != 0);
                cmp != 0
            )
            {
                return cmp;
            }

            return (this->luminous_intensity != 0) <=> (that.luminous_intensity != 0);
        }

        [[nodiscard]] consteval bool operator==(const dimensions_t& that) const noexcept
        {
            return (this->length != 0) == (that.length != 0)
                && (this->mass   != 0) == (that.mass   != 0)
                && (this->time   != 0) == (that.time   != 0);
        }

        [[nodiscard]] consteval dimensions_t operator*(const dimensions_t& that) const noexcept
        {
            return {
                this->length                    + that.length                   ,
                this->time                      + that.time                     ,
                this->mass                      + that.mass                     ,
                this->electric_current          + that.electric_current         ,
                this->thermodynamic_temperature + that.thermodynamic_temperature,
                this->amount_of_substance       + that.amount_of_substance      ,
                this->luminous_intensity        + that.luminous_intensity
            };
        }

        [[nodiscard]] consteval dimensions_t operator/(const dimensions_t& that) const noexcept
        {
            return {
                this->length                    - that.length                   ,
                this->time                      - that.time                     ,
                this->mass                      - that.mass                     ,
                this->electric_current          - that.electric_current         ,
                this->thermodynamic_temperature - that.thermodynamic_temperature,
                this->amount_of_substance       - that.amount_of_substance      ,
                this->luminous_intensity        - that.luminous_intensity
            };
        }

        [[nodiscard]] consteval bool dimensionless() const noexcept
        {
            return (this->length                    == 0)
                && (this->time                      == 0)
                && (this->mass                      == 0)
                && (this->electric_current          == 0)
                && (this->thermodynamic_temperature == 0)
                && (this->amount_of_substance       == 0)
                && (this->luminous_intensity        == 0);
        }

        [[nodiscard]] consteval bool base() const noexcept
        {
            return (this->length                    >= 0)
                && (this->time                      >= 0)
                && (this->mass                      >= 0)
                && (this->electric_current          >= 0)
                && (this->thermodynamic_temperature >= 0)
                && (this->amount_of_substance       >= 0)
                && (this->luminous_intensity        >= 0)
                && (this->length                    == 1)
                != (this->time                      == 1)
                != (this->mass                      == 1)
                != (this->electric_current          == 1)
                != (this->thermodynamic_temperature == 1)
                != (this->amount_of_substance       == 1)
                != (this->luminous_intensity        == 1);
        }

        [[nodiscard]] consteval bool derived() const noexcept
        {
            return !this->base();
        }

        // Wahr falls genau eine Basisdimension einen Exponenten != 0 aufweist.
        [[nodiscard]] consteval bool homogeneous() const noexcept
        {
            return (this->length                    != 0)
                != (this->time                      != 0)
                != (this->mass                      != 0)
                != (this->electric_current          != 0)
                != (this->thermodynamic_temperature != 0)
                != (this->amount_of_substance       != 0)
                != (this->luminous_intensity        != 0);
        }

    };

    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t _1   { 0, 0, 0, 0, 0, 0, 0 };
    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t L    { 1, 0, 0, 0, 0, 0, 0 };
    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t T    { 0, 1, 0, 0, 0, 0, 0 };
    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t M    { 0, 0, 1, 0, 0, 0, 0 };
    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t I    { 0, 0, 0, 1, 0, 0, 0 };
    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t Theta{ 0, 0, 0, 0, 1, 0, 0 };
    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t N    { 0, 0, 0, 0, 0, 1, 0 };
    ZOLLSTOCK_MODULE_EXPORT inline constexpr dimensions_t J    { 0, 0, 0, 0, 0, 0, 1 };

    namespace detail
    {

        template <int exponent>
        [[nodiscard]] consteval dimensions_t pow(dimensions_t dimensions) noexcept
        {
            return {
                dimensions.length                    * exponent,
                dimensions.time                      * exponent,
                dimensions.mass                      * exponent,
                dimensions.electric_current          * exponent,
                dimensions.thermodynamic_temperature * exponent,
                dimensions.amount_of_substance       * exponent,
                dimensions.luminous_intensity        * exponent
            };
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template<dimensions_t dimensions, int exponent>
    inline constexpr dimensions_t pow_v = detail::pow<exponent>(dimensions);

}


#endif //__ZOLLSTOCK_DIMENSIONS_HPP__
