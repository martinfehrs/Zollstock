#include <zollstock/quantity_limits.hpp>
#include <zollstock/all_units.hpp>

#include <catch2/catch_all.hpp>

#include <cmath>


namespace zs = zollstock;

using namespace zollstock::units;


TEMPLATE_TEST_CASE(
    "quantity-limits", "[quantity][limits]",
    double,
    const double,
    volatile double,
    const volatile double
)
{

    using quantity_limits = std::numeric_limits<zs::quantity<_1, double>>;
    using scalar_limits   = std::numeric_limits<double>;

    STATIC_REQUIRE(quantity_limits::is_specialized        == scalar_limits::is_specialized   );
    STATIC_REQUIRE(quantity_limits::is_signed             == scalar_limits::is_signed        );
    STATIC_REQUIRE(quantity_limits::is_integer            == scalar_limits::is_integer       );
    STATIC_REQUIRE(quantity_limits::is_exact              == scalar_limits::is_exact         );
    STATIC_REQUIRE(quantity_limits::has_infinity          == scalar_limits::has_infinity     );
    STATIC_REQUIRE(quantity_limits::has_quiet_NaN         == scalar_limits::has_quiet_NaN    );
    STATIC_REQUIRE(quantity_limits::has_signaling_NaN     == scalar_limits::has_signaling_NaN);
    STATIC_REQUIRE(quantity_limits::has_denorm            == scalar_limits::has_denorm       );
    STATIC_REQUIRE(quantity_limits::has_denorm_loss       == scalar_limits::has_denorm_loss  );
    STATIC_REQUIRE(quantity_limits::round_style           == scalar_limits::round_style      );
    STATIC_REQUIRE(quantity_limits::is_iec559             == scalar_limits::is_iec559        );
    STATIC_REQUIRE(quantity_limits::is_bounded            == scalar_limits::is_bounded       );
    STATIC_REQUIRE(quantity_limits::is_modulo             == scalar_limits::is_modulo        );
    STATIC_REQUIRE(quantity_limits::digits                == scalar_limits::digits           );
    STATIC_REQUIRE(quantity_limits::digits10              == scalar_limits::digits10         );
    STATIC_REQUIRE(quantity_limits::max_digits10          == scalar_limits::max_digits10     );
    STATIC_REQUIRE(quantity_limits::radix                 == scalar_limits::radix            );
    STATIC_REQUIRE(quantity_limits::min_exponent          == scalar_limits::min_exponent     );
    STATIC_REQUIRE(quantity_limits::min_exponent10        == scalar_limits::min_exponent10   );
    STATIC_REQUIRE(quantity_limits::max_exponent          == scalar_limits::max_exponent     );
    STATIC_REQUIRE(quantity_limits::max_exponent10        == scalar_limits::max_exponent10   );
    STATIC_REQUIRE(quantity_limits::traps                 == scalar_limits::traps            );
    STATIC_REQUIRE(quantity_limits::tinyness_before       == scalar_limits::tinyness_before  );

    STATIC_REQUIRE(quantity_limits::min().value()         == scalar_limits::min()        );
    STATIC_REQUIRE(quantity_limits::lowest().value()      == scalar_limits::lowest()     );
    STATIC_REQUIRE(quantity_limits::max().value()         == scalar_limits::max()        );
    STATIC_REQUIRE(quantity_limits::epsilon().value()     == scalar_limits::epsilon()    );
    STATIC_REQUIRE(quantity_limits::round_error().value() == scalar_limits::round_error());
    STATIC_REQUIRE(quantity_limits::infinity().value()    == scalar_limits::infinity()   );
    STATIC_REQUIRE(quantity_limits::denorm_min().value()  == scalar_limits::denorm_min() );

    if constexpr(quantity_limits::has_quiet_NaN)
    {
        STATIC_REQUIRE(std::isnan(quantity_limits::quiet_NaN().value()));
    }

    if constexpr(quantity_limits::has_signaling_NaN)
    {
        STATIC_REQUIRE(std::isnan(quantity_limits::signaling_NaN().value()));
    }

}
