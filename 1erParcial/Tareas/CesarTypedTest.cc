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
	Cifrado *instance2Test; //Debe ser de tipo Cypher
};

typedef testing::Types<Caesar> implementations; //Aqui va Caesar,Otro

TYPED_TEST_CASE(FixTyped,implementations);

TYPED_TEST(FixTyped,testName)
{
	
}