#ifndef __ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__


#include <zollstock/unit_symbol.hpp>

#include <type_traits>


namespace zollstock
{

    template <typename Candidate, typename = void>
    constexpr bool has_factor_v = false;

    template <typename Candidate>
    constexpr bool has_factor_v<
        Candidate,
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::factor)>, long double>>
    > = true;

    template <typename Candidate, typename = void>
    inline constexpr bool has_symbol_v = false;

    template <typename Candidate>
    inline constexpr bool has_symbol_v<
        Candidate,
        std::enable_if_t<std::is_same_v<std::remove_cv_t<decltype(Candidate::symbol)>, unit_symbol>>
    > = true;

    template <typename Candidate>
    inline constexpr bool is_prefix_v = has_factor_v<Candidate>
                                     && has_symbol_v<Candidate>;

}


#endif //__ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__
