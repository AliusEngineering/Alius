cmake_minimum_required(VERSION 3.16)
project(AliusSandbox)

add_executable(AliusSandbox main.cpp)

target_link_libraries(AliusSandbox PRIVATE alius)
target_include_directories(AliusSandbox PRIVATE "../")

add_custom_command(TARGET AliusSandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/resources" "${PROJECT_BINARY_DIR}/resources"
        )