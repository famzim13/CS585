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
    std::cout << array.getCapacity() << "\n";

    return 0;
}
