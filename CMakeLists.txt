# cmake_minimum_required(VERSION <specify CMake version here>)
project(KPang)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp KPang.cpp KPang.h)
add_executable(KPang ${SOURCE_FILES})