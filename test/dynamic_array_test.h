// dynamic_array_test.h
#ifndef INCLUDED_DYNAMIC_ARRAY_TEST
#define INCLUDED_DYNAMIC_ARRAY_TEST

#include "gtest/gtest.h"
#include "../src/engine/containers/dynamic_array.h"
#include "../src/engine/memory/counting_allocator.h"
#include "../src/engine/memory/default_allocator.h"
#include "../src/engine/memory/iallocator.h"

TEST( MultipleAllocatorsArrayInitializations, Equal )
{
    using namespace StevensDev;
    sgdm::CountingAllocator<int> count;
    sgdm::IAllocator<int>* alloc = &count;
    sgdc::DynamicArray<int> array( alloc );
    sgdm::CountingAllocator<int> count2;
    sgdm::IAllocator<int>* alloc2 = &count2;
    sgdc::DynamicArray<int> array2( alloc2 );
    ASSERT_EQ( count.getTotalAllocationCount(), 6 );
}

TEST( ArrayInitialization, Equal )
{
    using namespace StevensDev;
    sgdm::CountingAllocator<int> count;
    sgdm::IAllocator<int>* alloc = &count;
    sgdc::DynamicArray<int> array( alloc );
    ASSERT_EQ( count.getAllocationCount(), 3 );    
}

TEST( ArrayMethodsTesting, Equal )
{
    using namespace StevensDev;
    sgdm::CountingAllocator<int> count;
    sgdm::IAllocator<int>* alloc = &count;
    sgdc::DynamicArray<int> array( alloc );
    ASSERT_EQ( array.getCapacity(), 3 );

    array.push( 10 );
    ASSERT_EQ( array.at( 0 ), 10 );

    array.pushFront( 42 );
    ASSERT_EQ( array.at( 0 ), 42 );

    array[1] = 100;
    ASSERT_EQ( array[1], 100 );

    array.insertAt( 1, 147 );
    ASSERT_EQ( array[1], 147 );
    ASSERT_EQ( array[2], 100 );
    array.push( 29 );
    ASSERT_EQ( array.getCapacity(), 4 );
    ASSERT_EQ( array.pop(), 29 );
    ASSERT_EQ( array.popFront(), 42 );
    ASSERT_EQ( array.getLength(), 2 );
    ASSERT_EQ( count.getOutstandingCount(), 4 );

    array.removeAt( 0 );
    ASSERT_EQ( array[0], 100 );
    ASSERT_EQ( array.getCapacity(), 3 );
    ASSERT_EQ( count.getOutstandingCount(), 3 );
    ASSERT_EQ( array.getLength(), 1 );
}

#endif
