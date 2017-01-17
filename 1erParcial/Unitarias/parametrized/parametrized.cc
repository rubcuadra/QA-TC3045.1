#include "gtest/gtest.h"
#include "functions.h"

class FixValParam : public testing::TestWithParam<int>
{
public:
	void SetUp(){}
	void TearDown(){}
};

TEST_P(FixValParam,pares)
{
	if (GetParam()%2 == 0)
		EXPECT_EQ(true, isEven(GetParam()) );
	else
		EXPECT_EQ(false, isEven(GetParam()) );

}
TEST_P(FixValParam,nones)
{
	if (GetParam()%2 == 1)
		EXPECT_EQ(true, isOdd(GetParam()) );
	else
		EXPECT_EQ(false, isOdd(GetParam()) );
}

int array[] = {1,2,3,4,5,6,7,8,9}; //Pudo ser un vector
INSTANTIATE_TEST_CASE_P(UsingValuesIn,FixValParam,testing::ValuesIn(array));

INSTANTIATE_TEST_CASE_P(Values,FixValParam,testing::Values(2,4,6,8));