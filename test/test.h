// test.h
#ifndef INCLUDED_TEST
#define INCLUDED_TEST

#include "gtest/gtest.h"

TEST( AdditionTest, Equal )
{
    ASSERT_EQ( 10, 5+5 );
}

TEST( SubtractionTest, LessThan )
{
    ASSERT_LT( 2, 10-2 );
}

TEST( MultiplicationTest, GreaterThan )
{
    ASSERT_GT( 15, 5*2 );
}

#endif
