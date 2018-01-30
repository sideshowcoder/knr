cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(_CMAKE_TOOLCHAIN_PREFIX "llvm-")

project(knr)

# This is a project for learning so no reason to no include debug
set(CMAKE_BUILD_TYPE Debug)
# Export compile_commands.json for use with irony mode and clang this needs to
# be defined after project see
# https://gitlab.kitware.com/cmake/cmake/issues/16588
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(tst)
add_subdirectory(src)

enable_testing()
