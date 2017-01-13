#include "gtest/gtest.h"
#include "almacen.h"

class TimeFixture : public ::testing::Test
{
	static void SetUpTestCase(){}

	void SetUp(){}

	void TearDown(){}

	static void TestDownTestCase(){}
}

class AlmacenFixture : public ::testing::Test
{

public:
	static Almacen<int> *a;

	static void SetUpTestCase()
	{
		a = new Almacen<int>(10);
	}

	void SetUp()
	{
		a->add(20);
		a->add(10);
	}

	void TearDown()
	{
		a->clear();
	}

	static void TestDownTestCase()
	{
		delete a;
	}
	
};
Almacen<int> * AlmacenFixture::a = 0;

TEST_F(AlmacenFixture, capacidad)
{
	ASSERT_EQ(10,a->getCapacity());
}

TEST_F(AlmacenFixture, size)
{
	ASSERT_EQ(2,a->getSize());
}
