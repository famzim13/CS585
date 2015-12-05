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
  sgdc::DynamicArray<int>* numbers = new sgdc::DynamicArray<int>();
  numbers->push( 10 );
  sgdc::Map<int>* map = new sgdc::Map<int>();
  (*map)[std::string("ab")] = 10;
  std::cout << "Node with key 'ab' has value of " << (*map)[std::string("ab")] << "\n";
  (*map)[std::string("ba")] = 11;
  std::cout << "Node with key 'ba' has value of " << (*map)[std::string("ba")] << "\n";
  (*map)[std::string("j")] = 12;
  std::cout << "Node with key 'j' has value of " << (*map)[std::string("j")] << "\n";
  std::cout << map->has( "ab" ) << " and " << map->has( "q" ) << "\n";
  sgdc::DynamicArray<int> values = map->values();
  sgdc::DynamicArray<std::string> keys = map->keys();
  std::cout << "This is the main\n";
  for( int i=0; i<keys.getLastIndex(); i++ )
  {
    std::cout << keys.at(i) << "\n";
  }
  std::cout << "The for loop ended\n";
  return 0;
}
