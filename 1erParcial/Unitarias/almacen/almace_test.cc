#include gtest/gtest.h
#include "almacen.h"

class AlmacenFixture : public 
{
public:
	SetUp(){}

	TearDown(){}
private:
	static Almacen a(10);
};