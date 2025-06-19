add_executable(pcalc pcalc/pcalc.cpp)
target_link_libraries(pcalc zollstock)

if(USE_MODULES)
add_executable(pcalc-modules pcalc/pcalc-modules.cpp)
target_link_libraries(pcalc-modules zollstock)
endif(USE_MODULES)
