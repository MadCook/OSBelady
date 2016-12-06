cmake_minimum_required (VERSION 3.0)
project (OSBelady)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O3 -std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(beladyA main.cpp
              SimulatedMemory.h SimulatedMemory.cpp)
