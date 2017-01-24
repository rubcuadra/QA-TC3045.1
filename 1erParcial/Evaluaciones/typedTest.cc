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
	Base<int> *instance2Test;  //Base maybe no deberia de ser tipo template?
};

typedef testing::Types< Ordenamiento<int> > implementations; 

TYPED_TEST_CASE(FixTyped,implementations);

TYPED_TEST(FixTyped,testName)
{
	std::vector<int> arr = {7, 5, 16, 8};
	int *array = &arr[0]; 

	this->instance2Test->burbuja( array , arr.size() , this->instance2Test->desc );
	
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_GE(  arr.at(i) , arr.at(i+1));  // >=
	//EXPECT_EQ( 43, this->instance2Test->doSomething() ); 

}