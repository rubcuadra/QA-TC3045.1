#include <iostream>
using namespace std;

class Base
{
public:
  virtual int doSomething() = 0;

};

class Child1 : public Base
{
public:
  int doSomething()
  {
    cout << "Im child 1";
    return 1;
  }
};

class Child2 : public Base
{
public:
  int doSomething()
  {
    cout << "Im child 2";
    return 1;
  }
};

class Child3 : public Base
{
private:
  int value;
public:
  Child3(int val):value(val){}

  int doSomething()
  {
    cout << "Im child 3 with value "<<value<<"\n";
    return 1;
  }
};
