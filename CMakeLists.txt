cmake_minimum_required(VERSION 3.22)

project(Zollstock VERSION 0.1.0)

add_library(zollstock INTERFACE)

target_include_directories(zollstock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(zollstock INTERFACE cxx_std_17)

add_subdirectory(dependencies/Catch2)
add_subdirectory(tests)
