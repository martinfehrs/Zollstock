#ifndef __ZOLLSTOCK_TESTS_LITERAL_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_LITERAL_TEST_HELPERS_HPP__


#include <zollstock/tests/preprocessor_utils.hpp>


#define TEST_LITERAL(literal, constant)              \
    STATIC_REQUIRE(1.0_##literal == 1.0 * constant); \
    STATIC_REQUIRE(1_##literal   == 1   * constant); \

#define TEST_LITERALS_UNPREFIXED(literal, constant) \
    TEST_LITERAL(literal, constant)                 \

#define TEST_LITERALS_PREFIXED(literal, constant) \
    TEST_LITERAL(q##literal  , q##constant  )     \
    TEST_LITERAL(r##literal  , r##constant  )     \
    TEST_LITERAL(y##literal  , y##constant  )     \
    TEST_LITERAL(z##literal  , z##constant  )     \
    TEST_LITERAL(a##literal  , a##constant  )     \
    TEST_LITERAL(f##literal  , f##constant  )     \
    TEST_LITERAL(p##literal  , p##constant  )     \
    TEST_LITERAL(n##literal  , n##constant  )     \
    TEST_LITERAL(mic##literal, mic##constant)     \
    TEST_LITERAL(m##literal  , m##constant  )     \
    TEST_LITERAL(c##literal  , c##constant  )     \
    TEST_LITERAL(d##literal  , d##constant  )     \
    TEST_LITERAL(da##literal , da##constant )     \
    TEST_LITERAL(h##literal  , h##constant  )     \
    TEST_LITERAL(k##literal  , k##constant  )     \
    TEST_LITERAL(M##literal  , M##constant  )     \
    TEST_LITERAL(G##literal  , G##constant  )     \
    TEST_LITERAL(T##literal  , T##constant  )     \
    TEST_LITERAL(P##literal  , P##constant  )     \
    TEST_LITERAL(E##literal  , E##constant  )     \
    TEST_LITERAL(Z##literal  , Z##constant  )     \
    TEST_LITERAL(Y##literal  , Y##constant  )     \
    TEST_LITERAL(R##literal  , R##constant  )     \
    TEST_LITERAL(Q##literal  , Q##constant  )     \

#define TEST_LITERALS_ALL(literal, constant)      \
    TEST_LITERALS_PREFIXED(literal, constant)     \
    TEST_LITERALS_UNPREFIXED(literal, constant)   \

#define TEST_LITERALS_2(select, literal, constant) \
    TEST_LITERALS_##select(literal, constant)      \

#define TEST_LITERALS_1(select, literal)           \
    TEST_LITERALS_##select(literal, literal)       \

#define TEST_LITERALS(select, ...) \
    CONCAT(TEST_LITERALS_, COUNT_ARGS(__VA_ARGS__))(select, __VA_ARGS__)


#endif //__ZOLLSTOCK_TESTS_LITERAL_TEST_HELPERS_HPP__
