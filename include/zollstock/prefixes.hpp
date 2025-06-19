#ifndef __ZOLLSTOCK_PREFIXES_HPP__
#define __ZOLLSTOCK_PREFIXES_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#include <zollstock/config.hpp>
#include <zollstock/units/concepts/prefix.hpp>
#endif //ZOLLSTOCK_USE_MODULES


namespace zollstock::prefixes
{

    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"q"  , 1e-30L> q  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"r"  , 1e-27L> r  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"y"  , 1e-24L> y  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"z"  , 1e-21L> z  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"a"  , 1e-18L> a  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"f"  , 1e-15L> f  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"p"  , 1e-12L> p  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"n"  , 1e-09L> n  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"mic", 1e-06L> mic;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"m"  , 1e-03L> m  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"c"  , 1e-02L> c  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"d"  , 1e-01L> d  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"da" , 1e+01L> da ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"h"  , 1e+02L> h  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"k"  , 1e+03L> k  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"M"  , 1e+06L> M  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"G"  , 1e+09L> G  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"T"  , 1e+12L> T  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"P"  , 1e+15L> P  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"E"  , 1e+18L> E  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"Z"  , 1e+21L> Z  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"Y"  , 1e+24L> Y  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"R"  , 1e+27L> R  ;
    ZOLLSTOCK_MODULE_EXPORT inline constexpr prefix<"Q"  , 1e+30L> Q  ;

}


#endif //__ZOLLSTOCK_PREFIXES_HPP__
