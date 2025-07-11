#ifndef __ZOLLSTOCK_UNITS_CONSTANTS_SQUARED_TIME_HPP__
#define __ZOLLSTOCK_UNITS_CONSTANTS_SQUARED_TIME_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/units/constants/time.hpp>
#  include <zollstock/units/constants/definition_helpers.hpp>
#endif


namespace zollstock::units::inline constants
{

    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANTS(s, 2)

    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(min, 2)
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(h  , 2)
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(d  , 2)
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(a  , 2)

}


#endif //__ZOLLSTOCK_UNITS_CONSTANTS_SQUARED_TIME_HPP__
