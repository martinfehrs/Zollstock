#ifndef __ZOLLSTOCK_UNITS_CONCEPTS_UNIT_HPP__
#define __ZOLLSTOCK_UNITS_CONCEPTS_UNIT_HPP__


#ifndef ZOLLSTOCK_USE_MODULES
#  include <zollstock/config.hpp>
#  include <zollstock/dimensions.hpp>
#  include <zollstock/static_string.hpp>
#  include <zollstock/tuple_utils.hpp>
#  include <zollstock/units/concepts/prefix.hpp>

#  include <format>
#  include <sstream>
#  include <tuple>
#  include <type_traits>
#  include <concepts>
#  include <string>
#  include <iostream>
#  include <utility>
#endif


namespace zollstock
{

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept unit_factor_c = requires
    {
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        requires std::same_as<
            std::remove_cvref_t<decltype(Candidate::dimensions)>,
            dimensions::dimensions_t
        >;
        { Candidate::symbol         } -> std::same_as<const static_string&>;
        { Candidate::scaling_factor } -> std::same_as<const long double&>;
        { Candidate::prefix         } -> std::same_as<const static_string&>;
        { Candidate::exponent       } -> std::same_as<const int&>;
    };

    ZOLLSTOCK_MODULE_EXPORT template<class Candidate, std::size_t index>
    concept has_unit_factor_tuple_element_c = requires (Candidate candidate)
    {
        requires unit_factor_c<typename std::tuple_element<index, Candidate>::type>;
        { get<index>(candidate) } -> std::convertible_to<std::tuple_element_t<index, Candidate>&>;
    };

    ZOLLSTOCK_MODULE_EXPORT template<class Candidate>
    concept is_unit_factor_tuple_like_c = requires
    {
        requires []<std::size_t... indices>(std::index_sequence<indices...>)
        {
            return (has_unit_factor_tuple_element_c<Candidate, indices> && ...);
        }
        (std::make_index_sequence<std::tuple_size_v<Candidate>>{});

    };

    ZOLLSTOCK_MODULE_EXPORT struct unit_tag;

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept unit_c = requires
    {
        requires std::same_as<typename Candidate::type, unit_tag>;
        requires std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;
        requires is_unit_factor_tuple_like_c<std::remove_cvref_t<decltype(Candidate::factors)>>;
    };

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept homogeneous_unit_c = unit_c<Candidate> && Candidate::size == 1;

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept heterogeneous_unit_c = unit_c<Candidate> && Candidate::size != 1;

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto multiply_dimensions(
        const dimensions::dimensions_t& dimensions_1,
        const dimensions::dimensions_t& dimensions_2
    ) noexcept
    {
        return dimensions_1 * dimensions_2;
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval dimensions::dimensions_t unit_dimensions(
        unit_c auto unit
    ) noexcept
    {
        return tuple_transform_reduce(
            unit.factors,
            dimensions::_1,
            multiply_dimensions,
            [](unit_factor_c auto factor)
            {
                return dimensions::pow_v<factor.dimensions, factor.exponent>;
            }
        );
    }

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept base_unit_c = requires
    {
        requires unit_c<Candidate>;
        requires unit_dimensions(Candidate{}).base();
    };

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept derived_unit_c = requires
    {
        requires unit_c<Candidate>;
        requires unit_dimensions(Candidate{}).derived();
    };

    ZOLLSTOCK_MODULE_EXPORT template <typename Candidate>
    concept dimensionless_unit_c = requires
    {
        requires unit_c<Candidate>;
        requires unit_dimensions(Candidate{}).dimensionless();
    };

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto unit_scaling_factor(
        unit_c auto unit
    ) noexcept
    {
        return tuple_transform_reduce(
            unit.factors,
            1.0L,
            [](long double scaling_factor_1, long double scaling_factor_2)
            {
                return scaling_factor_1 * scaling_factor_2;
            },
            [](unit_factor_c auto factor)
            {
                return factor.scaling_factor;
            }
        );
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval bool convertible_units(
        unit_c auto from, unit_c auto to
    ) noexcept
    {
        return unit_dimensions(from) == unit_dimensions(to);
    }


    ZOLLSTOCK_MODULE_EXPORT template<
        dimensions::dimensions_t dimensions_,
        static_string symbol_,
        long double scaling_factor_,
        static_string prefix_,
        int exponent_
    >
    struct unit_factor
    {
        static constexpr auto dimensions = dimensions_;
        static constexpr auto symbol = symbol_;
        static constexpr auto scaling_factor = scaling_factor_;
        static constexpr auto prefix = prefix_;
        static constexpr auto exponent = exponent_;
    };



    ZOLLSTOCK_MODULE_EXPORT template<unit_factor_c... Factors>
    struct unit_product
    {
        using type = unit_tag;
        static constexpr auto factors = std::tuple{ Factors{}... };
        static constexpr std::size_t size = sizeof...(Factors);
    };

    ZOLLSTOCK_MODULE_EXPORT template <unit_factor_c... Factors>
    inline constexpr auto unit_product_v = unit_product<Factors...>{};

    ZOLLSTOCK_MODULE_EXPORT template <unit_factor_c FirstFactor, unit_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto unit_product_head(
        unit_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return unit_product_v<FirstFactor>;
    }

    ZOLLSTOCK_MODULE_EXPORT template <unit_factor_c FirstFactor, unit_factor_c... RemainingFactors>
    [[nodiscard]] consteval auto unit_product_tail(
        unit_product<FirstFactor, RemainingFactors...>
    ) noexcept
    {
        return unit_product_v<RemainingFactors...>;
    }

    namespace detail
    {

        template <unit_factor_c ... Factors1, unit_factor_c... Factors2>
        [[nodiscard]] consteval auto unit_product_concat(
            unit_product<Factors1...>, unit_product<Factors2...>
        ) noexcept
        {
            return unit_product_v<Factors1..., Factors2...>;
        }

    }



    ZOLLSTOCK_MODULE_EXPORT template <
        dimensions::dimensions_t dimensions,
        static_string symbol,
        long double scaling_factor,
        static_string prefix = "",
        int exponent = 1
    >
    using unit = unit_product<unit_factor<dimensions, symbol, scaling_factor, prefix, exponent>>;

    ZOLLSTOCK_MODULE_EXPORT template <
        dimensions::dimensions_t dimensions,
        static_string symbol,
        long double scaling_factor,
        static_string prefix = "",
        int exponent = 1
    >
    inline constexpr auto unit_v = unit<dimensions, symbol, scaling_factor, prefix, exponent>{};



    ZOLLSTOCK_MODULE_EXPORT template <
        dimensions::dimensions_t dimensions,
        static_string symbol,
        prefix_c auto prefix,
        int exponent = 1
    >
    using prefixed_unit = unit<dimensions, symbol, prefix.factor, prefix.symbol, exponent>;

    ZOLLSTOCK_MODULE_EXPORT template <
        dimensions::dimensions_t dimensions,
        static_string symbol,
        prefix_c auto prefix,
        int exponent = 1
    >
    inline constexpr auto prefixed_unit_v = prefixed_unit<dimensions, symbol, prefix, exponent>{};



    namespace detail
    {

        template <typename Char>
        [[nodiscard]] std::basic_string<Char> exponent_to_string(int exponent)
        {
            std::basic_string<Char> string_representation;

            string_representation += '^';

            std::basic_stringstream<Char> ss;

            ss << exponent;

            string_representation += ss.str();

            return string_representation;
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template <typename Char>
    [[nodiscard]] std::basic_string<Char> to_basic_string(unit_c auto unit)
    {
        using namespace std::string_literals;

        return tuple_transform_reduce(
            unit.factors,
            ""s,
            [](std::string lhs, const std::string& rhs)
            {
                if (!lhs.empty() && lhs.back() != '*')
                    lhs += '*';

                return lhs += rhs;
            },
            [](const unit_factor_c auto& factor)
            {
                std::string symbol{ factor.prefix.c_str() };

                symbol += factor.symbol.c_str();

                if(factor.exponent != 1)
                    symbol += detail::exponent_to_string<Char>(factor.exponent);

                return symbol;
            }
        );
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] std::string to_string(unit_c auto unit)
    {
        return to_basic_string<char>(unit);
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] std::wstring to_wstring(unit_c auto unit)
    {
        return to_basic_string<wchar_t>(unit);
    }

    ZOLLSTOCK_MODULE_EXPORT template <typename Char>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, unit_c auto unit)
    {
        return os << to_basic_string<Char>(unit);
    }



    namespace detail
    {

        template<int exponent> requires(exponent == 0)
        [[nodiscard]] consteval auto pow(unit_c auto unit) noexcept
        {
            return unit_product_v<>;
        }

        template<int exponent> requires(exponent == 1)
        [[nodiscard]] consteval auto pow(unit_c auto unit) noexcept
        {
            return unit;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(homogeneous_unit_c auto unit) noexcept
        {
            const auto factor = std::get<0>(unit.factors);

            return unit_v<
                factor.dimensions,
                factor.symbol,
                factor.scaling_factor,
                factor.prefix,
                factor.exponent * exponent
            >;
        }

        template<int exponent> requires(exponent < 0 || exponent > 1)
        [[nodiscard]] consteval auto pow(heterogeneous_unit_c auto unit) noexcept
        {
            if constexpr (unit.size == 0)
            {
                return unit;
            }
            else
            {
                return pow<exponent>(unit_product_head(unit))
                     * pow<exponent>(unit_product_tail(unit));
            }
        }

    }

    ZOLLSTOCK_MODULE_EXPORT template<unit_c auto unit, int exponent>
    inline constexpr unit_c auto pow_v = detail::pow<exponent>(unit);



    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto operator*(
        homogeneous_unit_c auto unit_1, homogeneous_unit_c auto unit_2
    )
    {
        const unit_factor_c auto factor_1 = std::get<0>(unit_1.factors);
        const unit_factor_c auto factor_2 = std::get<0>(unit_2.factors);

        if constexpr(factor_1.dimensions < factor_2.dimensions)
        {
            return detail::unit_product_concat(unit_1, unit_2);
        }
        else
        if constexpr(factor_1.dimensions > factor_2.dimensions)
        {
            return detail::unit_product_concat(unit_2, unit_1);
        }
        else
        if constexpr(factor_1.symbol < factor_2.symbol)
        {
            return detail::unit_product_concat(unit_1, unit_2);
        }
        else
        if constexpr(factor_1.symbol > factor_2.symbol)
        {
            return detail::unit_product_concat(unit_2, unit_1);
        }
        else
        if constexpr(factor_1.scaling_factor < factor_2.scaling_factor)
        {
            return detail::unit_product_concat(unit_1, unit_2);
        }
        else
        if constexpr(factor_1.scaling_factor > factor_2.scaling_factor)
        {
            return detail::unit_product_concat(unit_2, unit_1);
        }
        else
        if constexpr((factor_1.prefix) < (factor_2.prefix))
        {
            return detail::unit_product_concat(unit_1, unit_2);
        }
        else
        if constexpr(factor_1.prefix > factor_2.prefix)
        {
            return detail::unit_product_concat(unit_2, unit_1);
        }
        else
        if constexpr(factor_1.exponent + factor_2.exponent == 0)
        {
            return unit_product_v<>;
        }
        else
        {
            return unit_v<
                factor_1.dimensions * factor_2.dimensions,
                factor_1.symbol,
                factor_1.scaling_factor,
                factor_1.prefix,
                factor_1.exponent + factor_2.exponent
            >;
        }
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto operator*(
        heterogeneous_unit_c auto unit_1, homogeneous_unit_c auto unit_2
    )
    {
        if constexpr(unit_1.size == 0)
        {
            return unit_2;
        }
        else
        {
            const auto factor_2 = std::get<0>(unit_2.factors);
            const auto head = unit_product_head(unit_1);
            const auto head_factor = std::get<0>(head.factors);

            if constexpr (factor_2.dimensions < head_factor.dimensions)
            {
                return detail::unit_product_concat(unit_2, unit_1);
            }
            else
            if constexpr (factor_2.dimensions > head_factor.dimensions)
            {
                return detail::unit_product_concat(head, unit_product_tail(unit_1) * unit_2);
            }
            else
            if constexpr (factor_2.symbol < head_factor.symbol)
            {
                return detail::unit_product_concat(unit_2, unit_1);
            }
            else
            if constexpr (factor_2.symbol > head_factor.symbol)
            {
                return detail::unit_product_concat(head, unit_product_tail(unit_1) * unit_2);
            }
            else
            if constexpr ((factor_2.prefix) < (head_factor.prefix))
            {
                return detail::unit_product_concat(unit_2, unit_1);
            }
            else
            if constexpr (factor_2.prefix > head_factor.prefix)
            {
                return detail::unit_product_concat(head, unit_product_tail(unit_1) * unit_2);
            }
            else
            {
                return detail::unit_product_concat(head * unit_2, unit_product_tail(unit_1));
            }
        }
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto operator*(
        homogeneous_unit_c auto unit_1, heterogeneous_unit_c auto unit_2
    )
    {
        return unit_2 * unit_1;
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto operator*(
        heterogeneous_unit_c auto unit_1, heterogeneous_unit_c auto unit_2
    )
    {
        if constexpr (unit_1.size == 0)
        {
            return unit_2;
        }
        else
        if constexpr (unit_2.size == 0)
        {
            return unit_1;
        }
        else
        {
            return unit_product_head(unit_1) * (unit_product_tail(unit_1) * unit_2);
        }
    }



    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval auto operator/(
        unit_c auto unit_1, unit_c auto unit_2
    )
    {
        return unit_1 * pow_v<unit_2, -1>;
    }



    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval bool operator==(
        unit_factor_c auto factor_1, unit_factor_c auto factor_2
    ) noexcept
    {
        return factor_1.dimensions     == factor_2.dimensions
            && factor_1.symbol         == factor_2.symbol
            && factor_1.scaling_factor == factor_2.scaling_factor
            && factor_1.prefix         == factor_2.prefix
            && factor_1.exponent       == factor_2.exponent;
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval bool operator!=(
        unit_factor_c auto factor_1, unit_factor_c auto factor_2
    ) noexcept
    {
        return !(factor_1 == factor_2);
    }



    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval bool operator==(
        unit_c auto unit_1, unit_c auto unit_2
    ) noexcept
    {
        return tuple_equal(unit_1.factors, unit_2.factors);
    }

    ZOLLSTOCK_MODULE_EXPORT [[nodiscard]] consteval bool operator!=(
        unit_c auto unit_1, unit_c auto unit_2
    ) noexcept
    {
        return !(unit_1 == unit_2);
    }

}


ZOLLSTOCK_MODULE_EXPORT template<zollstock::unit_c Unit>
struct std::formatter<Unit, char>
{

    template<typename ParseContext>
    constexpr ParseContext::iterator parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template<typename FmtContext>
    FmtContext::iterator format(Unit u, FmtContext& ctx) const
    {
        std::ostringstream out;

        out << u;

        return std::ranges::copy(std::move(out).str(), ctx.out()).out;
    }
};


#endif //__ZOLLSTOCK_UNITS_CONCEPTS_UNIT_HPP__
