#include "gtest/gtest.h"
#include "hierarchie.h"

template<class T>
Base * factoryMethod()
{
	return new T;
};

template<>
Base* factoryMethod<Child3>()
{
	return new Child3(10);
};

template<class T>
class FixTypedConst : public testing::Test
{
public:
	FixTypedConst() : instance2Test(factoryMethod<T>()){}
	virtual ~FixTypedConst() //FALTA AGREGAR DESTRUCTOR A CHILDS
	{
		delete instance2Test;
		instance2Test=NULL;
	}

protected:
	Base *instance2Test; 
};

typedef testing::Types<Child1,Child2,Child3> implementations;

TYPED_TEST_CASE(FixTypedConst,implementations);

TYPED_TEST(FixTypedConst,testName)
{
	EXPECT_EQ( 1, this->instance2Test->doSomething() );
}