#ifndef __ZOLLSTOCK_TIME_CONCEPT_HPP__
#define __ZOLLSTOCK_TIME_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    template <typename Quantity>
    concept time_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::T;
    };

}


#endif //__ZOLLSTOCK_TIME_CONCEPT_HPP__
