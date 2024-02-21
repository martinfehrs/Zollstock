#ifndef __ZOLLSTOCK_UNIT_CONCEPT_HPP__
#define __ZOLLSTOCK_UNIT_CONCEPT_HPP__


#include <zollstock/quantity_data.hpp>

#include <type_traits>
#include <concepts>
#include <string>
#include <string_view>
#include <iostream>
#include <sstream>


namespace zollstock
{

    enum class unit_type
    {
        basic,
        exponentiation,
        product
    };



    template <typename Candidate>
    concept unit_c = std::is_trivial_v<Candidate> && std::is_empty_v<Candidate>;

    template <typename Candidate>
    concept typed_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::type } -> std::same_as<const unit_type&>;
    };

    template <typename Candidate>
    concept length_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::length() } -> std::convertible_to<quantity_data>;
    };

    template <typename Candidate>
    concept time_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::time() } -> std::convertible_to<quantity_data>;
    };

    template <typename Candidate>
    concept mass_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::mass() } -> std::convertible_to<quantity_data>;
    };

    template <typename Candidate>
    concept angle_based_unit_c = requires()
    {
        requires unit_c<Candidate>;
        { Candidate::angle() } -> std::convertible_to<quantity_data>;
    };

    template <typename Candidate>
    concept base_unit_c = unit_c<Candidate> && type_of(Candidate{}) == unit_type::basic;

    template <typename Candidate>
    concept raised_unit_c = unit_c<Candidate> && type_of(Candidate{}) == unit_type::exponentiation;

    template <typename Candidate>
    concept multiplied_unit_c = unit_c<Candidate> && type_of(Candidate{}) == unit_type::product;

    template <typename Candidate>
    concept homogeneous_unit_c = unit_c<Candidate> && type_of(Candidate{}) != unit_type::product;



    template <unit_c Unit>
    [[nodiscard]] consteval unit_type type_of(Unit unit) noexcept
    {
        if constexpr(typed_unit_c<Unit>)
        {
            return unit.type;
        }
        else
        {
            return unit_type::basic;
        }
    }



    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data length_of(Unit unit) noexcept
    {
        if constexpr(length_based_unit_c<Unit>)
        {
            return unit.length();
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data time_of(Unit unit) noexcept
    {
        if constexpr(time_based_unit_c<Unit>)
        {
            return unit.time();
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data mass_of(Unit unit) noexcept
    {
        if constexpr(mass_based_unit_c<Unit>)
        {
            return unit.mass();
        }
        else
        {
            return {};
        }
    }

    template <unit_c Unit>
    [[nodiscard]] consteval quantity_data angle_of(Unit unit) noexcept
    {
        if constexpr(angle_based_unit_c<Unit>)
        {
            return unit.angle();
        }
        else
        {
            return {};
        }
    }



    template <quantity quantity_>
    [[nodiscard]] consteval quantity_data data_of(unit_c auto unit) noexcept
    {
        if constexpr(quantity_ == quantity::length)
        {
            return length_of(unit);
        }
        else if constexpr(quantity_ == quantity::time)
        {
            return time_of(unit);
        }
        else if constexpr(quantity_ == quantity::mass)
        {
            return mass_of(unit);
        }
        else if constexpr(quantity_ == quantity::angle)
        {
            return angle_of(unit);
        }
    }



    namespace detail
    {

        template <quantity... quantities>
        [[nodiscard]] consteval bool convertible_units_impl(
            unit_c auto unit_1, unit_c auto unit_2, quantity_sequence<quantities...>
        ) noexcept
        {
            return (
                ... &&
                (data_of<quantities>(unit_1).exponent ==
                 data_of<quantities>(unit_2).exponent)
            );
        }

    }

    [[nodiscard]] consteval bool convertible_units(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return detail::convertible_units_impl(unit_1, unit_2, make_quantity_sequence());
    }



    template <base_unit_c auto base_unit_, int exponent_>
    struct unit_exponentiation
    {
        static constexpr auto type = unit_type::exponentiation;
        static constexpr auto base_unit = base_unit_;
        static constexpr auto exponent = exponent_;

        static consteval auto length() noexcept
        {
            return pow(length_of(base_unit_), exponent_);
        }

        static consteval auto time() noexcept
        {
            return pow(time_of(base_unit_), exponent_);
        }

        static consteval auto mass() noexcept
        {
            return pow(mass_of(base_unit_), exponent_);
        }

        static consteval auto angle() noexcept
        {
            return pow(angle_of(base_unit_), exponent_);
        }

    };


    template<homogeneous_unit_c auto... base_units>
    struct unit_product
    {
        static constexpr auto type = unit_type::product;
        static constexpr auto size = sizeof...(base_units);

        static consteval auto length() noexcept
        {
            return (quantity_data{} * ... * length_of(base_units));
        }

        static consteval auto time() noexcept
        {
            return (quantity_data{} * ... * time_of(base_units));
        }

        static consteval auto mass() noexcept
        {
            return (quantity_data{} * ... * mass_of(base_units));
        }

        static consteval auto angle() noexcept
        {
            return (quantity_data{} * ... *  angle_of(base_units));
        }
    };



    template <base_unit_c auto unit, int exponent_>
    inline constexpr auto unit_exponentiation_v = unit_exponentiation<unit, exponent_>{};

    template <homogeneous_unit_c auto... units>
    inline constexpr auto unit_product_v = unit_product<units...>{};


    inline namespace units
    {

        inline namespace types
        {

            using one = unit_product<>;

        }

        inline namespace constants
        {

            inline constexpr one _1{};

        }

    }


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

        template <quantity quantity_, typename Char>
        [[nodiscard]] std::basic_string<Char> quantity_entry_to_string(unit_c auto unit)
        {
            std::basic_string<Char> unit_representation;

            constexpr quantity_data data = data_of<quantity_>(unit);

            if(data.exponent != 0)
            {
                std::string_view symbol_string{ data.symbol.c_str() };

                unit_representation.append(symbol_string.begin(), symbol_string.end());

                if(data.exponent != 1)
                    unit_representation += exponent_to_string<Char>(data.exponent);
            }

            return unit_representation;
        }

        template <typename Char>
        class basic_concatenator
        {

        public:

            template <typename Separator>
            explicit basic_concatenator(const Separator& separator)
                : separator{ stringify(separator) }
            {
            }

            template <typename FirstToken, typename... RemainingTokens>
            [[nodiscard]] std::basic_string<Char> operator()(
                const FirstToken& first_token,
                const RemainingTokens&... remaining_tokens
            )
            {
                if constexpr (sizeof...(RemainingTokens) == 0)
                {
                    return stringify(first_token);
                }
                else
                {
                    std::basic_string result = stringify(first_token);

                    const std::basic_string tail = (*this)(remaining_tokens...);

                    if(result.size() > 0 && tail.size() > 0)
                        result += this->separator;

                    result += tail;

                    return result;
                }
            }

        private:

            template <typename Token>
            static std::basic_string<Char> stringify(const Token& token)
            {
                if constexpr(std::is_same_v<Token, std::basic_string<Char>>)
                {
                    return token;
                }
                else
                {
                    std::basic_stringstream<Char> sstream;

                    sstream << token;

                    return sstream.str();
                }
            }

            std::basic_string<Char> separator;

        };

        template <typename Char, quantity... quantities>
        [[nodiscard]] std::basic_string<Char> to_basic_string_impl(
            unit_c auto unit, quantity_sequence<quantities...>
        )
        {
            return detail::basic_concatenator<Char>{ '*' }(
                detail::quantity_entry_to_string<quantities, Char>(unit)...
            );
        }

    }

    template <typename Char>
    [[nodiscard]] std::basic_string<Char> to_basic_string(unit_c auto unit)
    {
        return detail::basic_concatenator<Char>{ "*" }(
            detail::to_basic_string_impl<Char>(unit, make_derived_quantity_sequence()),
            detail::to_basic_string_impl<Char>(unit, make_base_quantity_sequence())
        );
    }

    [[nodiscard]] std::string to_string(unit_c auto unit)
    {
        return to_basic_string<char>(unit);
    }

    [[nodiscard]] std::wstring to_wstring(unit_c auto unit)
    {
        return to_basic_string<wchar_t>(unit);
    }

    template <typename Char>
    std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, unit_c auto unit)
    {
        return os << to_basic_string<Char>(unit);
    }



    template <
        homogeneous_unit_c auto first_base_unit,
        homogeneous_unit_c auto... remaining_base_units
    >
    [[nodiscard]] consteval auto first_base_of(
        unit_product<first_base_unit, remaining_base_units...>
    ) noexcept
    {
        return first_base_unit;
    }

    template <
        homogeneous_unit_c auto first_base_unit,
        homogeneous_unit_c auto second_base_unit,
        homogeneous_unit_c auto... remaining_base_units
    >
    [[nodiscard]] consteval auto second_base_of(
        unit_product<first_base_unit, second_base_unit, remaining_base_units...>
    ) noexcept
    {
        return second_base_unit;
    }



    namespace detail
    {

        template <homogeneous_unit_c auto... base_units>
        [[nodiscard]] consteval auto append_to_product_raw(
            homogeneous_unit_c auto base_unit, unit_product<base_units...>
        ) noexcept
        {
            return unit_product_v<base_units..., base_unit>;
        }

        template <homogeneous_unit_c auto... base_units>
        [[nodiscard]] consteval auto prepend_to_product_raw(
            homogeneous_unit_c auto base_unit, unit_product<base_units...>
        ) noexcept
        {
            return unit_product_v<base_unit, base_units...>;
        }

        template <homogeneous_unit_c auto... base_units_1, homogeneous_unit_c auto... base_units_2>
        [[nodiscard]] consteval auto concat_products_raw(
            unit_product<base_units_1...>,
            unit_product<base_units_2...>
        ) noexcept
        {
            return unit_product_v<base_units_1..., base_units_2...>;
        }



        template <unit_c Unit>
        struct erasure_result
        {
            Unit unit;
            int exponent;
        };

        template <unit_c Unit>
        erasure_result(Unit, int) -> erasure_result<Unit>;


        [[nodiscard]] consteval auto erase_product_base(
            base_unit_c auto base_unit, unit_product<> unit
        ) noexcept
        {
            return erasure_result{ unit, 0 };
        }

        template <
            homogeneous_unit_c auto first_base_unit,
            homogeneous_unit_c auto... remaining_base_units
        >
        [[nodiscard]] consteval auto erase_product_base(
            base_unit_c auto base_unit, unit_product<first_base_unit, remaining_base_units...> unit
        ) noexcept
        {
            auto[cleared_tail, exponent] = erase_product_base(
                base_unit, unit_product_v<remaining_base_units...>
            );

            if constexpr (type_of(first_base_unit) == unit_type::basic)
            {
                if constexpr(first_base_unit == base_unit)
                {
                    return erasure_result{ cleared_tail, exponent + 1 };
                }
                else
                {
                    return erasure_result{ unit, exponent };
                }
            }
            else if constexpr(type_of(first_base_unit) == unit_type::exponentiation)
            {
                if constexpr(first_base_unit.base_unit == base_unit)
                {
                    return erasure_result{
                        cleared_tail,
                        exponent + first_base_unit.exponent
                    };
                }
                else
                {
                    return erasure_result{ unit, exponent };
                }
            }
        }

        [[nodiscard]] consteval auto combine_redundant_product_bases(unit_product<> unit) noexcept
        {
            return unit;
        }

        template <
            homogeneous_unit_c auto first_base_unit,
            homogeneous_unit_c auto... remaining_base_units
        >
        [[nodiscard]] consteval auto combine_redundant_product_bases(
            unit_product<first_base_unit, remaining_base_units...> unit
        ) noexcept
        {
            if constexpr(unit.size == 1)
            {
                return unit;
            }
            if constexpr (type_of(first_base_unit) == unit_type::basic)
            {
                constexpr auto erasure_result = erase_product_base(
                    first_base_unit,
                    combine_redundant_product_bases(unit_product_v<remaining_base_units...>)
                );

                if constexpr(erasure_result.exponent != 0)
                {
                    return prepend_to_product_raw(
                        unit_exponentiation_v<first_base_unit, erasure_result.exponent + 1>,
                        erasure_result.unit
                    );
                }
                else
                {
                    return prepend_to_product_raw(first_base_unit, erasure_result.unit);
                }
            }
            else if constexpr(type_of(first_base_unit) == unit_type::exponentiation)
            {
                constexpr auto erasure_result = erase_product_base(
                    first_base_unit.base_unit,
                    combine_redundant_product_bases(unit_product_v<remaining_base_units...>)
                );

                if constexpr(erasure_result.exponent != 0)
                {
                    return prepend_to_product_raw(
                        unit_exponentiation_v<
                            first_base_unit.base_unit,
                            first_base_unit.exponent + erasure_result.exponent
                        >,
                        erasure_result.unit
                    );
                }
                else
                {
                    return prepend_to_product_raw(first_base_unit, erasure_result.unit);
                }
            }
        }

        template <base_unit_c Unit>
        [[nodiscard]] consteval auto simplify_combined_unit(Unit unit) noexcept
        {
            return unit;
        }

        template <raised_unit_c Unit> requires(Unit::exponent == 0)
        [[nodiscard]] consteval auto simplify_combined_unit(Unit) noexcept
        {
            return _1;
        }

        template <raised_unit_c Unit> requires(Unit::exponent == 1)
        [[nodiscard]] consteval auto simplify_combined_unit(Unit) noexcept
        {
            return Unit::base_unit;
        }

        template <raised_unit_c Unit>
        [[nodiscard]] consteval auto simplify_combined_unit(Unit unit) noexcept
        {
            return unit;
        }

        template <multiplied_unit_c Unit> requires(Unit::size == 0)
        [[nodiscard]] consteval auto simplify_combined_unit(Unit unit) noexcept
        {
            return _1;
        }

        template <multiplied_unit_c Unit> requires(Unit::size == 1)
        [[nodiscard]] consteval auto simplify_combined_unit(Unit unit) noexcept
        {
            return simplify_combined_unit(first_base_of(unit));
        }

        template <multiplied_unit_c Unit>
        [[nodiscard]] consteval auto simplify_combined_unit(Unit unit) noexcept
        {
            constexpr auto reduced_unit = combine_redundant_product_bases(unit);

            if constexpr(reduced_unit.size <= 1)
            {
                return simplify_combined_unit(reduced_unit);
            }
            else
            {
                return reduced_unit;
            }
        }



        [[nodiscard]] consteval auto append_to_product(
            homogeneous_unit_c auto base_unit, multiplied_unit_c auto unit
        ) noexcept
        {
            return simplify_combined_unit(append_to_product_raw(base_unit, unit));
        }

        [[nodiscard]] consteval auto prepend_to_product(
            homogeneous_unit_c auto base_unit, multiplied_unit_c auto unit
        ) noexcept
        {
            return simplify_combined_unit(prepend_to_product_raw(base_unit, unit));
        }

        [[nodiscard]] consteval auto concat_products(
            multiplied_unit_c auto unit_1, multiplied_unit_c auto unit_2
        ) noexcept
        {
            return simplify_combined_unit(concat_products_raw(unit_1, unit_2));
        }

    }

    [[nodiscard]] consteval auto operator*(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        if constexpr(
            type_of(unit_1) == unit_type::product &&
            type_of(unit_2) == unit_type::product
        )
        {
            return detail::concat_products(unit_1, unit_2);
        }
        else
        if constexpr(type_of(unit_1) == unit_type::product)
        {
            return detail::append_to_product(unit_2, unit_1);
        }
        else
        if constexpr(type_of(unit_2) == unit_type::product)
        {
            return detail::prepend_to_product(unit_1, unit_2);
        }
        else
        {
            return detail::simplify_combined_unit(unit_product_v<unit_1, unit_2>);
        }
    }

    namespace detail
    {

        template<int exponent>
        [[nodiscard]] consteval auto pow(unit_c auto unit) noexcept
        {
            if constexpr(exponent == 0 || unit == _1)
            {
                return _1;
            }
            else if constexpr(exponent == 1)
            {
                return unit;
            }
            else if constexpr(type_of(unit) == unit_type::exponentiation)
            {
                return unit_exponentiation_v<unit.base_unit, unit.exponent * exponent>;
            }
            else
            {
                return unit_exponentiation_v<unit, exponent>;
            }
        }

    }

    template<unit_c auto unit, int exponent>
    inline constexpr unit_c auto pow_v = detail::pow<exponent>(unit);



    [[nodiscard]] consteval auto operator/(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return unit_1 * pow_v<unit_2, -1>;
    }



    namespace detail
    {

        template <quantity... quantities>
        [[nodiscard]] consteval bool equal(
            unit_c auto unit_1, unit_c auto unit_2, quantity_sequence<quantities...>
        ) noexcept
        {
            return (
                ... &&
                (data_of<quantities>(unit_1) == data_of<quantities>(unit_2))
            );
        }

    }

    [[nodiscard]] consteval bool operator==(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return detail::equal(unit_1, unit_2, make_quantity_sequence());
    }

    [[nodiscard]] consteval bool operator!=(unit_c auto unit_1, unit_c auto unit_2) noexcept
    {
        return !detail::equal(unit_1, unit_2, make_quantity_sequence());
    }

}


#endif //__ZOLLSTOCK_UNIT_CONCEPT_HPP__
