#ifndef __ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__


#define TEST_BASE_TYPE(base_type, dimension_, symbol_, factor_) \
{                                                               \
    using namespace zollstock;                                  \
                                                                \
    STATIC_REQUIRE(base_type::dimension == dimension_);         \
    STATIC_REQUIRE(base_type::symbol   == symbol_ );            \
    STATIC_REQUIRE(base_type::factor   == factor_ );            \
}                                                               \

#define TEST_BASE_TYPES_UNPREFIXED(base_type, dimension, symbol, factor) \
    TEST_BASE_TYPE(base_type, dimension, symbol, factor)                 \

#define TEST_BASE_TYPES_PREFIXED(base_type, dimension, symbol, factor)               \
{                                                                                    \
    using namespace zollstock;                                                       \
                                                                                     \
    TEST_BASE_TYPE(quecto##base_type, dimension, "q"_us   + symbol, 1e-30L * factor) \
    TEST_BASE_TYPE(ronto##base_type , dimension, "r"_us   + symbol, 1e-27L * factor) \
    TEST_BASE_TYPE(yocto##base_type , dimension, "y"_us   + symbol, 1e-24L * factor) \
    TEST_BASE_TYPE(zepto##base_type , dimension, "z"_us   + symbol, 1e-21L * factor) \
    TEST_BASE_TYPE(atto##base_type  , dimension, "a"_us   + symbol, 1e-18L * factor) \
    TEST_BASE_TYPE(femto##base_type , dimension, "f"_us   + symbol, 1e-15L * factor) \
    TEST_BASE_TYPE(pico##base_type  , dimension, "p"_us   + symbol, 1e-12L * factor) \
    TEST_BASE_TYPE(nano##base_type  , dimension, "n"_us   + symbol, 1e-9L  * factor) \
    TEST_BASE_TYPE(micro##base_type , dimension, "mic"_us + symbol, 1e-6L  * factor) \
    TEST_BASE_TYPE(milli##base_type , dimension, "m"_us   + symbol, 1e-3L  * factor) \
    TEST_BASE_TYPE(centi##base_type , dimension, "c"_us   + symbol, 1e-2L  * factor) \
    TEST_BASE_TYPE(deci##base_type  , dimension, "d"_us   + symbol, 1e-1L  * factor) \
    TEST_BASE_TYPE(deca##base_type  , dimension, "da"_us  + symbol, 1e1L   * factor) \
    TEST_BASE_TYPE(hecto##base_type , dimension, "h"_us   + symbol, 1e2L   * factor) \
    TEST_BASE_TYPE(kilo##base_type  , dimension, "k"_us   + symbol, 1e3L   * factor) \
    TEST_BASE_TYPE(mega##base_type  , dimension, "M"_us   + symbol, 1e6L   * factor) \
    TEST_BASE_TYPE(giga##base_type  , dimension, "G"_us   + symbol, 1e9L   * factor) \
    TEST_BASE_TYPE(tera##base_type  , dimension, "T"_us   + symbol, 1e12L  * factor) \
    TEST_BASE_TYPE(peta##base_type  , dimension, "P"_us   + symbol, 1e15L  * factor) \
    TEST_BASE_TYPE(exa##base_type   , dimension, "E"_us   + symbol, 1e18L  * factor) \
    TEST_BASE_TYPE(zetta##base_type , dimension, "Z"_us   + symbol, 1e21L  * factor) \
    TEST_BASE_TYPE(yotta##base_type , dimension, "Y"_us   + symbol, 1e24L  * factor) \
    TEST_BASE_TYPE(ronna##base_type , dimension, "R"_us   + symbol, 1e27L  * factor) \
    TEST_BASE_TYPE(quetta##base_type, dimension, "Q"_us   + symbol, 1e30L  * factor) \
}                                                                                    \

#define TEST_BASE_TYPES_ALL(base_type, dimension, symbol, factor)    \
    TEST_BASE_TYPES_UNPREFIXED(base_type, dimension, symbol, factor) \
    TEST_BASE_TYPES_PREFIXED(base_type, dimension, symbol, factor)   \

#define TEST_BASE_TYPES(select, base_type, dimension, symbol, factor) \
    TEST_BASE_TYPES_##select(base_type, dimension, symbol, factor)    \


#endif //__ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__
