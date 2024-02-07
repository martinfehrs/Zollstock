#ifndef __ZOLLSTOCK_TESTS_LITERAL_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_LITERAL_TEST_HELPERS_HPP__


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


#endif //__ZOLLSTOCK_TESTS_LITERAL_TEST_HELPERS_HPP__
