// game.m.cpp
#include <iostream>
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/containers/node.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"
#include <string>

int main()
{
  using namespace StevensDev;
  sgdc::Node<std::string>* node = new sgdc::Node<std::string>( "a", "dog" );
  std::cout << "Node key is " << node->getKey() << "\n";
  node->setKey( "b" );
  std::cout << "Node key is " << node->getKey() << "\n";
  sgdc::Map<int>* map = new sgdc::Map<int>();
  (*map)[std::string("a")] = 10;
  (*map)[std::string("a")] = 11;;
  return 0;
}
