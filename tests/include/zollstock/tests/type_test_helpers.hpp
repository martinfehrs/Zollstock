#ifndef __ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__


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


#endif //__ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__
