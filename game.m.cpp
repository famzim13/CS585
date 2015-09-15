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
    sgdm::CountingAllocator<int> count2;
    sgdm::IAllocator<int>* alloc = &count;
    sgdm::IAllocator<int>* alloc2 = &count2;
    sgdc::DynamicArray<int> array( alloc );
    sgdc::DynamicArray<int> array2( alloc2 );
    std::cout << array.getCapacity() << "\n";
    std::cout << array2.getCapacity() << "\n";
    std::cout << count.getAllocationCount() << "\n";
    std::cout << count2.getAllocationCount() << "\n";
    std::cout << count.getTotalAllocationCount() << "\n";
    
    array.push(8);
    array.pushFront(100);
    array.insertAt(1, 10);
    array.insertAt(1, 5);
    array.insertAt(2, 6);
    std::cout << "Pop Front: " << array.popFront() << "\n";
    for(int i=0; i<5; i++)
      std::cout << array[i] << "\n";
    std::cout << "End Post Pop Front\n";
    std::cout << "Pop: " << array.pop() << "\n";
    for(int i=0; i<5; i++)
      std::cout << array[i] << "\n";
    std::cout << "End Post Pop\n";
    std::cout << "Remove At: 1\n";
    array.removeAt(1);
    for(int i=0; i<5; i++)
      std::cout << array[i] << "\n";
    std::cout << "End Post 1st Remove At\n";
    array.removeAt(1);
    for(int i=0; i<5; i++)
      std::cout << array[i] << "\n";
    std::cout << "End Post 2st Remove At\n";
    std::cout << array << "\n";

    return 0;
}
