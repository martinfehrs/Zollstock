#ifndef __ZOLLSTOCK_TESTS_CONSTANT_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_CONSTANT_TEST_HELPERS_HPP__


#include <zollstock/unit_concept.hpp>


#define TEST_BASE_UNIT_CONSTANT(symbol_, quantity_, factor_)        \
{                                                                   \
    using namespace zollstock;                                      \
                                                                    \
    static constexpr auto factor = std::get<0>(symbol_.factors);    \
                                                                    \
    STATIC_REQUIRE(factor.quantity       == quantity_t::quantity_); \
    STATIC_REQUIRE(factor.symbol         == #symbol_ );             \
    STATIC_REQUIRE(factor.scaling_factor == factor_ );              \
}

#define TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol_, quantity_, prefix)             \
{                                                                                   \
    using namespace zollstock;                                                      \
                                                                                    \
    static constexpr auto factor = std::get<0>(prefix##symbol_.factors);            \
                                                                                    \
    STATIC_REQUIRE(factor.quantity        == quantity_t::quantity_);                \
    STATIC_REQUIRE(factor.symbol         == si_prefixes::prefix.symbol + #symbol_); \
    STATIC_REQUIRE(factor.scaling_factor == si_prefixes::prefix.factor);            \
}

#define TEST_BASE_UNIT_CONSTANTS_UNPREFIXED(symbol, quantity) \
    TEST_BASE_UNIT_CONSTANT(symbol, quantity, 1.0L)           \

#define TEST_BASE_UNIT_CONSTANTS_PREFIXED(symbol, quantity)    \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, q  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, r  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, y  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, z  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, a  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, f  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, p  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, mic) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, m  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, c  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, da ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, h  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, k  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, M  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, G  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, T  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, P  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, E  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, Z  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, Y  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, R  ) \
    TEST_PREFIXED_BASE_SI_UNIT_CONSTANT(symbol, quantity, Q  ) \

#define TEST_BASE_UNIT_CONSTANTS_ALL(symbol, quantity)    \
    TEST_BASE_UNIT_CONSTANTS_UNPREFIXED(symbol, quantity) \
    TEST_BASE_UNIT_CONSTANTS_PREFIXED(symbol, quantity)   \

#define TEST_BASE_UNIT_CONSTANTS(select, symbol, quantity) \
    TEST_BASE_UNIT_CONSTANTS_##select(symbol, quantity)    \


#define TEST_RAISED_UNIT_CONSTANT(symbol, exponent)                         \
    STATIC_REQUIRE(symbol##exponent == zollstock::pow_v<symbol, exponent>); \

#define TEST_RAISED_UNIT_CONSTANTS_UNPREFIXED(symbol, exponent) \
    TEST_RAISED_UNIT_CONSTANT(symbol, exponent)                 \

#define TEST_RAISED_UNIT_CONSTANTS_PREFIXED(base_symbol, exponent) \
    TEST_RAISED_UNIT_CONSTANT(q##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(r##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(y##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(z##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(a##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(f##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(p##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(mic##base_symbol, exponent)          \
    TEST_RAISED_UNIT_CONSTANT(m##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(c##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(d##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(da##base_symbol , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(h##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(k##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(M##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(G##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(T##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(P##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(E##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(Z##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(Y##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(R##base_symbol  , exponent)          \
    TEST_RAISED_UNIT_CONSTANT(Q##base_symbol  , exponent)          \

#define TEST_RAISED_UNIT_CONSTANTS_ALL(base_symbol, exponent)    \
    TEST_RAISED_UNIT_CONSTANTS_UNPREFIXED(base_symbol, exponent) \
    TEST_RAISED_UNIT_CONSTANTS_PREFIXED(base_symbol, exponent)   \

#define TEST_RAISED_UNIT_CONSTANTS(select, base_symbol, exponent) \
    TEST_RAISED_UNIT_CONSTANTS_##select(base_symbol, exponent)    \



void test_mixed_division_unit_constant(
    zollstock::base_unit_c auto unit_1, zollstock::base_unit_c auto unit_2
)
{
    using namespace zollstock;

    static_assert(unit_1 != unit_2);

    CAPTURE(unit_1, unit_2);

    static constexpr auto mixed = unit_1 / unit_2;

    STATIC_REQUIRE(derived_unit_c<decltype(mixed)>);
    STATIC_REQUIRE(unit_product_head(mixed)  == unit_1);
    STATIC_REQUIRE(unit_product_head(unit_product_tail(mixed)) == pow_v<unit_2, -1>);
    STATIC_REQUIRE(tuple_contains(mixed.factors, std::get<0>(unit_1.factors)));
    STATIC_REQUIRE(tuple_contains(mixed.factors, std::get<0>(zollstock::pow_v<unit_2, -1>.factors)));
}

#define TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1, symbol_2) \
    test_mixed_division_unit_constant(symbol_1, symbol_2);    \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_UNPREFIXED(symbol_1, symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1, symbol_2);                           \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_UNPREFIXED(symbol_1, symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(q##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(r##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(y##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(z##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(a##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(f##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(p##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(n##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(mic##symbol_1, symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(m##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(c##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(d##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(da##symbol_1 , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(h##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(k##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(M##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(G##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(T##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(P##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(E##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(Z##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(Y##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(R##symbol_1  , symbol_2)                     \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(Q##symbol_1  , symbol_2)                     \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_ALL_UNPREFIXED(symbol_1, symbol_2)    \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_UNPREFIXED(symbol_1, symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_UNPREFIXED(symbol_1, symbol_2)   \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(symbol_1, symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , q##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , r##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , y##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , z##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , a##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , f##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , p##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , n##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , mic##symbol_2)                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , m##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , c##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , d##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , da##symbol_2 )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , h##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , k##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , M##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , G##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , T##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , P##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , E##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , Z##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , Y##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , R##symbol_2  )                    \
    TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1 , Q##symbol_2  )                    \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_ALL(symbol_1, symbol_2)    \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_UNPREFIXED(symbol_1, symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(symbol_1, symbol_2)   \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_PREFIXED(symbol_1, symbol_2)    \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(q##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(r##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(y##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(z##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(a##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(f##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(p##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(n##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(mic##symbol_1, symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(m##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(c##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(d##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(da##symbol_1 , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(h##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(k##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(M##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(G##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(T##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(P##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(E##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(Z##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(Y##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(R##symbol_1  , symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(Q##symbol_1  , symbol_2) \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_ALL_PREFIXED(symbol_1, symbol_2)    \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_PREFIXED(symbol_1, symbol_2)   \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(symbol_1, symbol_2) \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_ALL(symbol_1, symbol_2)    \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_PREFIXED(symbol_1, symbol_2)   \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_UNPREFIXED(symbol_1, symbol_2) \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS_ALL_ALL(symbol_1, symbol_2)           \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_PREFIXED(symbol_1, symbol_2)     \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_PREFIXED_UNPREFIXED(symbol_1, symbol_2)   \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_PREFIXED(symbol_1, symbol_2)   \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_UNPREFIXED_UNPREFIXED(symbol_1, symbol_2) \

#define TEST_MIXED_DIVISION_UNIT_CONSTANTS(select_1, select_2, symbol_1, symbol_2) \
    TEST_MIXED_DIVISION_UNIT_CONSTANTS_##select_1##_##select_2(symbol_1, symbol_2) \


#endif //__ZOLLSTOCK_TESTS_CONSTANT_TEST_HELPERS_HPP__
