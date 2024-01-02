#ifndef __ZOLLSTOCK_TIME_UNITS_HPP__
#define __ZOLLSTOCK_TIME_UNITS_HPP__


#include <zollstock/scalar.hpp>
#include <zollstock/unit_prefix_concept.hpp>
#include <zollstock/si_prefixes.hpp>


namespace zollstock
{

    inline namespace unit
    {

        inline namespace types
        {

            template <typename Prefix>
            struct basic_second
            {
                static_assert(is_prefix_v<Prefix>);

                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, Prefix::factor, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, Prefix::symbol + "s"_us, ""_us };
            };

            using quektosecond = basic_second<quekto    >;
            using rontosecond  = basic_second<ronto     >;
            using yoktosecond  = basic_second<yokto     >;
            using zeptosecond  = basic_second<zepto     >;
            using attosecond   = basic_second<atto      >;
            using femtosecond  = basic_second<femto     >;
            using picosecond   = basic_second<pico      >;
            using nanosecond   = basic_second<nano      >;
            using microsecond  = basic_second<micro     >;
            using millisecond  = basic_second<milli     >;
            using centisecond  = basic_second<centi     >;
            using decisecond   = basic_second<deci      >;
            using second       = basic_second<unprefixed>;
            using decasecond   = basic_second<deca      >;
            using hectosecond  = basic_second<hecto     >;
            using kilosecond   = basic_second<kilo      >;
            using megasecond   = basic_second<mega      >;
            using gigasecond   = basic_second<giga      >;
            using terasecond   = basic_second<tera      >;
            using petasecond   = basic_second<peta      >;
            using exasecond    = basic_second<exa       >;
            using zettasecond  = basic_second<zetta     >;
            using yottasecond  = basic_second<yotta     >;
            using ronnasecond  = basic_second<ronna     >;
            using quettasecond = basic_second<quetta    >;

            struct minute
            {
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 60.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "min"_us, ""_us };
            };

            struct hour
            {
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 3600.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "h"_us, ""_us };
            };

            struct day
            {
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 86'400.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "d"_us, ""_us };
            };

            struct year
            {
                static constexpr quantity_exponents exponents{ 0, 1, 0 };
                static constexpr quantity_factors factors{ 0.0L, 31'536'000.0L, 0.0L };
                static constexpr quantity_symbols symbols{ ""_us, "d"_us, ""_us };
            };

        }

        inline namespace constants
        {

            inline constexpr quektosecond qs  {};
            inline constexpr rontosecond  rs  {};
            inline constexpr yoktosecond  ys  {};
            inline constexpr zeptosecond  zs  {};
            inline constexpr attosecond   as  {};
            inline constexpr femtosecond  fs  {};
            inline constexpr picosecond   ps  {};
            inline constexpr nanosecond   ns  {};
            inline constexpr microsecond  mics{};
            inline constexpr millisecond  ms  {};
            inline constexpr centisecond  cs  {};
            inline constexpr decisecond   ds  {};
            inline constexpr second       s   {};
            inline constexpr decasecond   das {};
            inline constexpr hectosecond  hs  {};
            inline constexpr kilosecond   ks  {};
            inline constexpr megasecond   Ms  {};
            inline constexpr gigasecond   Gs  {};
            inline constexpr terasecond   Ts  {};
            inline constexpr petasecond   Ps  {};
            inline constexpr exasecond    Es  {};
            inline constexpr zettasecond  Zs  {};
            inline constexpr yottasecond  Ys  {};
            inline constexpr ronnasecond  Rs  {};
            inline constexpr quettasecond Qs  {};

            inline constexpr minute      min  {};
            inline constexpr hour        h    {};
            inline constexpr day         d    {};
            inline constexpr year        a    {};

        }

        inline namespace literals
        {

            [[nodiscard]] constexpr auto operator""_qs(long double val) noexcept
            {
                return scalar<quektosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_qs(unsigned long long int val) noexcept
            {
                return scalar<quektosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_rs(long double val) noexcept
            {
                return scalar<rontosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_rs(unsigned long long int val) noexcept
            {
                return scalar<rontosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ys(long double val) noexcept
            {
                return scalar<yoktosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ys(unsigned long long int val) noexcept
            {
                return scalar<yoktosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_zs(long double val) noexcept
            {
                return scalar<zeptosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_zs(unsigned long long int val) noexcept
            {
                return scalar<zeptosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_as(long double val) noexcept
            {
                return scalar<attosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_as(unsigned long long int val) noexcept
            {
                return scalar<attosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_fs(long double val) noexcept
            {
                return scalar<femtosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_fs(unsigned long long int val) noexcept
            {
                return scalar<femtosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ps(long double val) noexcept
            {
                return scalar<picosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ps(unsigned long long int val) noexcept
            {
                return scalar<picosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ns(long double val) noexcept
            {
                return scalar<nanosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ns(unsigned long long int val) noexcept
            {
                return scalar<nanosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_mics(long double val) noexcept
            {
                return scalar<microsecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_mics(unsigned long long int val) noexcept
            {
                return scalar<microsecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ms(long double val) noexcept
            {
                return scalar<millisecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ms(unsigned long long int val) noexcept
            {
                return scalar<millisecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_cs(long double val) noexcept
            {
                return scalar<centisecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_cs(unsigned long long int val) noexcept
            {
                return scalar<centisecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ds(long double val) noexcept
            {
                return scalar<decisecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ds(unsigned long long int val) noexcept
            {
                return scalar<decisecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_s(long double val) noexcept
            {
                return scalar<second>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_s(unsigned long long int val) noexcept
            {
                return scalar<second>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_das(long double val) noexcept
            {
                return scalar<decasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_das(unsigned long long int val) noexcept
            {
                return scalar<decasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_hs(long double val) noexcept
            {
                return scalar<hectosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_hs(unsigned long long int val) noexcept
            {
                return scalar<hectosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_ks(long double val) noexcept
            {
                return scalar<kilosecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_ks(unsigned long long int val) noexcept
            {
                return scalar<kilosecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Ms(long double val) noexcept
            {
                return scalar<megasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Ms(unsigned long long int val) noexcept
            {
                return scalar<megasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Gs(long double val) noexcept
            {
                return scalar<gigasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Gs(unsigned long long int val) noexcept
            {
                return scalar<gigasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Ts(long double val) noexcept
            {
                return scalar<terasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Ts(unsigned long long int val) noexcept
            {
                return scalar<terasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Ps(long double val) noexcept
            {
                return scalar<petasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Ps(unsigned long long int val) noexcept
            {
                return scalar<petasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Es(long double val) noexcept
            {
                return scalar<exasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Es(unsigned long long int val) noexcept
            {
                return scalar<exasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Zs(long double val) noexcept
            {
                return scalar<zettasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Zs(unsigned long long int val) noexcept
            {
                return scalar<zettasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Ys(long double val) noexcept
            {
                return scalar<yottasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Ys(unsigned long long int val) noexcept
            {
                return scalar<yottasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Rs(long double val) noexcept
            {
                return scalar<ronnasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Rs(unsigned long long int val) noexcept
            {
                return scalar<ronnasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_Qs(long double val) noexcept
            {
                return scalar<quettasecond>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_Qs(unsigned long long int val) noexcept
            {
                return scalar<quettasecond>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_min(long double val) noexcept
            {
                return scalar<minute>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_min(unsigned long long int val) noexcept
            {
                return scalar<minute>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_h(long double val) noexcept
            {
                return scalar<hour>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_h(unsigned long long int val) noexcept
            {
                return scalar<hour>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_d(long double val) noexcept
            {
                return scalar<day>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_d(unsigned long long int val) noexcept
            {
                return scalar<day>{ static_cast<double>(val) };
            }


            [[nodiscard]] constexpr auto operator""_a(long double val) noexcept
            {
                return scalar<year>{ static_cast<double>(val) };
            }

            [[nodiscard]] constexpr auto operator""_a(unsigned long long int val) noexcept
            {
                return scalar<year>{ static_cast<double>(val) };
            }

        }

    }

}


#endif //__ZOLLSTOCK_TIME_UNITS_HPP__
