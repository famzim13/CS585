cmake_minimum_required( VERSION 2.8 )
project( GameDev )

# Enable Testing
enable_testing()

# Find Packages
find_package( Threads REQUIRED )

# Add Subdirectories
add_subdirectory( lib/gtest-1.7.0 )

# Include GTest Directories
include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

# Add Executables
add_executable( testing test/test.cpp )
add_executable( example game.m.cpp
		src/engine/containers/dynamic_array.cpp
		src/engine/memory/counting_allocator.cpp
		src/engine/memory/default_allocator.cpp
		src/engine/memory/iallocator.cpp )

# Link Libraries
target_link_libraries( testing gtest gtest_main )
