add_executable(tests)

target_sources(tests PRIVATE length_unit_tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE zollstock)

include(CTest)
include(Catch)

catch_discover_tests(tests)
