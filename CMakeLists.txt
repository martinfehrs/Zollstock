cmake_minimum_required(VERSION 3.22)

project(Zollstock VERSION 0.1.0)

add_library(zollstock OBJECT)

target_include_directories(zollstock PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/si_prefixes_requirements.cpp)
target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/length_units_requirements.cpp)
target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/area_units_requirements.cpp)
target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/volume_units_requirements.cpp)
target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/time_units_requirements.cpp)
target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/angle_units_requirements.cpp)
target_sources(zollstock PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/velocity_units_requirements.cpp)


target_compile_features(zollstock PUBLIC cxx_std_17)

add_subdirectory(dependencies/Catch2)
add_subdirectory(tests)
