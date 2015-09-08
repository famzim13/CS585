cmake_minimum_required ( VERSION 2.6 )

project ( GameDev )

# Build engine

add_executable( example game.m.cpp )

# Build test cases
enable_testing()
find_package( GTest REQUIRED )
find_package( Threads REQUIRED )
include_directories( ${GTEST_INCLUDE_DIRS} )
add_executable( test test/test.cpp )
target_link_libraries( test ${GTEST_BOTH_LIBRARIES} )
target_link_libraries( test ${CMAKE_THREAD_LIBS_INIT} )