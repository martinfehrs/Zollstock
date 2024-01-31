#ifndef __ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__


#include <zollstock/time_unit_types.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock::inline units::inline constants
{

    ZOLLSTOCK_DEFINE_SI_BASE_UNIT_CONSTANTS(second, s)

    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(minute, min)
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(hour  , h  )
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(day   , d  )
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(year  , a  )

}


#endif //__ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__
