#ifndef __ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_TEST_HELPERS_HPP__


#define ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_BASE_UNIT_CONSTANTS(base_type, base_symbol) \
    STATIC_REQUIRE(q##base_symbol   == quecto##base_type{});                         \
    STATIC_REQUIRE(r##base_symbol   == ronto##base_type {});                         \
    STATIC_REQUIRE(y##base_symbol   == yocto##base_type {});                         \
    STATIC_REQUIRE(z##base_symbol   == zepto##base_type {});                         \
    STATIC_REQUIRE(a##base_symbol   == atto##base_type  {});                         \
    STATIC_REQUIRE(f##base_symbol   == femto##base_type {});                         \
    STATIC_REQUIRE(p##base_symbol   == pico##base_type  {});                         \
    STATIC_REQUIRE(mic##base_symbol == micro##base_type {});                         \
    STATIC_REQUIRE(m##base_symbol   == milli##base_type {});                         \
    STATIC_REQUIRE(c##base_symbol   == centi##base_type {});                         \
    STATIC_REQUIRE(da##base_symbol  == deca##base_type  {});                         \
    STATIC_REQUIRE(h##base_symbol   == hecto##base_type {});                         \
    STATIC_REQUIRE(k##base_symbol   == kilo##base_type  {});                         \
    STATIC_REQUIRE(M##base_symbol   == mega##base_type  {});                         \
    STATIC_REQUIRE(G##base_symbol   == giga##base_type  {});                         \
    STATIC_REQUIRE(T##base_symbol   == tera##base_type  {});                         \
    STATIC_REQUIRE(P##base_symbol   == peta##base_type  {});                         \
    STATIC_REQUIRE(E##base_symbol   == exa##base_type   {});                         \
    STATIC_REQUIRE(Z##base_symbol   == zetta##base_type {});                         \
    STATIC_REQUIRE(Y##base_symbol   == yotta##base_type {});                         \
    STATIC_REQUIRE(R##base_symbol   == ronna##base_type {});                         \
    STATIC_REQUIRE(Q##base_symbol   == quetta##base_type{});                         \

#define ZOLLSTOCK_TESTS_TEST_SI_BASE_UNIT_CONSTANTS(base_type, base_symbol)      \
    STATIC_REQUIRE(base_symbol == base_type{});                                  \
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_BASE_UNIT_CONSTANTS(base_type, base_symbol) \

#define ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(symbol, exponent) \
    STATIC_REQUIRE(symbol##exponent == zollstock::pow_v<symbol, exponent>);   \

#define ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_DERIVED_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(q##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(r##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(y##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(z##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(a##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(f##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(p##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(mic##base_symbol, exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(m##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(c##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(d##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(da##base_symbol , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(h##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(k##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(M##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(G##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(T##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(P##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(E##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(Z##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(Y##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(R##base_symbol  , exponent)             \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(Q##base_symbol  , exponent)             \

#define ZOLLSTOCK_TESTS_TEST_SI_DERIVED_UNIT_CONSTANTS(base_symbol, exponent)      \
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_DERIVED_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_TESTS_TEST_DERIVED_UNIT_CONSTANT(base_symbol, exponent)              \

#define ZOLLSTOCK_TESTS_TEST_LITERAL(symbol)        \
    STATIC_REQUIRE(1.0_##symbol   == 1.0 * symbol); \
    STATIC_REQUIRE(1_##symbol     == 1   * symbol); \

#define ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_LITERALS(base_symbol) \
    ZOLLSTOCK_TESTS_TEST_LITERAL(q##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(r##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(y##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(z##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(a##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(f##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(p##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(n##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(mic##base_symbol)             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(m##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(c##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(d##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(da##base_symbol )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(h##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(k##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(M##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(G##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(T##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(P##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(E##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(Z##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(Y##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(R##base_symbol  )             \
    ZOLLSTOCK_TESTS_TEST_LITERAL(Q##base_symbol  )             \

#define ZOLLSTOCK_TESTS_TEST_SI_LITERALS(base_symbol)      \
    ZOLLSTOCK_TESTS_TEST_LITERAL(base_symbol)              \
    ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_LITERALS(base_symbol) \

#define ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type, factor_, symbol_) \
    STATIC_REQUIRE(type::quantity.exponent == 1            );       \
    STATIC_REQUIRE(type::quantity.factor   == factor_      );       \
    STATIC_REQUIRE(type::quantity.symbol   == #symbol_##_us);       \

#define ZOLLSTOCK_TESTS_TEST_SI_PREFIXED_TYPES(quantity, type_prefix, base_type, base_factor, base_symbol)      \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##quecto##base_type, 1e-30L * base_factor, q##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##ronto##base_type , 1e-27L * base_factor, r##base_symbol  ) \
    ZOLLSTOCK_TESTS_TEST_TYPE(quantity, type_prefix##yocto##base_type , 1e-24L * base_factor, y##base_symbol  ) \
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
