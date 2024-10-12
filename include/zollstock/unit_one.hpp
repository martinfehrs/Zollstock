#ifndef __ZOLLSTOCK_UNIT_ONE_HPP__
#define __ZOLLSTOCK_UNIT_ONE_HPP__


#include <zollstock/unit_one_constant.hpp>
#include <zollstock/literal_definition_helpers.hpp>


namespace zollstock::units::inline literals
{

    ZOLLSTOCK_DEFINE_LITERALS(1, _1)


    template <typename Quantity>
    concept dimensionless_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::_1;
    };

}


#endif //__ZOLLSTOCK_UNIT_ONE_HPP__
