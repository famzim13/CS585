cmake_minimum_required (VERSION 2.6)

project (example)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(example game.m.cpp)
target_link_libraries(example ${GTEST_LIBRARIES})
