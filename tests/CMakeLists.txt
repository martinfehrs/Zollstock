add_executable(tests)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE zollstock)

target_compile_features(tests PRIVATE cxx_std_20)


add_subdirectory(sources)

include(Catch)
catch_discover_tests(tests WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_test(NAME pcalc COMMAND $<TARGET_FILE:pcalc> 1 15 2)

set_property(
    TEST pcalc
    PROPERTY PASS_REGULAR_EXPRESSION "^pipe mass: 7125\.13 kg"
)
