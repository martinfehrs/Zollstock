#ifndef __ZOLLSTOCK_PREFIXES_HPP__
#define __ZOLLSTOCK_PREFIXES_HPP__


#include <zollstock/units/concepts/prefix.hpp>


namespace zollstock::prefixes
{

    inline constexpr prefix<"q"  , 1e-30L> q  ;
    inline constexpr prefix<"r"  , 1e-27L> r  ;
    inline constexpr prefix<"y"  , 1e-24L> y  ;
    inline constexpr prefix<"z"  , 1e-21L> z  ;
    inline constexpr prefix<"a"  , 1e-18L> a  ;
    inline constexpr prefix<"f"  , 1e-15L> f  ;
    inline constexpr prefix<"p"  , 1e-12L> p  ;
    inline constexpr prefix<"n"  , 1e-09L> n  ;
    inline constexpr prefix<"mic", 1e-06L> mic;
    inline constexpr prefix<"m"  , 1e-03L> m  ;
    inline constexpr prefix<"c"  , 1e-02L> c  ;
    inline constexpr prefix<"d"  , 1e-01L> d  ;
    inline constexpr prefix<"da" , 1e+01L> da ;
    inline constexpr prefix<"h"  , 1e+02L> h  ;
    inline constexpr prefix<"k"  , 1e+03L> k  ;
    inline constexpr prefix<"M"  , 1e+06L> M  ;
    inline constexpr prefix<"G"  , 1e+09L> G  ;
    inline constexpr prefix<"T"  , 1e+12L> T  ;
    inline constexpr prefix<"P"  , 1e+15L> P  ;
    inline constexpr prefix<"E"  , 1e+18L> E  ;
    inline constexpr prefix<"Z"  , 1e+21L> Z  ;
    inline constexpr prefix<"Y"  , 1e+24L> Y  ;
    inline constexpr prefix<"R"  , 1e+27L> R  ;
    inline constexpr prefix<"Q"  , 1e+30L> Q  ;

}


#endif //__ZOLLSTOCK_PREFIXES_HPP__
