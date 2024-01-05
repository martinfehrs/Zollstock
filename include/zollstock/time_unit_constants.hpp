#ifndef __ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__


#include <zollstock/time_unit_types.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace constants
        {

            ZOLLSTOCK_DEFINE_SI_CONSTANTS(,second, s)

            inline constexpr minute min  {};
            inline constexpr hour   h    {};
            inline constexpr day    d    {};
            inline constexpr year   a    {};

        }

    }

}


#endif //__ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__
