#ifndef __ZOLLSTOCK_UNITS_LITERALS_TIME_HPP__
#define __ZOLLSTOCK_UNITS_LITERALS_TIME_HPP__


#include <zollstock/units/constants/time.hpp>
#include <zollstock/units/literals/definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(s)

    ZOLLSTOCK_DEFINE_LITERALS(min, min)
    ZOLLSTOCK_DEFINE_LITERALS(h  , h  )
    ZOLLSTOCK_DEFINE_LITERALS(d  , d  )
    ZOLLSTOCK_DEFINE_LITERALS(a  , a  )

}


#endif //__ZOLLSTOCK_UNITS_LITERALS_TIME_HPP__
