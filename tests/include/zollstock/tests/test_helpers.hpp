#ifndef __ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/unit_algorithms.hpp>


using namespace zollstock;


#define TEST_BASE_UNIT_CONSTANT(type, symbol) \
    STATIC_REQUIRE(symbol == type{});         \

#define TEST_BASE_UNIT_CONSTANTS_UNPREFIXED(base_type, base_symbol) \
    TEST_BASE_UNIT_CONSTANT(base_type, base_symbol);                \

#define TEST_BASE_UNIT_CONSTANTS_PREFIXED(base_type, base_symbol) \
    TEST_BASE_UNIT_CONSTANT(quecto##base_type, q##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(ronto##base_type , r##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(yocto##base_type , y##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(zepto##base_type , z##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(atto##base_type  , a##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(femto##base_type , f##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(pico##base_type  , p##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(micro##base_type , mic##base_symbol); \
    TEST_BASE_UNIT_CONSTANT(milli##base_type , m##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(centi##base_type , c##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(deca##base_type  , da##base_symbol ); \
    TEST_BASE_UNIT_CONSTANT(hecto##base_type , h##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(kilo##base_type  , k##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(mega##base_type  , M##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(giga##base_type  , G##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(tera##base_type  , T##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(peta##base_type  , P##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(exa##base_type   , E##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(zetta##base_type , Z##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(yotta##base_type , Y##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(ronna##base_type , R##base_symbol  ); \
    TEST_BASE_UNIT_CONSTANT(quetta##base_type, Q##base_symbol  ); \

#define TEST_BASE_UNIT_CONSTANTS_ALL(base_type, base_symbol)    \
    TEST_BASE_UNIT_CONSTANTS_UNPREFIXED(base_type, base_symbol) \
    TEST_BASE_UNIT_CONSTANTS_PREFIXED(base_type, base_symbol)   \

#define TEST_BASE_UNIT_CONSTANTS(select, base_type, base_symbol) \
    TEST_BASE_UNIT_CONSTANTS_##select(base_type, base_symbol)    \



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



void test_mixed_division_unit_constant(auto unit_1, auto unit_2)
{
    static_assert(unit_1 != unit_2);

    CAPTURE(unit_1, unit_2);

    static constexpr auto mixed = unit_1 / unit_2;

    STATIC_REQUIRE(type_of(mixed)     == unit_type::product                       );
    STATIC_REQUIRE(mixed.base_unit_1  == unit_1                                   );
    STATIC_REQUIRE(mixed.base_unit_2  == pow_v<unit_2, -1>                        );
    STATIC_REQUIRE(unit_length(mixed) == unit_length(unit_1) / unit_length(unit_2));
    STATIC_REQUIRE(unit_time  (mixed) == unit_time  (unit_1) / unit_time  (unit_2));
    STATIC_REQUIRE(unit_angle (mixed) == unit_angle (unit_1) / unit_angle (unit_2));
}

#define TEST_MIXED_DIVISION_UNIT_CONSTANT(symbol_1, symbol_2) \
    test_mixed_division_unit_constant(symbol_1, symbol_2);                    \

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


#define TEST_LITERAL(symbol)                        \
    STATIC_REQUIRE(1.0_##symbol   == 1.0 * symbol); \
    STATIC_REQUIRE(1_##symbol     == 1   * symbol); \

#define TEST_LITERALS_UNPREFIXED(base_symbol) \
    TEST_LITERAL(base_symbol)                 \

#define TEST_LITERALS_PREFIXED(base_symbol) \
    TEST_LITERAL(q##base_symbol  )          \
    TEST_LITERAL(r##base_symbol  )          \
    TEST_LITERAL(y##base_symbol  )          \
    TEST_LITERAL(z##base_symbol  )          \
    TEST_LITERAL(a##base_symbol  )          \
    TEST_LITERAL(f##base_symbol  )          \
    TEST_LITERAL(p##base_symbol  )          \
    TEST_LITERAL(n##base_symbol  )          \
    TEST_LITERAL(mic##base_symbol)          \
    TEST_LITERAL(m##base_symbol  )          \
    TEST_LITERAL(c##base_symbol  )          \
    TEST_LITERAL(d##base_symbol  )          \
    TEST_LITERAL(da##base_symbol )          \
    TEST_LITERAL(h##base_symbol  )          \
    TEST_LITERAL(k##base_symbol  )          \
    TEST_LITERAL(M##base_symbol  )          \
    TEST_LITERAL(G##base_symbol  )          \
    TEST_LITERAL(T##base_symbol  )          \
    TEST_LITERAL(P##base_symbol  )          \
    TEST_LITERAL(E##base_symbol  )          \
    TEST_LITERAL(Z##base_symbol  )          \
    TEST_LITERAL(Y##base_symbol  )          \
    TEST_LITERAL(R##base_symbol  )          \
    TEST_LITERAL(Q##base_symbol  )          \

#define TEST_LITERALS_ALL(base_symbol)    \
    TEST_LITERALS_PREFIXED(base_symbol)   \
    TEST_LITERALS_UNPREFIXED(base_symbol) \

#define TEST_LITERALS(select, base_symbol) \
    TEST_LITERALS_##select(base_symbol)    \



#define TEST_TYPE(quantity, type, factor_, symbol_)           \
    STATIC_REQUIRE(type::quantity.exponent == 1            ); \
    STATIC_REQUIRE(type::quantity.factor   == factor_      ); \
    STATIC_REQUIRE(type::quantity.symbol   == #symbol_##_us); \

#define TEST_TYPES_UNPREFIXED(quantity, base_type, base_factor, base_symbol) \
    TEST_TYPE(quantity, base_type, base_factor, base_symbol)                 \

#define TEST_TYPES_PREFIXED(quantity, base_type, base_factor, base_symbol)         \
    TEST_TYPE(quantity, quecto##base_type, 1e-30L * base_factor, q##base_symbol  ) \
    TEST_TYPE(quantity, ronto##base_type , 1e-27L * base_factor, r##base_symbol  ) \
    TEST_TYPE(quantity, yocto##base_type , 1e-24L * base_factor, y##base_symbol  ) \
    TEST_TYPE(quantity, zepto##base_type , 1e-21L * base_factor, z##base_symbol  ) \
    TEST_TYPE(quantity, atto##base_type  , 1e-18L * base_factor, a##base_symbol  ) \
    TEST_TYPE(quantity, femto##base_type , 1e-15L * base_factor, f##base_symbol  ) \
    TEST_TYPE(quantity, pico##base_type  , 1e-12L * base_factor, p##base_symbol  ) \
    TEST_TYPE(quantity, nano##base_type  , 1e-9L  * base_factor, n##base_symbol  ) \
    TEST_TYPE(quantity, micro##base_type , 1e-6L  * base_factor, mic##base_symbol) \
    TEST_TYPE(quantity, milli##base_type , 1e-3L  * base_factor, m##base_symbol  ) \
    TEST_TYPE(quantity, centi##base_type , 1e-2L  * base_factor, c##base_symbol  ) \
    TEST_TYPE(quantity, deci##base_type  , 1e-1L  * base_factor, d##base_symbol  ) \
    TEST_TYPE(quantity, deca##base_type  , 1e1L   * base_factor, da##base_symbol ) \
    TEST_TYPE(quantity, hecto##base_type , 1e2L   * base_factor, h##base_symbol  ) \
    TEST_TYPE(quantity, kilo##base_type  , 1e3L   * base_factor, k##base_symbol  ) \
    TEST_TYPE(quantity, mega##base_type  , 1e6L   * base_factor, M##base_symbol  ) \
    TEST_TYPE(quantity, giga##base_type  , 1e9L   * base_factor, G##base_symbol  ) \
    TEST_TYPE(quantity, tera##base_type  , 1e12L  * base_factor, T##base_symbol  ) \
    TEST_TYPE(quantity, peta##base_type  , 1e15L  * base_factor, P##base_symbol  ) \
    TEST_TYPE(quantity, exa##base_type   , 1e18L  * base_factor, E##base_symbol  ) \
    TEST_TYPE(quantity, zetta##base_type , 1e21L  * base_factor, Z##base_symbol  ) \
    TEST_TYPE(quantity, yotta##base_type , 1e24L  * base_factor, Y##base_symbol  ) \
    TEST_TYPE(quantity, ronna##base_type , 1e27L  * base_factor, R##base_symbol  ) \
    TEST_TYPE(quantity, quetta##base_type, 1e30L  * base_factor, Q##base_symbol  ) \

#define TEST_TYPES_ALL(quantity, base_type, base_factor, base_symbol)    \
    TEST_TYPES_UNPREFIXED(quantity, base_type, base_factor, base_symbol) \
    TEST_TYPES_PREFIXED(quantity, base_type, base_factor, base_symbol)   \

#define TEST_TYPES(select, quantity, base_type, base_factor, base_symbol) \
    TEST_TYPES_##select(quantity, base_type, base_factor, base_symbol)    \

#endif //__ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__
