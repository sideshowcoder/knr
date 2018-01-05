cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(_CMAKE_TOOLCHAIN_PREFIX "llvm-")

project(knr)

add_subdirectory(tst)
add_subdirectory(src)

enable_testing()
