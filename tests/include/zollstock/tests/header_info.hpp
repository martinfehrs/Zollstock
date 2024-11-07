#ifndef __ZOLLSTOCK_TESTS_HEADER_INFO_HPP__
#define __ZOLLSTOCK_TESTS_HEADER_INFO_HPP__


consteval bool includes_length_concept() noexcept
{
#ifdef __ZOLLSTOCK_LENGTH_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_mass_concept() noexcept
{
#ifdef __ZOLLSTOCK_MASS_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_time_concept() noexcept
{
#ifdef __ZOLLSTOCK_TIME_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_temperature_concept() noexcept
{
#ifdef __ZOLLSTOCK_TEMPERATURE_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_amount_of_substance_concept() noexcept
{
#ifdef __ZOLLSTOCK_AMOUNT_OF_SUBSTANCE_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_planar_angle_concept() noexcept
{
#ifdef __ZOLLSTOCK_PLANAR_ANGLE_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_area_concept() noexcept
{
#ifdef __ZOLLSTOCK_AREA_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_volume_concept() noexcept
{
#ifdef __ZOLLSTOCK_VOLUME_CONCEPT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_quantity_concepts() noexcept
{
#ifdef __ZOLLSTOCK_QUANTITY_CONCEPTS_HPP__
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

consteval bool includes_unit_one_constant() noexcept
{
#ifdef __ZOLLSTOCK_UNIT_ONE_CONSTANT_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_length_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_LENGTH_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_mass_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_MASS_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_time_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_temperature_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_TEMPERATURE_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_amount_of_substance_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_AMOUNT_OF_SUBSTANCE_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_angle_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_PLANAR_ANGLE_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_area_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_AREA_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_volume_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_VOLUME_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_squared_time_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_SQUARED_TIME_UNIT_CONSTANTS_HPP__
    return true;
#else
    return false;
#endif
}

consteval bool includes_base_unit_constants() noexcept
{
#ifdef __ZOLLSTOCK_BASE_UNIT_CONSTANTS_HPP__
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
#ifdef __ZOLLSTOCK_DERIVED_UNIT_CONSTANTS_HPP__
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
#ifdef __ZOLLSTOCK_ALL_UNIT_CONSTANTS_HPP__
    return includes_base_unit_constants()
        && includes_derived_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_unit_one() noexcept
{
#ifdef __ZOLLSTOCK_UNIT_ONE_HPP__
    return includes_unit_one_constant();
#else
    return false;
#endif
}

consteval bool includes_length_units() noexcept
{
#ifdef __ZOLLSTOCK_LENGTH_UNITS_HPP__
    return includes_length_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_mass_units() noexcept
{
#ifdef __ZOLLSTOCK_MASS_UNITS_HPP__
    return includes_mass_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_time_units() noexcept
{
#ifdef __ZOLLSTOCK_TIME_UNITS_HPP__
    return includes_time_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_temperature_units() noexcept
{
#ifdef __ZOLLSTOCK_TEMPERATURE_UNITS_HPP__
    return includes_temperature_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_amount_of_substance_units() noexcept
{
#ifdef __ZOLLSTOCK_AMOUNT_OF_SUBSTANCE_UNITS_HPP__
    return includes_temperature_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_angle_units() noexcept
{
#ifdef __ZOLLSTOCK_PLANAR_ANGLE_UNITS_HPP__
    return includes_angle_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_area_units() noexcept
{
#ifdef __ZOLLSTOCK_AREA_UNITS_HPP__
    return includes_area_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_volume_units() noexcept
{
#ifdef __ZOLLSTOCK_VOLUME_UNITS_HPP__
    return includes_volume_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_base_units() noexcept
{
#ifdef __ZOLLSTOCK_BASE_UNITS_HPP__
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
#ifdef __ZOLLSTOCK_DERIVED_UNITS_HPP__
    return includes_unit_one()
        && includes_angle_units()
        && includes_area_units()
        && includes_volume_units()
        && includes_squared_time_unit_constants();
#else
    return false;
#endif
}

consteval bool includes_all_units() noexcept
{
#ifdef __ZOLLSTOCK_ALL_UNITS_HPP__
    return includes_base_units()
        && includes_derived_units();
#else
    return false;
#endif
}


#endif //__ZOLLSTOCK_TESTS_HEADER_INFO_HPP__
