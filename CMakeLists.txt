cmake_minimum_required( VERSION 2.8 )
project( GameDev )

# Set C++ Version
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++14" HAS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++1y" HAS_CXX1Y)
CHECK_CXX_COMPILER_FLAG("-std=c++11" HAS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" HAS_CXX0x)
if(HAS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(HAS_CXX1Y)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
elseif(HAS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(HAS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif()

# Enable Testing
enable_testing()

# Find Packages
find_package( Threads REQUIRED )

# Add Subdirectories
add_subdirectory( lib/gtest-1.7.0 )

# Include GTest Directories
include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

# Add Executables
# add_executable( testing test/test.cpp )
add_executable( example game.m.cpp
		src/engine/memory/counting_allocator.cpp
		src/engine/memory/default_allocator.cpp
		src/engine/memory/iallocator.cpp )

# Link Libraries
# target_link_libraries( testing gtest gtest_main )
