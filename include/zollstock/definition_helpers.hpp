#ifndef __ZOLLSTOCK_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_DEFINITION_HELPERS_HPP__


#define ZOLLSTOCK_DEFINE_LITERAL(suffix, constant)                                              \
    [[nodiscard]] consteval auto operator""_##suffix(unsigned long long int value) noexcept     \
    {                                                                                           \
        return scalar<constant, int>{ narrow<int>(value) };                                     \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_l_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        return scalar<constant, long int>{ narrow<long int>(value) };                           \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ll_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        return scalar<constant, long long int>{ narrow<long long int>(value) };                 \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_u_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        return scalar<constant, unsigned int>{ narrow<unsigned int>(value) };                   \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ul_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        return scalar<constant, unsigned long int>{ narrow<unsigned long int>(value) };         \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ull_##suffix(unsigned long long int value) noexcept \
    {                                                                                           \
        return scalar<constant, unsigned long long int>{ value };                               \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_##suffix(long double value)                         \
    {                                                                                           \
        if (                                                                                    \
            value > std::numeric_limits<double>::max() ||                                       \
            value < std::numeric_limits<double>::min()                                          \
        )                                                                                       \
            throw "literal value out of range";                                                 \
                                                                                                \
        return scalar<constant, double>{ static_cast<double>(value) };                          \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_f_##suffix(long double value)                       \
    {                                                                                           \
        if (                                                                                    \
            value > std::numeric_limits<float>::max() ||                                        \
            value < std::numeric_limits<float>::min()                                           \
        )                                                                                       \
            throw "literal value out of range";                                                 \
                                                                                                \
        return scalar<constant, float>{ static_cast<float>(value) };                                 \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_l_##suffix(long double value) noexcept              \
    {                                                                                           \
        return scalar<constant, long double>{ value };                                          \
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

#define ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimension, symbol, factor) \
    inline constexpr unit<dimension, #symbol, factor> symbol{};        \

#define ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, prefix) \
    inline constexpr auto& prefix##base_symbol = prefixed_unit_v<              \
        dimension,                                                             \
        #base_symbol,                                                          \
        si_prefixes::prefix                                                    \
    >;                                                                         \

#define ZOLLSTOCK_DEFINE_PREFIXED_BASE_SI_UNIT_CONSTANTS(dimension, base_symbol) \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, q  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, r  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, y  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, z  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, a  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, f  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, p  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, n  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, mic)          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, m  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, c  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, d  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, da )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, h  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, k  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, M  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, G  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, T  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, P  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, E  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, Z  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, Y  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, R  )          \
    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANT(dimension, base_symbol, Q  )          \

#define ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(dimension, base_symbol)      \
    ZOLLSTOCK_DEFINE_PREFIXED_BASE_SI_UNIT_CONSTANTS(dimension, base_symbol) \
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimension, base_symbol, 1.0L)        \

#define ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(base_symbol, exponent)                       \
    inline constexpr auto base_symbol##exponent = zollstock::pow_v<base_symbol, exponent>; \

#define ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, prefix) \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(prefix##base_symbol, exponent)        \

#define ZOLLSTOCK_DEFINE_PREFIXED_RAISED_SI_UNIT_CONSTANTS(base_symbol, exponent) \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, q  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, r  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, y  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, z  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, a  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, f  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, p  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, n  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, mic)          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, m  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, c  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, d  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, da )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, h  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, k  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, M  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, G  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, T  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, P  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, E  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, Z  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, Y  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, R  )          \
    ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANT(base_symbol, exponent, Q  )          \

#define ZOLLSTOCK_DEFINE_RAISED_SI_UNIT_CONSTANTS(base_symbol, exponent)          \
    ZOLLSTOCK_DEFINE_PREFIXED_RAISED_SI_UNIT_CONSTANTS(base_symbol, exponent)     \
    ZOLLSTOCK_DEFINE_RAISED_UNIT_CONSTANT(base_symbol, exponent)                  \


#endif //__ZOLLSTOCK_DEFINITION_HELPERS_HPP__
