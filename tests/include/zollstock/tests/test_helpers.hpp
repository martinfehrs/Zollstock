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


#endif //__ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__
