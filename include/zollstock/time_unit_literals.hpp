#ifndef __ZOLLSTOCK_TIME_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_TIME_UNIT_LITERALS_HPP__


#include <zollstock/time_unit_constants.hpp>
#include <zollstock/definition_helpers.hpp>
#include <zollstock/quantity.hpp>


namespace zollstock::inline unit::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(s)

    ZOLLSTOCK_DEFINE_LITERAL(min, min)
    ZOLLSTOCK_DEFINE_LITERAL(h  , h  )
    ZOLLSTOCK_DEFINE_LITERAL(d  , d  )
    ZOLLSTOCK_DEFINE_LITERAL(a  , a  )

}


#endif //__ZOLLSTOCK_TIME_UNIT_LITERALS_HPP__
