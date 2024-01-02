#ifndef __ZOLLSTOCK_DIMENSIONLESS_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_DIMENSIONLESS_UNIT_LITERALS_HPP__


#include <zollstock/scalar.hpp>
#include <zollstock/dimensionless_units.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_1(long double val) noexcept
            {
                return scalar<one>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_1(unsigned long long int val) noexcept
            {
                return scalar<one>{ static_cast<double>(val) };
            }

        }

    }

}


#endif //__ZOLLSTOCK_DIMENSIONLESS_UNIT_LITERALS_HPP__
