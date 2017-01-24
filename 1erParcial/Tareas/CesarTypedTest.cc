#include "gtest/gtest.h"
#include "../cyphers/cyphers/Cypher.h"
//#include "hierarchie.h" //Incluir en .h de Caesar

template<class instanceType>
class FixTyped : public testing::Test
{
public:
	FixTyped()
	{
		instance2Test = new instanceType;
	}
protected:
	Base *instance2Test; //Debe ser de tipo Cypher
};

typedef testing::Types<Child1,Child2> implementations; //Aqui va Caesar

TYPED_TEST_CASE(FixTyped,implementations);

TYPED_TEST(FixTyped,testName)
{
	
}