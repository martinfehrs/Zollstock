#ifndef __ZOLLSTOCK_LENGTH_UNITS_HPP__
#define __ZOLLSTOCK_LENGTH_UNITS_HPP__


#include <zollstock/length_unit_constants.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_SI_LITERALS(m)


    template <typename Quantity>
    concept length_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::L;
    };

}


#endif //__ZOLLSTOCK_LENGTH_UNITS_HPP__
