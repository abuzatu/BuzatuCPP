#include "testFunctionPassByPointer.h"

int main()
{
  double* a=new double;
  std::cout<<"address of a is="<<a<<" value of a is "<<*a<<std::endl;
  *a=1.0;
  std::cout<<"address of a is="<<a<<" value of a is "<<*a<<std::endl;
  change(a);
  std::cout<<"After change(a)"<<std::endl;
  std::cout<<"address of a is="<<a<<" value of a is "<<*a<<std::endl;


  double* b=new double;
  std::cout<<"address of b is="<<b<<" value of b is "<<*b<<std::endl;
  *b=2.2;
  std::cout<<"address of b is="<<b<<" value of b is "<<*b<<std::endl;

  double* c=new double;
  std::cout<<"address of c is="<<c<<" value of c is "<<*c<<std::endl;
  *c=3.3;
  std::cout<<"address of c is="<<c<<" value of c is "<<*c<<std::endl;

  change(a,b,c);
  std::cout<<"After change(a,b,c)"<<std::endl;
  std::cout<<"address of a is="<<a<<" value of a is "<<*a<<std::endl;
  std::cout<<"address of b is="<<b<<" value of b is "<<*b<<std::endl;
  std::cout<<"address of c is="<<c<<" value of c is "<<*c<<std::endl;

  return 0;
}

void change(double* a)
{
  //change the value of a by doubling it
  (*a)*=2;
}

void change(double* a, double* b, double* c)
{
  //change the values by doubling them
  (*a)*=2;
  (*b)*=2;
  (*c)*=2;
}
