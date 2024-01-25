#ifndef __ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>


namespace zollstock::inline unit::inline types
{

    struct one
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_exponents exponents{ 0, 0, 0 };
        static constexpr unit_factors factors{ 0.0L, 0.0L, 0.0L };
        static constexpr unit_symbols symbols{ ""_us, ""_us, ""_us };

    };

}


#endif //__ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__
