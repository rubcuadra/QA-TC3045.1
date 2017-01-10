#include "first.h"
#include "gtest/gtest.h"

TEST(f_Factorial,positivos)
{
	ASSERT_EQ(1, fact(1) );
	ASSERT_EQ(120, fact(5) );
}

TEST(f_Factorial,negativos)
{
	ASSERT_EQ(1, fact(-1) );
	ASSERT_EQ(1, fact(-5) );
}

TEST(f_Factorial,zero)
{
	ASSERT_EQ(1, fact(0) );
}