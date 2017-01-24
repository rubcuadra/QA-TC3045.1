#include "gtest/gtest.h"
#include "almacen.h"
#include "time.h"

class TimeFixture : public ::testing::Test
{

public:
	virtual void SetUp()
	{
		tiempo = time(NULL)
	}

	virtual void TearDown()
	{
		EXPECT_TRUE( (time(NULL)-tiempo<=10) );//Esperamos que sea menor de 10s
	}

private:
	time_t tiempo;
};

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
		TimeFixture::Setup();
	}

	void TearDown()
	{
		TimeFixture::TearDown();
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

TEST_F(AlmacenFixture, time)
{
	//Sleep 11 seconds
}
