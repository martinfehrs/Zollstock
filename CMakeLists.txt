cmake_minimum_required(VERSION 3.22)

project(Zollstock VERSION 0.1.0)

add_library(zollstock INTERFACE)

target_include_directories(zollstock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(zollstock INTERFACE cxx_std_20)

add_subdirectory(dependencies/Catch2)

include(CTest)
add_subdirectory(tests)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set(CPACK_SOURCE_IGNORE_FILES /build;/\\.git/)
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}")
include (CPack)
