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
    
    array.push(1);
    std::cout << array.at(0) << "\n";
    std::cout << array[0] << "\n";
    array[0] = 15;
    std::cout << array[0] << "\n";

    return 0;
}
