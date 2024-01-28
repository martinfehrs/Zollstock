#ifndef __ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__
#define __ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__


#include <zollstock/unit_concept.hpp>


namespace zollstock::inline unit::inline types
{

    struct one
    {
        static constexpr unit_type type = unit_type::basic;
        static constexpr unit_data length{};
        static constexpr unit_data time{};
        static constexpr unit_data angle{};

    };

}


#endif //__ZOLLSTOCK_DIMENSIONLESS_UNIT_TYPES_HPP__
