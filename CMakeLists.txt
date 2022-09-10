# Latest feature: precompiled headers (3.16+)
cmake_minimum_required(VERSION 3.16)
project(alius)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Include dependencies
include("CMakeDependencies.txt")

# Compile target - glob everything under ./Alius
file(GLOB_RECURSE alius_sources CONFIGURE_DEPENDS "Alius/**")
message(STATUS "Sources are: ${alius_sources}")

add_library(alius ${alius_sources})

target_precompile_headers(alius PUBLIC "Alius/Core/AliusCore.hpp")

target_include_directories(alius PUBLIC
        ${LOGGER_INCLUDES}
        Alius
        )

target_link_libraries(alius PUBLIC
        ${LOGGER_LIBS}
        glfw
        )


## Temporary target: test application
add_executable(alius_app main.cpp)
target_link_libraries(alius_app PUBLIC alius)
