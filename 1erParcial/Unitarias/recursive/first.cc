#include <iostream>
#include "first.h"



int fact(int num)
{
	return num<2?1:num*fact(num-1);
}