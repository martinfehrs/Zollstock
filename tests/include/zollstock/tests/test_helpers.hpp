#ifndef __ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__


#define ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_CONSTANTS(type_prefix, base_type, base_symbol) \
    REQUIRE(q##base_symbol   == type_prefix##quekto##base_type{}); \
    REQUIRE(r##base_symbol   == type_prefix##ronto##base_type {}); \
    REQUIRE(y##base_symbol   == type_prefix##yokto##base_type {}); \
    REQUIRE(z##base_symbol   == type_prefix##zepto##base_type {}); \
    REQUIRE(a##base_symbol   == type_prefix##atto##base_type  {}); \
    REQUIRE(f##base_symbol   == type_prefix##femto##base_type {}); \
    REQUIRE(p##base_symbol   == type_prefix##pico##base_type  {}); \
    REQUIRE(mic##base_symbol == type_prefix##micro##base_type {}); \
    REQUIRE(m##base_symbol   == type_prefix##milli##base_type {}); \
    REQUIRE(c##base_symbol   == type_prefix##centi##base_type {}); \
    REQUIRE(da##base_symbol  == type_prefix##deca##base_type  {}); \
    REQUIRE(h##base_symbol   == type_prefix##hecto##base_type {}); \
    REQUIRE(k##base_symbol   == type_prefix##kilo##base_type  {}); \
    REQUIRE(M##base_symbol   == type_prefix##mega##base_type  {}); \
    REQUIRE(G##base_symbol   == type_prefix##giga##base_type  {}); \
    REQUIRE(T##base_symbol   == type_prefix##tera##base_type  {}); \
    REQUIRE(P##base_symbol   == type_prefix##peta##base_type  {}); \
    REQUIRE(E##base_symbol   == type_prefix##exa##base_type   {}); \
    REQUIRE(Z##base_symbol   == type_prefix##zetta##base_type {}); \
    REQUIRE(Y##base_symbol   == type_prefix##yotta##base_type {}); \
    REQUIRE(R##base_symbol   == type_prefix##ronna##base_type {}); \
    REQUIRE(Q##base_symbol   == type_prefix##quetta##base_type{}); \

#define ZOLLSTOCK_TESTS_TEST_SI_CONSTANTS(type_prefix, base_type, base_symbol) \
    REQUIRE(base_symbol == type_prefix##base_type{}); \
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_CONSTANTS(type_prefix, base_type, base_symbol) \

#define ZOLLSTOCK_TESTS_TEST_LITERAL(symbol) \
    REQUIRE(1.0_##symbol   == 1.0 * symbol); \
    REQUIRE(1_##symbol     == 1.0 * symbol); \

#define ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_LITERALS(base_symbol) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(q##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(r##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(y##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(z##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(a##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(f##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(p##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(n##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(mic##base_symbol) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(m##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(c##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(d##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(da##base_symbol ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(h##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(k##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(M##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(G##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(T##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(P##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(E##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(Z##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(Y##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(R##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(Q##base_symbol  ) \

#define ZOLLSTOCK_TESTS_TEST_SI_LITERALS(base_symbol) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(base_symbol) \
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_LITERALS(base_symbol) \


#endif //__ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__
