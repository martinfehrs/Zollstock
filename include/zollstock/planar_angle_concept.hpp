#ifndef __ZOLLSTOCK_PLANAR_ANGLE_CONCEPT_HPP__
#define __ZOLLSTOCK_PLANAR_ANGLE_CONCEPT_HPP__


#include <zollstock/quantity_concept.hpp>
#include <zollstock/unit_concept.hpp>


namespace zollstock::inline quantities
{

    template <typename Quantity>
    concept planar_angle_c = requires
    {
        requires quantity_c<Quantity>;
        requires unit_dimensions(Quantity::unit()) == dimensions::_1;
    };

}


#endif //__ZOLLSTOCK_PLANAR_ANGLE_CONCEPT_HPP__
