#ifndef __ZOLLSTOCK_DIMENSIONS_HPP__
#define __ZOLLSTOCK_DIMENSIONS_HPP__


#include <compare>


namespace zollstock::dimensions
{

    struct dimensions_t
    {

        const int length;
        const int time;
        const int mass;
        const int electric_current;
        const int thermodynamic_temperature;
        const int amount_of_substance;
        const int luminous_intensity;

        consteval dimensions_t(
            int length,
            int time,
            int mass,
            int electric_current,
            int thermodynamic_temperature,
            int amount_of_substance,
            int luminous_intensity
        ) noexcept
            : length                   { length                    }
            , time                     { time                      }
            , mass                     { mass                      }
            , electric_current         { electric_current          }
            , thermodynamic_temperature{ thermodynamic_temperature }
            , amount_of_substance      { amount_of_substance       }
            , luminous_intensity       { luminous_intensity        }
        { }

        consteval dimensions_t(const dimensions_t&) noexcept = default;

        [[nodiscard]] consteval auto operator<=>(const dimensions_t&) const noexcept = default;

        [[nodiscard]] consteval bool operator==(const dimensions_t&) const noexcept = default;

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

    };

    inline constexpr dimensions_t _1   { 0, 0, 0, 0, 0, 0, 0 };
    inline constexpr dimensions_t L    { 1, 0, 0, 0, 0, 0, 0 };
    inline constexpr dimensions_t M    { 0, 1, 0, 0, 0, 0, 0 };
    inline constexpr dimensions_t T    { 0, 0, 1, 0, 0, 0, 0 };
    inline constexpr dimensions_t Theta{ 0, 0, 0, 0, 1, 0, 0 };

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

    template<dimensions_t dimensions, int exponent>
    inline constexpr dimensions_t pow_v = detail::pow<exponent>(dimensions);

}


#endif //__ZOLLSTOCK_DIMENSIONS_HPP__
