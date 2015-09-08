// test.cpp
#include "gtest/gtest.h"

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

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
