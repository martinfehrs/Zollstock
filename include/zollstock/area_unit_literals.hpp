#ifndef __ZOLLSTOCK_AREA_UNIT_LITERALS_HPP__
#define __ZOLLSTOCK_AREA_UNIT_LITERALS_HPP__


#include <zollstock/area_unit_types.hpp>
#include <zollstock/definition_helpers.hpp>
#include <zollstock/scalar.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace literals
        {

            ZOLLSTOCK_DEFINE_SI_LITERALS(square_, meter, m2)

        }

    }

}


#endif //__ZOLLSTOCK_AREA_UNIT_LITERALS_HPP__
