// game.m.cpp
#include <iostream>
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/data/json_parser.h"
#include "src/engine/data/json_entity.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"
#include <string>

int main()
{
  using namespace StevensDev;
  sgdd::JsonParser* parse = new sgdd::JsonParser();
  //parse->fromString( "{ 'name' : 'Configuration', 'values' : [ 1, 3, 'penguin' ] }" );
  return 0;
}
