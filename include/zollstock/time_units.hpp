#ifndef __ZOLLSTOCK_TIME_UNITS_HPP__
#define __ZOLLSTOCK_TIME_UNITS_HPP__


#include <zollstock/time_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(s)

    ZOLLSTOCK_DEFINE_LITERALS(min, min)
    ZOLLSTOCK_DEFINE_LITERALS(h  , h  )
    ZOLLSTOCK_DEFINE_LITERALS(d  , d  )
    ZOLLSTOCK_DEFINE_LITERALS(a  , a  )

}


#endif //__ZOLLSTOCK_TIME_UNITS_HPP__
