#ifndef __ZOLLSTOCK_SI_PREFIXES_HPP__
#define __ZOLLSTOCK_SI_PREFIXES_HPP__


#include "unit_symbol.hpp"


namespace zollstock
{

    struct quekto
    {
        static constexpr long double factor = 1e-30L;
        static constexpr auto symbol = "q"_us;        
    };

    struct ronto
    {
        static constexpr long double factor = 1e-27L;
        static constexpr auto symbol = "r"_us;        
    };

    struct yokto
    {
        static constexpr long double factor = 1e-24L;
        static constexpr auto symbol = "y"_us;        
    };

    struct zepto
    {
        static constexpr long double factor = 1e-21L;
        static constexpr auto symbol = "z"_us;        
    };

    struct atto
    {
        static constexpr long double factor = 1e-18L;
        static constexpr auto symbol = "a"_us;        
    };

    struct femto
    {
        static constexpr long double factor = 1e-15L;
        static constexpr auto symbol = "f"_us;        
    };

    struct pico
    {
        static constexpr long double factor = 1e-12L;
        static constexpr auto symbol = "p"_us;        
    };

    struct nano
    {
        static constexpr long double factor = 1e-9L;
        static constexpr auto symbol = "n"_us;
    };

    struct micro
    {
        static constexpr long double factor = 1e-6L;
        static constexpr auto symbol = "mic"_us;
    };

    struct milli
    {
        static constexpr long double factor = 1e-3L;
        static constexpr auto symbol = "m"_us; 
    };

    struct centi
    {
        static constexpr long double factor = 1e-2L; 
        static constexpr auto symbol = "c"_us;
    };

    struct deci
    {
        static constexpr long double factor = 1e-1L;
        static constexpr auto symbol = "d"_us;
    };

    struct unprefixed
    {
        static constexpr long double factor = 1e0L;
        static constexpr auto symbol = ""_us;
    };

    struct deca
    {
        static constexpr long double factor = 1e1L;
        static constexpr auto symbol = "da"_us;        
    };

    struct hecto
    {
        static constexpr long double factor = 1e2L;
        static constexpr auto symbol = "h"_us;        
    };

    struct kilo
    {
        static constexpr long double factor = 1e3L;
        static constexpr auto symbol = "k"_us;        
    };

    struct mega
    {
        static constexpr long double factor = 1e6L;
        static constexpr auto symbol = "M"_us;        
    };

    struct giga
    {
        static constexpr long double factor = 1e9L;
        static constexpr auto symbol = "G"_us;        
    };

    struct tera
    {
        static constexpr long double factor = 1e12L;
        static constexpr auto symbol = "T"_us;        
    };

    struct peta
    {
        static constexpr long double factor = 1e15L;
        static constexpr auto symbol = "P"_us;        
    };

    struct exa
    {
        static constexpr long double factor = 1e18L;
        static constexpr auto symbol = "E"_us;        
    };   

    struct zetta
    {
        static constexpr long double factor = 1e21L;
        static constexpr auto symbol = "Z"_us;        
    };   

    struct yotta
    {
        static constexpr long double factor = 1e24L;
        static constexpr auto symbol = "Y"_us;        
    };   

    struct ronna
    {
        static constexpr long double factor = 1e27L;
        static constexpr auto symbol = "R"_us;        
    };

    struct quetta
    {
        static constexpr long double factor = 1e30L;
        static constexpr auto symbol = "Q"_us;        
    };

}


#endif //__ZOLLSTOCK_SI_PREFIXES_HPP__