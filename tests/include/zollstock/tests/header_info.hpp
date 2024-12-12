#ifndef __ZOLLSTOCK_TESTS_HEADER_INFO_HPP__
#define __ZOLLSTOCK_TESTS_HEADER_INFO_HPP__


consteval bool includes_length_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_LENGTH_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_mass_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_MASS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_time_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_TIME_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_temperature_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_TEMPERATURE_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_amount_of_substance_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_AMOUNT_OF_SUBSTANCE_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_planar_angle_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_PLANAR_ANGLE_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_area_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_AREA_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_volume_concept() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_VOLUME_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_quantity_concepts() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONCEPTS_HPP__
    return includes_length_concept()
        && includes_mass_concept()
        && includes_time_concept()
        && includes_temperature_concept()
        && includes_amount_of_substance_concept()
        && includes_planar_angle_concept()
        && includes_area_concept()
        && includes_volume_concept();
#else
    return false;
#endif
}

consteval bool includes_quantity_constants() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_quantity_limits() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_LIMITS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_quantity_math() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITIES_MATH_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_unit_one_constant() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_ONE_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_length_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_LENGTH_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_mass_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_MASS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_time_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_TIME_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_temperature_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_TEMPERATURE_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_amount_of_substance_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_AMOUNT_OF_SUBSTANCE_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_angle_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_PLANAR_ANGLE_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_area_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_AREA_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_volume_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_VOLUME_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_squared_time_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_SQUARED_TIME_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_base_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_BASE_HPP__
    return includes_unit_one_constant()
        && includes_length_unit_constants()
        && includes_mass_unit_constants()
        && includes_time_unit_constants()
        && includes_temperature_unit_constants()
        && includes_amount_of_substance_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_derived_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_DERIVED_HPP__
    return includes_unit_one_constant()
        && includes_angle_unit_constants()
        && includes_area_unit_constants()
        && includes_volume_unit_constants()
        && includes_squared_time_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_all_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_CONSTANTS_HPP__
    return includes_base_unit_constants()
        && includes_derived_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_unit_one() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_ONE_HPP__
    return includes_unit_one_constant();
#else
    return false;
#endif
}

consteval bool includes_length_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_LENGTH_HPP__
    return includes_length_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_mass_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_MASS_HPP__
    return includes_mass_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_time_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_TIME_HPP__
    return includes_time_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_temperature_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_TEMPERATURE_HPP__
    return includes_temperature_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_amount_of_substance_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_AMOUNT_OF_SUBSTANCE_HPP__
    return includes_amount_of_substance_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_angle_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_PLANAR_ANGLE_HPP__
    return includes_angle_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_area_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_AREA_HPP__
    return includes_area_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_volume_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_VOLUME_HPP__
    return includes_volume_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_base_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_BASE_HPP__
    return includes_unit_one()
        && includes_length_units()
        && includes_mass_units()
        && includes_time_units()
        && includes_temperature_units()
        && includes_amount_of_substance_units();
#else
    return false;
#endif
}

consteval bool includes_derived_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_DERIVED_HPP__
    return includes_unit_one()
        && includes_angle_units()
        && includes_area_units()
        && includes_volume_units()
        && includes_squared_time_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_units() noexcept
{
#ifdef __ZOLLSTOCK_UNITS_HPP__
    return includes_base_units()
        && includes_derived_units();
#else
    return false;
#endif
}


#endif //__ZOLLSTOCK_TESTS_HEADER_INFO_HPP__
