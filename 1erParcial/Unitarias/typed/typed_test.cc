#include "gtest/gtest.h"
#include "hierarchie.h"

template<class instanceType>
class FixTyped : public testing::Test
{
public:
	FixTyped()
	{
		instance2Test = new instanceType;
	}
protected:
	Base *instance2Test; 
};

typedef testing::Types<Child1,Child2> implementations;

TYPED_TEST_CASE(FixTyped,implementations);

TYPED_TEST(FixTyped,testName)
{
	EXPECT_EQ( 1, this->instance2Test->doSomething() );
}