// game.m.cpp
#include <iostream>
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"
#include <string>

int main()
{
  using namespace StevensDev;
  sgdc::DynamicArray<int>* numbers = new sgdc::DynamicArray<int>();
  numbers->push( 10 );
  std::cout << "Initializing map\n";
  sgdc::Map<std::string>* map = new sgdc::Map<std::string>();
  std::cout << "Map was initialized\n";
  (*map)[std::string("ab")] = "Apple";
  std::cout << "Node with key 'ab' has value of " << (*map)[std::string("ab")] << "\n";
  (*map)[std::string("ba")] = "Banana";
  std::cout << "Node with key 'ba' has value of " << (*map)[std::string("ba")] << "\n";
  (*map)[std::string("j")] = "Oranges";
  std::cout << "Node with key 'j' has value of " << (*map)[std::string("j")] << "\n";
  std::cout << map->has( "ab" ) << " and " << map->has( "q" ) << "\n";
  sgdc::DynamicArray<std::string> values = map->values();
  sgdc::DynamicArray<std::string> keys = map->keys();
  std::cout << "This is the main\n";
  for( int i=0; i<values.getLastIndex(); i++ )
  {
    std::cout << values.at(i) << "\n";
  }
  std::cout << "The for loop ended\n";
  return 0;
}
