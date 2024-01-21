#ifndef __ZOLLSTOCK_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_DEFINITION_HELPERS_HPP__


#define ZOLLSTOCK_DEFINE_LITERAL(symbol)                                                    \
    [[nodiscard]] constexpr auto operator""_##symbol(unsigned long long int value) noexcept \
    {                                                                                       \
        return scalar<symbol>{ static_cast<double>(value) };                                \
    }                                                                                       \
                                                                                            \
    [[nodiscard]] constexpr auto operator""_##symbol(long double value) noexcept            \
    {                                                                                       \
        return scalar<symbol>{ static_cast<double>(value) };                                \
    }                                                                                       \

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(base_symbol) \
    ZOLLSTOCK_DEFINE_LITERAL(q##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(r##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(y##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(z##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(a##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(f##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(p##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(n##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(mic##base_symbol)             \
    ZOLLSTOCK_DEFINE_LITERAL(m##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(c##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(d##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(da##base_symbol )             \
    ZOLLSTOCK_DEFINE_LITERAL(h##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(k##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(M##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(G##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(T##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(P##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(E##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(Z##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(Y##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(R##base_symbol  )             \
    ZOLLSTOCK_DEFINE_LITERAL(Q##base_symbol  )             \

#define ZOLLSTOCK_DEFINE_SI_LITERALS(base_symbol)      \
    ZOLLSTOCK_DEFINE_LITERAL(base_symbol)              \
    ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(base_symbol) \

#define ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(type, symbol) \
    inline constexpr type symbol{};                       \

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_BASE_UNIT_CONSTANTS(base_type, base_symbol) \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(quecto##base_type, q##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(ronto##base_type , r##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(yocto##base_type , y##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(zepto##base_type , z##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(atto##base_type  , a##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(femto##base_type , f##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(pico##base_type  , p##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(nano##base_type  , n##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(micro##base_type , mic##base_symbol)     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(milli##base_type , m##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(centi##base_type , c##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(deci##base_type  , d##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(deca##base_type  , da##base_symbol )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(hecto##base_type , h##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(kilo##base_type  , k##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(mega##base_type  , M##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(giga##base_type  , G##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(tera##base_type  , T##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(peta##base_type  , P##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(exa##base_type   , E##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(zetta##base_type , Z##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(yotta##base_type , Y##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(ronna##base_type , R##base_symbol  )     \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(quetta##base_type, Q##base_symbol  )     \

#define ZOLLSTOCK_DEFINE_SI_BASE_UNIT_CONSTANTS(base_type, base_symbol)      \
    ZOLLSTOCK_DEFINE_SI_PREFIXED_BASE_UNIT_CONSTANTS(base_type, base_symbol) \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(base_type, base_symbol)              \

#define ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(base_symbol, exponent)               \
    inline constexpr auto base_symbol##exponent = zollstock::pow<exponent>(base_symbol); \

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_DERIVED_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(q##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(r##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(y##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(z##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(a##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(f##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(p##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(n##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(mic##base_symbol, exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(m##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(c##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(d##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(da##base_symbol , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(h##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(k##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(M##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(G##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(T##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(P##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(E##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(Z##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(Y##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(R##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(Q##base_symbol  , exponent)             \

#define ZOLLSTOCK_DEFINE_SI_DERIVED_UNIT_CONSTANTS(base_symbol, exponent)      \
    ZOLLSTOCK_DEFINE_SI_PREFIXED_DERIVED_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_DEFINE_DERIVED_UNIT_CONSTANT(base_symbol, exponent)              \


#endif //__ZOLLSTOCK_DEFINITION_HELPERS_HPP__
