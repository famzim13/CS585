// game.m.cpp
#include <iostream>
#include "src/engine/containers/dynamic_array.h"
#include "src/engine/memory/counting_allocator.h"
#include "src/engine/memory/default_allocator.h"
#include "src/engine/memory/iallocator.h"

int main()
{
    using namespace StevensDev;
    sgdm::CountingAllocator<int> count;
    sgdm::IAllocator<int>* alloc = &count;
    sgdc::DynamicArray<int> array( alloc );
    array.push( 10 );
    std::cout << array.at( 0 ) << "\n";

    array.pushFront( 42 );
    std::cout << array.at( 0 ) << "\n";

    array[1] = 100;
    std::cout << array[1] << "\n";

    array.insertAt( 1, 147 );
    std::cout << array[2] << " pre push\n";
    array.push( 29 );
    std::cout <<  array.getCapacity() << "\n";
    for(int i = 0; i<4; i++)
      std::cout << array[i] << "\n";
    std::cout << "End for loop\n";
    std::cout << array.pop() << "\n";
    std::cout << array.popFront() << "\n";
    std::cout << array.getLength() << "\n";
    std::cout << count.getOutstandingCount() << "\n";

    array.removeAt( 0 );
    std::cout << array[0] << "\n";
    std::cout << array.getCapacity() << "\n";
    std::cout << count.getOutstandingCount() << "\n";
    std::cout << array.getLength() << "\n";
    return 0;
}
