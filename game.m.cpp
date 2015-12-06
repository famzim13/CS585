// game.m.cpp
#include <iostream>
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/data/json_parser.h"
#include "src/engine/data/json_entity.h"
#include "src/engine/events/event_dispatcher.h"
#include "src/engine/events/ievent.h"
#include "src/engine/input/input.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"
#include "src/engine/rendering/renderable_sprite.h"
#include "src/engine/rendering/renderer.h"
#include "src/engine/scene/icollider.h"
#include "src/engine/scene/itickable.h"
#include "src/engine/scene/nxn_scene_graph.h"
#include "src/engine/scene/rectangle_bounds.h"
#include "src/engine/scene/scene.h"
#include <string>

int main()
{
  using namespace StevensDev;
  sgdd::JsonParser* parse = new sgdd::JsonParser();
  //parse->fromString( "{ 'name' : 'Configuration', 'values' : [ 1, 3, 'penguin' ] }" );
  return 0;
}
