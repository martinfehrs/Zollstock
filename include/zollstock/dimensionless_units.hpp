#ifndef __ZOLLSTOCK_DIMENSIONLESS_UNITS_HPP__
#define __ZOLLSTOCK_DIMENSIONLESS_UNITS_HPP__


#include "unit_concept.hpp"


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            struct one
            {

                static constexpr quantity_exponents exponents{ 0, 0, 0 };
                static constexpr quantity_factors factors{ 0.0L, 0.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, ""_us, ""_us };

            };

        }

        inline namespace constants
        {

            inline constexpr one _1{};

        }

    }

}


#endif //__ZOLLSTOCK_DIMENSIONLESS_UNITS_HPP__
