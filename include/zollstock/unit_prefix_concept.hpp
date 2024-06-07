#ifndef __ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__


#include <zollstock/unit_symbol.hpp>

#include <type_traits>


namespace zollstock
{

    template <typename Candidate>
    concept prefix_c = requires()
    {
        { Candidate::symbol } -> std::same_as<const unit_symbol&>;
        { Candidate::factor } -> std::same_as<const long double&>;
    };



    template <unit_symbol symbol_, long double factor_>
    struct prefix
    {
        static constexpr unit_symbol symbol = symbol_;
        static constexpr long double factor = factor_;
    };

}


#endif //__ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__
