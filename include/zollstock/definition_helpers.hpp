#ifndef __ZOLLSTOCK_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_DEFINITION_HELPERS_HPP__


#define ZOLLSTOCK_DEFINE_LITERAL(suffix, constant)                                              \
    [[nodiscard]] consteval auto operator""_##suffix(unsigned long long int value) noexcept     \
    {                                                                                           \
        return scalar<constant, int>{ value };                                                \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_l_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        return scalar<constant, long int>{ value };                                           \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ll_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        return scalar<constant, long long int>{ value };                                      \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_u_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        return scalar<constant, unsigned int>{ value };                                       \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ul_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        return scalar<constant, unsigned long int>{ value };                                  \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ull_##suffix(unsigned long long int value) noexcept \
    {                                                                                           \
        return scalar<constant, unsigned long long int>{ value };                             \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_##suffix(long double value) noexcept                \
    {                                                                                           \
        return scalar<constant, double>{ value };                                             \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_f_##suffix(long double value) noexcept              \
    {                                                                                           \
        return scalar<constant, float>{ value };                                              \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_l_##suffix(long double value) noexcept              \
    {                                                                                           \
        return scalar<constant, long double>{ value };                                        \
    }                                                                                           \

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(base_symbol)       \
    ZOLLSTOCK_DEFINE_LITERAL(q##base_symbol  , q##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(r##base_symbol  , r##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(y##base_symbol  , y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(z##base_symbol  , z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(a##base_symbol  , a##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(f##base_symbol  , f##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(p##base_symbol  , p##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(n##base_symbol  , n##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(mic##base_symbol, mic##base_symbol) \
    ZOLLSTOCK_DEFINE_LITERAL(m##base_symbol  , m##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(c##base_symbol  , c##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(d##base_symbol  , d##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(da##base_symbol , da##base_symbol ) \
    ZOLLSTOCK_DEFINE_LITERAL(h##base_symbol  , h##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(k##base_symbol  , k##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(M##base_symbol  , M##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(G##base_symbol  , G##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(T##base_symbol  , T##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(P##base_symbol  , P##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(E##base_symbol  , E##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(Z##base_symbol  , Z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(Y##base_symbol  , Y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(R##base_symbol  , R##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERAL(Q##base_symbol  , Q##base_symbol  ) \

#define ZOLLSTOCK_DEFINE_SI_LITERALS(base_symbol)      \
    ZOLLSTOCK_DEFINE_LITERAL(base_symbol, base_symbol) \
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

#define ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(base_symbol, exponent)                       \
    inline constexpr auto base_symbol##exponent = zollstock::pow_v<base_symbol, exponent>; \

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_RAISED_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(q##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(r##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(y##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(z##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(a##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(f##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(p##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(n##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(mic##base_symbol, exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(m##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(c##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(d##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(da##base_symbol , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(h##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(k##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(M##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(G##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(T##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(P##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(E##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(Z##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(Y##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(R##base_symbol  , exponent)             \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(Q##base_symbol  , exponent)             \

#define ZOLLSTOCK_DEFINE_SI_RAISED_UNIT_CONSTANTS(base_symbol, exponent)      \
    ZOLLSTOCK_DEFINE_SI_PREFIXED_RAISED_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(base_symbol, exponent)              \


#endif //__ZOLLSTOCK_DEFINITION_HELPERS_HPP__
