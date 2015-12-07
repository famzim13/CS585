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
find_package(SFML 2.1.0 REQUIRED system window graphics network audio)

# Add Subdirectories
#add_subdirectory( lib/gtest-1.7.0 )

# Include GTest Directories
#include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )
include_directories( ${SFML_INCLUDE_DIR} )

# Add Flags
set( CMAKE_BUILDING_TYPE Debug )

# Add Executables
# add_executable( testing test/test.cpp )
add_executable( example game.m.cpp
    src/engine/actors/iactor.cpp
    src/engine/actors/icontroller.cpp
    src/engine/actors/ifactory.cpp
		src/engine/containers/dynamic_array.cpp
		src/engine/containers/map.cpp
    src/engine/containers/node.cpp
		src/engine/data/json_entity.cpp
		src/engine/data/json_parser.cpp
    src/engine/events/event_bus.cpp
    src/engine/events/event_dispatcher.cpp
    src/engine/events/ievent.cpp
    src/engine/input/input.cpp
		src/engine/memory/counting_allocator.cpp
		src/engine/memory/default_allocator.cpp
		src/engine/memory/iallocator.cpp
		src/engine/memory/stack_guard.cpp
    src/engine/rendering/renderable_sprite.cpp
    src/engine/rendering/renderer.cpp
    src/engine/scene/icollider.cpp
    src/engine/scene/itickable.cpp
    src/engine/scene/nxn_scene_graph.cpp
    src/engine/scene/rectangle_bounds.cpp
    src/engine/scene/scene.cpp )

# Link Libraries
# target_link_libraries( testing gtest gtest_main )
target_link_libraries(example ${SFML_LIBRARIES})
