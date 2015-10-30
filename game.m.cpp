// game.m.cpp
#include <iostream>
//#include "src/engine/containers/dynamic_array.h"
//#include "src/engine/containers/map.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"

int main()
{
  using namespace StevensDev;
  sgdm::DefaultAllocator<int> defAlloc;
  sgdm::CountingAllocator<int> count;
  sgdm::IAllocator<int>* alloc = &count;
  int* x = alloc->get( 10 );
  alloc->release( x, 10 );
  return 0;
}
