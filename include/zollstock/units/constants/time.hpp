#ifndef __ZOLLSTOCK_UNITS_CONSTANTS_TIME_HPP__
#define __ZOLLSTOCK_UNITS_CONSTANTS_TIME_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/units/constants/definition_helpers.hpp>
#endif


namespace zollstock::units::inline constants
{

    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(T, s)

    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(T, min,         60.0L)
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(T, h  ,      3'600.0L)
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(T, d  ,     86'400.0L)
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(T, a  , 31'536'000.0L)

}


#endif //__ZOLLSTOCK_UNITS_CONSTANTS_TIME_HPP__
