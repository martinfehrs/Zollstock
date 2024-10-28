#ifndef __ZOLLSTOCK_AREA_CONCEPT_HPP__
#define __ZOLLSTOCK_AREA_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    template <typename Quantity>
    concept area_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::pow_v<dimensions::L, 2>;
    };

}


#endif //__ZOLLSTOCK_AREA_CONCEPT_HPP__
