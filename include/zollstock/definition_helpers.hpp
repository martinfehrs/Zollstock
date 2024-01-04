#ifndef __ZOLLSTOCK_DEFINITION_HELPERS_HPP__
#define __ZOLLSTOCK_DEFINITION_HELPERS_HPP__


#define ZOLLSTOCK_DEFINE_LITERAL(type, suffix) \
    [[nodiscard]] constexpr auto operator""_##suffix(unsigned long long int value) noexcept \
    { \
        return scalar<type>{ static_cast<double>(value) }; \
    } \
    \
    [[nodiscard]] constexpr auto operator""_##suffix(long double value) noexcept \
    { \
        return scalar<type>{ static_cast<double>(value) }; \
    } \


#endif //__ZOLLSTOCK_DEFINITION_HELPERS_HPP__
