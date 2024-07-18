#ifndef __ZOLLSTOCK_DIMENSIONS_HPP__
#define __ZOLLSTOCK_DIMENSIONS_HPP__


#include <zollstock/dimension_concept.hpp>


namespace zollstock::dimensions
{

    inline constexpr dimension_t<"T"> T{};
    inline constexpr dimension_t<"L"> L{};
    inline constexpr dimension_t<"M"> M{};

}


#endif //__ZOLLSTOCK_DIMENSIONS_HPP__
