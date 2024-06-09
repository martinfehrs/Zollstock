#ifndef __ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__


#include <zollstock/static_string.hpp>

#include <type_traits>


namespace zollstock
{

    template <typename Candidate>
    concept prefix_c = requires()
    {
        { Candidate::symbol } -> std::same_as<const static_string&>;
        { Candidate::factor } -> std::same_as<const long double&>;
    };



    template <static_string symbol_, long double factor_>
    struct prefix
    {
        static constexpr static_string symbol = symbol_;
        static constexpr long double factor = factor_;
    };

}


#endif //__ZOLLSTOCK_UNIT_PREFIX_CONCEPT_HPP__
