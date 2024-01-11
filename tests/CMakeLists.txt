add_executable(tests)

target_sources(tests PRIVATE si_prefix_tests.cpp)
target_sources(tests PRIVATE length_unit_type_tests.cpp)
target_sources(tests PRIVATE length_unit_constant_tests.cpp)
target_sources(tests PRIVATE length_unit_literal_tests.cpp)
target_sources(tests PRIVATE time_unit_type_tests.cpp)
target_sources(tests PRIVATE time_unit_constant_tests.cpp)
target_sources(tests PRIVATE time_unit_literal_tests.cpp)
target_sources(tests PRIVATE area_unit_type_tests.cpp)
target_sources(tests PRIVATE area_unit_constant_tests.cpp)
target_sources(tests PRIVATE area_unit_literal_tests.cpp)
target_sources(tests PRIVATE volume_unit_type_tests.cpp)
target_sources(tests PRIVATE volume_unit_constant_tests.cpp)
target_sources(tests PRIVATE volume_unit_literal_tests.cpp)
target_sources(tests PRIVATE angle_unit_type_tests.cpp)
target_sources(tests PRIVATE angle_unit_constant_tests.cpp)
target_sources(tests PRIVATE angle_unit_literal_tests.cpp)
target_sources(tests PRIVATE velocity_unit_type_tests.cpp)


target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE zollstock)

include(CTest)
include(Catch)

catch_discover_tests(tests)
