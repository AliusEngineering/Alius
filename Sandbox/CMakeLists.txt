cmake_minimum_required(VERSION 3.16)
project(AliusSandbox)

if (NOT DEFINED ALS_BINARY_LOCATION)
    message(STATUS "ALS_BINARY_LOCATION property not set! Setting it to PROJECT_BINARY_DIR (current project binary output directory)")
    set(ALS_BINARY_LOCATION ${PROJECT_BINARY_DIR})
endif ()

add_executable(AliusSandbox main.cpp)

target_link_libraries(AliusSandbox PRIVATE alius)
target_include_directories(AliusSandbox PRIVATE "../")

set_target_properties(AliusSandbox PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${ALS_BINARY_LOCATION}")