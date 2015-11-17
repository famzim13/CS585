// game.m.cpp
#include <iostream>
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/containers/map.h"
#include "src/engine/containers/node.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"
#include "string.h"

int main()
{
  using namespace StevensDev;
  sgdc::Node<int>* node = new sgdc::Node<int>();
  node->setValue() = 10;
  sgdc::Node<int>* node2 = new sgdc::Node<int>();
  node2->setValue() = 20;
  node->setNext( *node2 );
  std::cout << "Size of node is " << sizeof(node) << "\n";
  std::cout << "Node value is " << node->getValue() << "\n";
  std::cout << "Node2 value is " << node->getNext()->getValue() << "\n";
  node2->setValue() = 60;
  std::cout << "Node2 value is " << node->getNext()->getValue() << "\n";
  sgdc::Map<int>* map = new sgdc::Map<int>();
  (*map)[std::string("a")] = 10;
  (*map)[std::string("a")] = 11;;
  return 0;
}
