#ifndef __ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>


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

    }

}


#endif //__ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__
