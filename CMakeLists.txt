# Latest feature: precompiled headers (3.16+)
cmake_minimum_required(VERSION 3.16)
project(alius)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Define build type before including anything
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "[Alius] Building in Debug.")
    set(ALS_BUILD_TYPE "Debug")
    add_compile_definitions(ALS_DEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "[Alius] Building in Release.")
    set(ALS_BUILD_TYPE "Release")
    add_compile_definitions(ALS_RELEASE)
endif ()

# Should be used in all projects depending on Alius to copy resources correctly
set(ALS_BINARY_LOCATION ${CMAKE_BINARY_DIR})

# Include dependencies
include("CMakeDependencies.txt")

# Compile target - glob everything under ./Alius
file(GLOB_RECURSE alius_sources CONFIGURE_DEPENDS "Alius/**")
message(STATUS "[Alius] Sources are: ${alius_sources}")

add_library(alius ${alius_sources})

# Core components
include("AliusBaseComponents.txt")

target_precompile_headers(alius PUBLIC "Alius/Core/AliusCore.hpp")

target_include_directories(alius PUBLIC
        ${LOGGER_INCLUDES}
        Alius
        )

target_link_libraries(alius PUBLIC ${LOGGER_LIBS} glfw)

# Sandbox application
add_subdirectory("Sandbox")
