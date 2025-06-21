cmake_minimum_required(VERSION 3.12)
project(raft-kv)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

add_subdirectory(third_party/abseil-cpp)
get_property(targets DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY BUILDSYSTEM_TARGETS)
message(STATUS "Avaiable CMake targets: ${targets}")
add_subdirectory(third_party/spdlog)
add_subdirectory(third_party/tomlplusplus)
add_subdirectory(src)