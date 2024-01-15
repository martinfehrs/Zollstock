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


#define _ZOLLSTOCK_TESTS_MAKE_LENGTH_EXPONENTS()   quantity_exponents{ 1, 0, 0 }
#define _ZOLLSTOCK_TESTS_MAKE_TIME_EXPONENTS()     quantity_exponents{ 0, 1, 0 }
#define _ZOLLSTOCK_TESTS_MAKE_ANGLE_EXPONENTS()    quantity_exponents{ 0, 0, 1 }
#define _ZOLLSTOCK_TESTS_MAKE_AREA_EXPONENTS()     quantity_exponents{ 2, 0, 0 }
#define _ZOLLSTOCK_TESTS_MAKE_VOLUME_EXPONENTS()   quantity_exponents{ 3, 0, 0 }

#define _ZOLLSTOCK_TESTS_MAKE_LENGTH_FACTORS(factor)         quantity_factors{ factor, 0.0L  , 0.0L   }
#define _ZOLLSTOCK_TESTS_MAKE_TIME_FACTORS(factor)           quantity_factors{ 0.0L  , factor, 0.0L   }
#define _ZOLLSTOCK_TESTS_MAKE_ANGLE_FACTORS(factor)          quantity_factors{ 0.0L  , 0.0L  , factor }
#define _ZOLLSTOCK_TESTS_MAKE_AREA_FACTORS(factor)           quantity_factors{ factor, 0.0L  , 0.0L   }
#define _ZOLLSTOCK_TESTS_MAKE_VOLUME_FACTORS(factor)         quantity_factors{ factor, 0.0L  , 0.0L   }
#define _ZOLLSTOCK_TESTS_MAKE_VELOCITY_FACTORS(length, time) quantity_factors{ length, time  , 0.0L   }

#define _ZOLLSTOCK_TESTS_MAKE_LENGTH_SYMBOLS(symbol) quantity_symbols{ #symbol##_us, ""_us  , ""_us   }
#define _ZOLLSTOCK_TESTS_MAKE_TIME_SYMBOLS(symbol)   quantity_symbols{ ""_us  , #symbol##_us, ""_us   }
#define _ZOLLSTOCK_TESTS_MAKE_ANGLE_SYMBOLS(symbol)  quantity_symbols{ ""_us  , ""_us  , #symbol##_us }
#define _ZOLLSTOCK_TESTS_MAKE_AREA_SYMBOLS(symbol)   quantity_symbols{ #symbol##_us, ""_us  , ""_us   }
#define _ZOLLSTOCK_TESTS_MAKE_VOLUME_SYMBOLS(symbol) quantity_symbols{ #symbol##_us, ""_us  , ""_us   }


#define _ZOLLSTOCK_TESTS_MAKE_QUANTITY_EXPONENTS(quantity) _ZOLLSTOCK_TESTS_MAKE_##quantity##_EXPONENTS
#define _ZOLLSTOCK_TESTS_MAKE_QUANTITY_FACTORS(quantity)   _ZOLLSTOCK_TESTS_MAKE_##quantity##_FACTORS
#define _ZOLLSTOCK_TESTS_MAKE_QUANTITY_SYMBOLS(quantity)   _ZOLLSTOCK_TESTS_MAKE_##quantity##_SYMBOLS


#define ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type, factor, symbol) \
    REQUIRE(type::exponents == _ZOLLSTOCK_TESTS_MAKE_QUANTITY_EXPONENTS(quantity)()    ); \
    REQUIRE(type::factors   == _ZOLLSTOCK_TESTS_MAKE_QUANTITY_FACTORS(quantity)(factor)); \
    REQUIRE(type::symbols   == _ZOLLSTOCK_TESTS_MAKE_QUANTITY_SYMBOLS(quantity)(symbol)); \


#define ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_TYPES(quantity, type_prefix, base_type, base_factor, base_symbol) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##quekto##base_type, 1e-30L * base_factor, q##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##ronto##base_type , 1e-27L * base_factor, r##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##yokto##base_type , 1e-24L * base_factor, y##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##zepto##base_type , 1e-21L * base_factor, z##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##atto##base_type  , 1e-18L * base_factor, a##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##femto##base_type , 1e-15L * base_factor, f##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##pico##base_type  , 1e-12L * base_factor, p##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##nano##base_type  , 1e-9L  * base_factor, n##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##micro##base_type , 1e-6L  * base_factor, mic##base_symbol) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##milli##base_type , 1e-3L  * base_factor, m##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##centi##base_type , 1e-2L  * base_factor, c##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##deci##base_type  , 1e-1L  * base_factor, d##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##deca##base_type  , 1e1L   * base_factor, da##base_symbol ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##hecto##base_type , 1e2L   * base_factor, h##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##kilo##base_type  , 1e3L   * base_factor, k##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##mega##base_type  , 1e6L   * base_factor, M##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##giga##base_type  , 1e9L   * base_factor, G##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##tera##base_type  , 1e12L  * base_factor, T##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##peta##base_type  , 1e15L  * base_factor, P##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##exa##base_type   , 1e18L  * base_factor, E##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##zetta##base_type , 1e21L  * base_factor, Z##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##yotta##base_type , 1e24L  * base_factor, Y##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##ronna##base_type , 1e27L  * base_factor, R##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##quetta##base_type, 1e30L  * base_factor, Q##base_symbol  ) \

#define ZOLLSTOCK_TESTS_TEST_SI_TYPES(quantity, type_prefix, base_type, base_factor, base_symbol) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##base_type, base_factor, base_symbol)        \
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_TYPES(quantity, type_prefix, base_type, base_factor, base_symbol) \

#endif //__ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__
