#ifndef __ZOLLSTOCK_SQUARED_TIME_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_SQUARED_TIME_UNIT_CONSTANTS_HPP__


#include <zollstock/time_unit_constants.hpp>
#include <zollstock/definition_helpers.hpp>
#include <zollstock/unit_algorithms.hpp>


namespace zollstock::inline units::inline constants
{

    ZOLLSTOCK_DEFINE_SI_DERIVED_UNIT_CONSTANTS(s, 2)

    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(min, 2)
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(h  , 2)
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(d  , 2)
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(a  , 2)

}


#endif //__ZOLLSTOCK_SQUARED_TIME_UNIT_CONSTANTS_HPP__
