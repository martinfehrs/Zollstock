#ifndef __ZOLLSTOCK_QUANTITIES_HPP__
#define __ZOLLSTOCK_QUANTITIES_HPP__


#include <zollstock/quantity_concept.hpp>


namespace zollstock::quantities
{

    inline constexpr quantity_t<"θ"> theta{};
    inline constexpr quantity_t<"l"> l    {};
    inline constexpr quantity_t<"t"> t    {};
    inline constexpr quantity_t<"m"> m    {};

}


#endif //__ZOLLSTOCK_QUANTITIES_HPP__
