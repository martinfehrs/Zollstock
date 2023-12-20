#ifndef __ZOLLSTOCK_ANGLE_UNITS_HPP__
#define __ZOLLSTOCK_ANGLE_UNITS_HPP__


#include "scalar.hpp"
#include "unit_prefix_concept.hpp"
#include "si_prefixes.hpp"


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            template <typename Prefix>
            struct basic_radian
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr unit_exponents exponents{ 0, 0, 1 };
                static constexpr unit_factors factors{ 0.0L, 0.0L, Prefix::factor };
                static constexpr unit_symbols symbols{ ""_us,  ""_us, Prefix::symbol + "rad"_us };
            };

            using picoradian  = basic_radian<pico      >;
            using nanoradian  = basic_radian<nano      >;
            using microradian = basic_radian<micro     >;
            using milliradian = basic_radian<milli     >;
            using centiradian = basic_radian<centi     >;
            using deciradian  = basic_radian<deci      >;
            using radian      = basic_radian<unprefixed>;

            struct degree
            {
                static constexpr unit_exponents exponents{ 0, 0, 1 };
                static constexpr unit_factors factors{ 0.0L, 0.0L, 3.1415926L/180.0L };
                static constexpr unit_symbols symbols{ ""_us, ""_us, "deg"_us };        
            };

        }

        inline namespace constants
        {

            inline constexpr picoradian  prad   {};
            inline constexpr nanoradian  nrad   {};
            inline constexpr microradian micrad {};
            inline constexpr milliradian mrad   {};
            inline constexpr centiradian crad   {};
            inline constexpr deciradian  drad   {};
            inline constexpr radian      rad    {};

            inline constexpr degree      deg    {};

        }

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_prad(long double val) noexcept
            {
                return scalar<picoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_prad(unsigned long long int val) noexcept
            {
                return scalar<picoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_nrad(long double val) noexcept
            {
                return scalar<nanoradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_nrad(unsigned long long int val) noexcept
            {
                return scalar<nanoradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_micrad(long double val) noexcept
            {
                return scalar<microradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_micrad(unsigned long long int val) noexcept
            {
                return scalar<microradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_mrad(long double val) noexcept
            {
                return scalar<milliradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_mrad(unsigned long long int val) noexcept
            {
                return scalar<milliradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_crad(long double val) noexcept
            {
                return scalar<centiradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_crad(unsigned long long int val) noexcept
            {
                return scalar<centiradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_drad(long double val) noexcept
            {
                return scalar<deciradian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_drad(unsigned long long int val) noexcept
            {
                return scalar<deciradian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_rad(long double val) noexcept
            {
                return scalar<radian>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_rad(unsigned long long int val) noexcept
            {
                return scalar<radian>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_deg(long double val) noexcept
            {
                return scalar<degree>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_deg(unsigned long long int val) noexcept
            {
                return scalar<degree>{ static_cast<double>(val) };
            }

        }

    }

    inline namespace math_constants
    {
    
        inline constexpr scalar<radian> pi{ 3.14159265358979323846264338327950288419716939937510L };

    }

}


#endif //__ZOLLSTOCK_ANGLE_UNITS_HPP__