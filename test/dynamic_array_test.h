// dynamic_array_test.h
#ifndef INCLUDED_DYNAMIC_ARRAY_TEST
#define INCLUDED_DYNAMIC_ARRAY_TEST

#include "gtest/gtest.h"
#include "../src/engine/containers/dynamic_array.h"
#include "../src/engine/memory/counting_allocator.h"
#include "../src/engine/memory/default_allocator.h"
#include "../src/engine/memory/iallocator.h"

TEST( AdditionTest, Equal )
{
    ASSERT_EQ( 5+5, 10 );
}

TEST( SubtractionTest, LessThan )
{
    ASSERT_LT( 10-9, 2 );
}

TEST( MultiplicationTest, GreaterThan )
{
    ASSERT_GT( 5*4, 15 );
}

#endif
