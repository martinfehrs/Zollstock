#ifndef __ZOLLSTOCK_TIME_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_TIME_UNIT_LITERALS_HPP__


#include <zollstock/time_unit_types.hpp>
#include <zollstock/definition_helpers.hpp>
#include <zollstock/scalar.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_SI_LITERALS(, second, s)

            ZOLLSTOCK_DEFINE_LITERAL(minute, min )
            ZOLLSTOCK_DEFINE_LITERAL(hour  , h   )
            ZOLLSTOCK_DEFINE_LITERAL(day   , d   )
            ZOLLSTOCK_DEFINE_LITERAL(year  , a   )

        }

    }

}


#endif //__ZOLLSTOCK_TIME_UNIT_LITERALS_HPP__
