#include "gtest/gtest.h"
#include "Ordenamiento.h"
#include <iostream>
#include <vector>
//g++ -isystem ../../googletest/googletest/include/ -pthread -std=c++11 typedTest.cc  ../Unitarias/gtest_main.a -o prueba
template<class tipoOrdenamiento>
class FixTyped : public testing::Test
{
public:
	FixTyped()
	{
		instance2Test = new tipoOrdenamiento;
	}
protected:
	Base *instance2Test;  //Base maybe no deberia de ser tipo template?
};

typedef testing::Types< Ordenamiento<int> > implementations; 

TYPED_TEST_CASE(FixTyped,implementations);

TYPED_TEST(FixTyped,testName)
{
	//EXPECT_EQ( 43, this->instance2Test->doSomething() ); 
	// Aqui deberia invocar un metodo virtual de base que implementa sorter
}