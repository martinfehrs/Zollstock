#ifndef __ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__
#define __ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__


#define TEST_BASE_TYPE(base_type, quantity_, symbol_, factor_) \
{                                                              \
    using namespace zollstock;                                 \
                                                               \
    STATIC_REQUIRE(base_type::quantity == quantity_);          \
    STATIC_REQUIRE(base_type::symbol   == symbol_ );           \
    STATIC_REQUIRE(base_type::factor   == factor_ );           \
}                                                              \

#define TEST_BASE_TYPES_UNPREFIXED(base_type, quantity, symbol, factor) \
    TEST_BASE_TYPE(base_type, quantity, symbol, factor)                 \

#define TEST_BASE_TYPES_PREFIXED(base_type, quantity, symbol, factor)               \
{                                                                                   \
    using namespace zollstock;                                                      \
                                                                                    \
    TEST_BASE_TYPE(quecto##base_type, quantity, "q"_us   + symbol, 1e-30L * factor) \
    TEST_BASE_TYPE(ronto##base_type , quantity, "r"_us   + symbol, 1e-27L * factor) \
    TEST_BASE_TYPE(yocto##base_type , quantity, "y"_us   + symbol, 1e-24L * factor) \
    TEST_BASE_TYPE(zepto##base_type , quantity, "z"_us   + symbol, 1e-21L * factor) \
    TEST_BASE_TYPE(atto##base_type  , quantity, "a"_us   + symbol, 1e-18L * factor) \
    TEST_BASE_TYPE(femto##base_type , quantity, "f"_us   + symbol, 1e-15L * factor) \
    TEST_BASE_TYPE(pico##base_type  , quantity, "p"_us   + symbol, 1e-12L * factor) \
    TEST_BASE_TYPE(nano##base_type  , quantity, "n"_us   + symbol, 1e-9L  * factor) \
    TEST_BASE_TYPE(micro##base_type , quantity, "mic"_us + symbol, 1e-6L  * factor) \
    TEST_BASE_TYPE(milli##base_type , quantity, "m"_us   + symbol, 1e-3L  * factor) \
    TEST_BASE_TYPE(centi##base_type , quantity, "c"_us   + symbol, 1e-2L  * factor) \
    TEST_BASE_TYPE(deci##base_type  , quantity, "d"_us   + symbol, 1e-1L  * factor) \
    TEST_BASE_TYPE(deca##base_type  , quantity, "da"_us  + symbol, 1e1L   * factor) \
    TEST_BASE_TYPE(hecto##base_type , quantity, "h"_us   + symbol, 1e2L   * factor) \
    TEST_BASE_TYPE(kilo##base_type  , quantity, "k"_us   + symbol, 1e3L   * factor) \
    TEST_BASE_TYPE(mega##base_type  , quantity, "M"_us   + symbol, 1e6L   * factor) \
    TEST_BASE_TYPE(giga##base_type  , quantity, "G"_us   + symbol, 1e9L   * factor) \
    TEST_BASE_TYPE(tera##base_type  , quantity, "T"_us   + symbol, 1e12L  * factor) \
    TEST_BASE_TYPE(peta##base_type  , quantity, "P"_us   + symbol, 1e15L  * factor) \
    TEST_BASE_TYPE(exa##base_type   , quantity, "E"_us   + symbol, 1e18L  * factor) \
    TEST_BASE_TYPE(zetta##base_type , quantity, "Z"_us   + symbol, 1e21L  * factor) \
    TEST_BASE_TYPE(yotta##base_type , quantity, "Y"_us   + symbol, 1e24L  * factor) \
    TEST_BASE_TYPE(ronna##base_type , quantity, "R"_us   + symbol, 1e27L  * factor) \
    TEST_BASE_TYPE(quetta##base_type, quantity, "Q"_us   + symbol, 1e30L  * factor) \
}                                                                                   \

#define TEST_BASE_TYPES_ALL(base_type, quantity, symbol, factor)    \
    TEST_BASE_TYPES_UNPREFIXED(base_type, quantity, symbol, factor) \
    TEST_BASE_TYPES_PREFIXED(base_type, quantity, symbol, factor)   \

#define TEST_BASE_TYPES(select, base_type, quantity, symbol, factor) \
    TEST_BASE_TYPES_##select(base_type, quantity, symbol, factor)    \


#endif //__ZOLLSTOCK_TESTS_TYPE_TEST_HELPERS_HPP__
