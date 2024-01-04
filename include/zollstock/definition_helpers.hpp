#ifndef __ZOLLSTOCK_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_DEFINITION_HELPERS_HPP__


#define ZOLLSTOCK_DEFINE_LITERAL(type, symbol) \
    [[nodiscard]] constexpr auto operator""_##symbol(unsigned long long int value) noexcept \
    { \
        return scalar<type>{ static_cast<double>(value) }; \
    } \
    \
    [[nodiscard]] constexpr auto operator""_##symbol(long double value) noexcept \
    { \
        return scalar<type>{ static_cast<double>(value) }; \
    } \

#define ZOLLSTOCK_DEFINE_SI_LITERALS(type_prefix, base_type, base_symbol) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##quekto##base_type, q##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##ronto##base_type , r##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##yokto##base_type , y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##zepto##base_type , z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##atto##base_type  , a##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##femto##base_type , f##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##pico##base_type  , p##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##nano##base_type  , n##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##micro##base_type , mic##base_symbol) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##milli##base_type , m##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##centi##base_type , c##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##deci##base_type  , d##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##base_type        , base_symbol     ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##deca##base_type  , da##base_symbol ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##hecto##base_type , h##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##kilo##base_type  , k##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##mega##base_type  , M##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##giga##base_type  , G##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##tera##base_type  , T##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##peta##base_type  , P##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##exa##base_type   , E##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##zetta##base_type , Z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##yotta##base_type , Y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##ronna##base_type , R##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(type_prefix##quetta##base_type, Q##base_symbol  ) \

#define ZOLLSTOCK_DEFINE_SI_CONSTANTS(type_prefix, base_type, base_symbol) \
    inline constexpr type_prefix##quekto##base_type q##base_symbol  {}; \
    inline constexpr type_prefix##ronto##base_type  r##base_symbol  {}; \
    inline constexpr type_prefix##yokto##base_type  y##base_symbol  {}; \
    inline constexpr type_prefix##zepto##base_type  z##base_symbol  {}; \
    inline constexpr type_prefix##atto##base_type   a##base_symbol  {}; \
    inline constexpr type_prefix##femto##base_type  f##base_symbol  {}; \
    inline constexpr type_prefix##pico##base_type   p##base_symbol  {}; \
    inline constexpr type_prefix##nano##base_type   n##base_symbol  {}; \
    inline constexpr type_prefix##micro##base_type  mic##base_symbol{}; \
    inline constexpr type_prefix##milli##base_type  m##base_symbol  {}; \
    inline constexpr type_prefix##centi##base_type  c##base_symbol  {}; \
    inline constexpr type_prefix##deci##base_type   d##base_symbol  {}; \
    inline constexpr type_prefix##base_type         base_symbol     {}; \
    inline constexpr type_prefix##deca##base_type   da##base_symbol {}; \
    inline constexpr type_prefix##hecto##base_type  h##base_symbol  {}; \
    inline constexpr type_prefix##kilo##base_type   k##base_symbol  {}; \
    inline constexpr type_prefix##mega##base_type   M##base_symbol  {}; \
    inline constexpr type_prefix##giga##base_type   G##base_symbol  {}; \
    inline constexpr type_prefix##tera##base_type   T##base_symbol  {}; \
    inline constexpr type_prefix##peta##base_type   P##base_symbol  {}; \
    inline constexpr type_prefix##exa##base_type    E##base_symbol  {}; \
    inline constexpr type_prefix##zetta##base_type  Z##base_symbol  {}; \
    inline constexpr type_prefix##yotta##base_type  Y##base_symbol  {}; \
    inline constexpr type_prefix##ronna##base_type  R##base_symbol  {}; \
    inline constexpr type_prefix##quetta##base_type Q##base_symbol  {}; \


#endif //__ZOLLSTOCK_DEFINITION_HELPERS_HPP__
