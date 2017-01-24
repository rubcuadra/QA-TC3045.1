#include "gtest/gtest.h"
#include "Ordenamiento.h"
#include <iostream>
#include <vector>
//Dentro de Evaluaciones
// g++ -isystem ../../googletest/googletest/include/ -pthread -std=c++11 valueParam.cc ../Unitarias/gtest_main.a -o prueba
// ./prueba.out
class FixValParam : public testing::TestWithParam< std::vector<int> >
{
public:
	static Ordenamiento<int> * sorter;

	static void SetUpTestCase()
	{
		sorter = new Ordenamiento<int>();
	}

	void SetUp()
	{

	}

	void TearDown()
	{

	}

	static void TestDownTestCase()
	{
		delete sorter;
	}
};

Ordenamiento<int> * FixValParam::sorter = 0;

TEST_P(FixValParam,burbujas_asc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; //Array necesario por que asi fue creado el .h

	sorter->burbuja( array , arr.size() , sorter->asc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_LE( arr.at(i) , arr.at(i+1));	// <=
}

TEST_P(FixValParam,burbujas_desc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; 
	sorter->burbuja( array , arr.size() , sorter->desc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_GE(  arr.at(i) , arr.at(i+1));  // >=
}

TEST_P(FixValParam,insercion_asc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; //Array necesario por que asi fue creado el .h

	sorter->insercion( array , arr.size() , sorter->asc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_LE( arr.at(i) , arr.at(i+1));	// <=
}

TEST_P(FixValParam,insercion_desc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; 
	sorter->insercion( array , arr.size() , sorter->desc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_GE(  arr.at(i) , arr.at(i+1));  // >=
}

TEST_P(FixValParam,seleccion_asc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; //Array necesario por que asi fue creado el .h

	sorter->seleccion( array , arr.size() , sorter->asc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_LE( arr.at(i) , arr.at(i+1));	// <=
}

TEST_P(FixValParam,seleccion_desc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; 
	sorter->seleccion( array , arr.size() , sorter->desc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_GE(  arr.at(i) , arr.at(i+1));  // >=
}

TEST_P(FixValParam,quicksort_asc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; //Array necesario por que asi fue creado el .h

	sorter->quicksort( array , 0,arr.size() , sorter->asc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_LE( arr.at(i) , arr.at(i+1));	// <=
}

TEST_P(FixValParam,quicksort_desc)
{
	std::vector<int> arr = GetParam();
	int *array = &arr[0]; 
	sorter->quicksort( array , 0,arr.size() , sorter->desc );
	for (int i = 0; i < arr.size()-1; ++i)
		EXPECT_GE(  arr.at(i) , arr.at(i+1));  // >=
}

std::vector<int> v1 = {7, 5, 16, 8};
std::vector<int> v2 = {10, 3, 22, 112};

INSTANTIATE_TEST_CASE_P(UsingValues,FixValParam,testing::Values(v1,v2));

//INSTANTIATE_TEST_CASE_P(Values,FixValParam,testing::Values(2,4,6,8));