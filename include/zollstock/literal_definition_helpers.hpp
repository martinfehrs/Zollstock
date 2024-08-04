#ifndef __ZOLLSTOCK_LITERAL_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_LITERAL_DEFINITION_HELPERS_HPP__


#define ZOLLSTOCK_DEFINE_LITERAL(suffix, constant)                                              \
    [[nodiscard]] consteval auto operator""_##suffix(unsigned long long int value) noexcept     \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return scalar<constant, int>{ narrow<int>(value) };                                     \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_l_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return scalar<constant, long int>{ narrow<long int>(value) };                           \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ll_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return scalar<constant, long long int>{ narrow<long long int>(value) };                 \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_u_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return scalar<constant, unsigned int>{ narrow<unsigned int>(value) };                   \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ul_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return scalar<constant, unsigned long int>{ narrow<unsigned long int>(value) };         \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_ull_##suffix(unsigned long long int value) noexcept \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return scalar<constant, unsigned long long int>{ value };                               \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_##suffix(long double value)                         \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
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
        using namespace ::zollstock;                                                            \
                                                                                                \
        if (                                                                                    \
            value > std::numeric_limits<float>::max() ||                                        \
            value < std::numeric_limits<float>::min()                                           \
        )                                                                                       \
            throw "literal value out of range";                                                 \
                                                                                                \
        return scalar<constant, float>{ static_cast<float>(value) };                            \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator""_l_##suffix(long double value) noexcept              \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
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


#endif //__ZOLLSTOCK_LITERAL_DEFINITION_HELPERS_HPP__
