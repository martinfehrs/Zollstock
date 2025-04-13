#ifndef __ZOLLSTOCK_UNITS_LITERALS_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_UNITS_LITERALS_DEFINITION_HELPERS_HPP__


#include <zollstock/quantities/template.hpp>

#include <limits>


#define ZOLLSTOCK_DEFINE_LITERALS(suffix, constant)                                             \
    [[nodiscard]] consteval auto operator"" _##suffix(unsigned long long int value) noexcept     \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return quantity<constant, int>{ narrow<int>(value) };                                   \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _l_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return quantity<constant, long int>{ narrow<long int>(value) };                         \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _ll_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return quantity<constant, long long int>{ narrow<long long int>(value) };               \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _u_##suffix(unsigned long long int value) noexcept   \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return quantity<constant, unsigned int>{ narrow<unsigned int>(value) };                 \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _ul_##suffix(unsigned long long int value) noexcept  \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return quantity<constant, unsigned long int>{ narrow<unsigned long int>(value) };       \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _ull_##suffix(unsigned long long int value) noexcept \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return quantity<constant, unsigned long long int>{ value };                             \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _##suffix(long double value)                         \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        if (                                                                                    \
            value > std::numeric_limits<double>::max() ||                                       \
            value < std::numeric_limits<double>::lowest()                                       \
        )                                                                                       \
            throw "literal value out of range";                                                 \
                                                                                                \
        return quantity<constant, double>{ static_cast<double>(value) };                        \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _f_##suffix(long double value)                       \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        if (                                                                                    \
            value > std::numeric_limits<float>::max() ||                                        \
            value < std::numeric_limits<float>::lowest()                                        \
        )                                                                                       \
            throw "literal value out of range";                                                 \
                                                                                                \
        return quantity<constant, float>{ static_cast<float>(value) };                          \
    }                                                                                           \
                                                                                                \
    [[nodiscard]] consteval auto operator"" _l_##suffix(long double value) noexcept              \
    {                                                                                           \
        using namespace ::zollstock;                                                            \
                                                                                                \
        return quantity<constant, long double>{ value };                                        \
    }                                                                                           \

#define ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(base_symbol)        \
    ZOLLSTOCK_DEFINE_LITERALS(q##base_symbol  , q##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(r##base_symbol  , r##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(y##base_symbol  , y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(z##base_symbol  , z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(a##base_symbol  , a##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(f##base_symbol  , f##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(p##base_symbol  , p##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(n##base_symbol  , n##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(mic##base_symbol, mic##base_symbol) \
    ZOLLSTOCK_DEFINE_LITERALS(m##base_symbol  , m##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(c##base_symbol  , c##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(d##base_symbol  , d##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(da##base_symbol , da##base_symbol ) \
    ZOLLSTOCK_DEFINE_LITERALS(h##base_symbol  , h##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(k##base_symbol  , k##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(M##base_symbol  , M##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(G##base_symbol  , G##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(T##base_symbol  , T##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(P##base_symbol  , P##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(E##base_symbol  , E##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(Z##base_symbol  , Z##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(Y##base_symbol  , Y##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(R##base_symbol  , R##base_symbol  ) \
    ZOLLSTOCK_DEFINE_LITERALS(Q##base_symbol  , Q##base_symbol  ) \

#define ZOLLSTOCK_DEFINE_SI_LITERALS(base_symbol)       \
    ZOLLSTOCK_DEFINE_LITERALS(base_symbol, base_symbol) \
    ZOLLSTOCK_DEFINE_SI_PREFIXED_LITERALS(base_symbol)  \


#endif //__ZOLLSTOCK_UNITS_LITERALS_DEFINITION_HELPERS_HPP__
