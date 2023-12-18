#ifndef __ZOLLSTOCK_NUMBER_UNITS_HPP__
#define __ZOLLSTOCK_NUMBER_UNITS_HPP__


#include "scalar.hpp"


namespace zollstock
{

    inline namespace unit 
    {

        inline namespace types
        {

            struct one
            {

                static constexpr unit_exponents exponents{ 0, 0, 0 };
                static constexpr unit_factors factors{ 0.0L, 0.0L, 0.0L };
                static constexpr unit_symbols symbols{ ""_us, ""_us, ""_us };

            };

        }

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


#endif //__ZOLLSTOCK_NUMBER_UNITS_HPP__