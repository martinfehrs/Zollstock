#ifndef __ZOLLSTOCK_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_DEFINITION_HELPERS_HPP__


#define ZOLLSTOCK_DEFINE_LITERAL(symbol) \
    [[nodiscard]] constexpr auto operator""_##symbol(unsigned long long int value) noexcept \
    { \
        return scalar<symbol>{ static_cast<double>(value) }; \
    } \
    \
    [[nodiscard]] constexpr auto operator""_##symbol(long double value) noexcept \
    { \
        return scalar<symbol>{ static_cast<double>(value) }; \
    } \

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(base_symbol) \
    ZOLLSTOCK_DEFINE_LITERAL(q##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(r##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(a##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(f##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(p##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(n##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(mic##base_symbol) \
    ZOLLSTOCK_DEFINE_LITERAL(m##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(c##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(d##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(da##base_symbol ) \
    ZOLLSTOCK_DEFINE_LITERAL(h##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(k##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(M##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(G##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(T##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(P##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(E##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(Z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(Y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(R##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(Q##base_symbol  ) \

#define ZOLLSTOCK_DEFINE_SI_LITERALS(base_symbol) \
    ZOLLSTOCK_DEFINE_LITERAL(base_symbol) \
    ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(base_symbol)

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_CONSTANTS(type_prefix, base_type, base_symbol) \
    inline constexpr type_prefix##quecto##base_type q##base_symbol  {}; \
    inline constexpr type_prefix##ronto##base_type  r##base_symbol  {}; \
    inline constexpr type_prefix##yocto##base_type  y##base_symbol  {}; \
    inline constexpr type_prefix##zepto##base_type  z##base_symbol  {}; \
    inline constexpr type_prefix##atto##base_type   a##base_symbol  {}; \
    inline constexpr type_prefix##femto##base_type  f##base_symbol  {}; \
    inline constexpr type_prefix##pico##base_type   p##base_symbol  {}; \
    inline constexpr type_prefix##nano##base_type   n##base_symbol  {}; \
    inline constexpr type_prefix##micro##base_type  mic##base_symbol{}; \
    inline constexpr type_prefix##milli##base_type  m##base_symbol  {}; \
    inline constexpr type_prefix##centi##base_type  c##base_symbol  {}; \
    inline constexpr type_prefix##deci##base_type   d##base_symbol  {}; \
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

#define ZOLLSTOCK_DEFINE_SI_CONSTANTS(type_prefix, base_type, base_symbol) \
    ZOLLSTOCK_DEFINE_SI_PREFIXED_CONSTANTS(type_prefix, base_type, base_symbol) \
    inline constexpr type_prefix##base_type base_symbol{};


#endif //__ZOLLSTOCK_DEFINITION_HELPERS_HPP__
