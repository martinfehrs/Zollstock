add_executable(tests)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE zollstock)

add_subdirectory(sources)

include(CTest)
include(Catch)

catch_discover_tests(tests)
