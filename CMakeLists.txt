cmake_minimum_required (VERSION 2.6)

project (example)

# Build engine

add_executable(example game.m.cpp)

# Build test cases

add_subdirectory(test/gtest)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable( test test/test.cpp )
target_link_libraries(test ${GTEST_LIBRARIES})
