#ifndef __ZOLLSTOCK_CONSTANT_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_CONSTANT_DEFINITION_HELPERS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/si_prefixes.hpp>


#define ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimension, symbol, factor) \
    inline constexpr ::zollstock::unit<                                \
        ::zollstock::dimensions::dimension,                            \
        #symbol,                                                       \
        factor                                                         \
    > symbol{};                                                        \

#define ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, si_prefix) \
    inline constexpr auto& si_prefix##base_symbol = ::zollstock::prefixed_unit_v< \
        ::zollstock::dimensions::dimension,                                       \
        #base_symbol,                                                             \
        ::zollstock::si_prefixes::si_prefix                                       \
    >;                                                                            \

#define ZOLLSTOCK_DEFINE_PREFIXED_BASE_SI_UNIT_CONSTANTS(dimension, base_symbol) \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, q  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, r  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, y  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, z  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, a  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, f  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, p  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, n  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, mic)          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, m  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, c  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, d  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, da )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, h  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, k  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, M  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, G  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, T  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, P  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, E  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, Z  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, Y  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, R  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, Q  )          \

#define ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(dimension, base_symbol)      \
    ZOLLSTOCK_DEFINE_PREFIXED_BASE_SI_UNIT_CONSTANTS(dimension, base_symbol) \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimension, base_symbol, 1.0L)        \

#define ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(base_symbol, exponent)                         \
    inline constexpr auto base_symbol##exponent = ::zollstock::pow_v<base_symbol, exponent>; \

#define ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, si_prefix) \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(si_prefix##base_symbol, exponent)        \

#define ZOLLSTOCK_DEFINE_PREFIXED_RAISED_SI_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, q  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, r  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, y  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, z  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, a  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, f  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, p  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, n  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, mic)          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, m  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, c  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, d  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, da )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, h  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, k  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, M  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, G  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, T  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, P  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, E  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, Z  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, Y  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, R  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, Q  )          \

#define ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANTS(base_symbol, exponent)          \
    ZOLLSTOCK_DEFINE_PREFIXED_RAISED_SI_UNIT_CONSTANTS(base_symbol, exponent)     \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(base_symbol, exponent)                  \


#endif //__ZOLLSTOCK_CONSTANT_DEFINITION_HELPERS_HPP__
