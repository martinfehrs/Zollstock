#ifndef __ZOLLSTOCK_UNITS_CONCEPTS_PREFIX_HPP__
#define __ZOLLSTOCK_UNITS_CONCEPTS_PREFIX_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>
#  include <zollstock/static_string.hpp>

#  include <concepts>
#  include <type_traits>
#endif

namespace zollstock
{

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept prefix_c = requires()
    {
        { Candidate::symbol } -> std::same_as<const static_string&>;
        { Candidate::factor } -> std::same_as<const long double&>;
    };



    ZOLLSTOCK_MODULE_EXPORT template <static_string symbol_, long double factor_>
    struct prefix
    {
        static constexpr static_string symbol = symbol_;
        static constexpr long double factor = factor_;
    };

}


#endif //__ZOLLSTOCK_UNITS_CONCEPTS_PREFIX_HPP__
