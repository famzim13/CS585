cmake_minimum_required( VERSION 2.6 )
project( GameDev )

# GTest
add_subdirectory( lib/gtest-1.7.0 )
enable_testing()
include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

# Main application
add_executable( example game.m.cpp )

# Test application
add_subdirectory( test )
add_executable( test test/test.cpp )
target_link_libraries( test gtest gtest_main )