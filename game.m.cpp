// game.m.cpp
#include <iostream>
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/containers/trie_node.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"

int main()
{
  using namespace StevensDev;
  sgdm::DefaultAllocator< sgdc::Map<int> > dynAlloc;
  sgdc::Map<int>* map = dynAlloc.get( 1 );
  dynAlloc.construct( map, sgdc::Map<int>() );
  return 0;
}
