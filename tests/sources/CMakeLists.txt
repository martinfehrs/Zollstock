target_sources(tests PRIVATE unit_tests/prefixes.cpp)
target_sources(tests PRIVATE unit_tests/constants/length.cpp)
target_sources(tests PRIVATE unit_tests/literals/length.cpp)
target_sources(tests PRIVATE unit_tests/constants/time.cpp)
target_sources(tests PRIVATE unit_tests/literals/time.cpp)
target_sources(tests PRIVATE unit_tests/constants/mass.cpp)
target_sources(tests PRIVATE unit_tests/literals/mass.cpp)
target_sources(tests PRIVATE unit_tests/constants/area.cpp)
target_sources(tests PRIVATE unit_tests/literals/area.cpp)
target_sources(tests PRIVATE unit_tests/constants/volume.cpp)
target_sources(tests PRIVATE unit_tests/literals/volume.cpp)
target_sources(tests PRIVATE unit_tests/constants/planar_angle.cpp)
target_sources(tests PRIVATE unit_tests/literals/planar_angle.cpp)
target_sources(tests PRIVATE unit_tests/constants/temperature.cpp)
target_sources(tests PRIVATE unit_tests/literals/temperature.cpp)
target_sources(tests PRIVATE unit_tests/constants/one.cpp)
target_sources(tests PRIVATE unit_tests/literals/one.cpp)
target_sources(tests PRIVATE unit_tests/constants/squared_time.cpp)
target_sources(tests PRIVATE unit_tests/constants/velocity.cpp)
target_sources(tests PRIVATE unit_tests/constants/acceleration.cpp)
target_sources(tests PRIVATE unit_tests/constants/angular_velocity.cpp)
target_sources(tests PRIVATE quantity_tests/construction.cpp)
target_sources(tests PRIVATE quantity_tests/quantity.cpp)
target_sources(tests PRIVATE quantity_tests/math.cpp)
target_sources(tests PRIVATE quantity_tests/limits.cpp)

add_subdirectory(header_tests)

if (MSVC)
    target_link_options   (tests PRIVATE "/stack:10000000")
    target_compile_options(tests PRIVATE "/bigobj"        )
endif(MSVC)
