#include "testFunctionPassByReference.h"

int main()
{
  double a=1.0;
  std::cout<<"before a="<<a<<std::endl;
  change(a);
  std::cout<<"after  a="<<a<<std::endl;

  double b=2.2;
  double c=3.3;
  std::cout<<"before a="<<a<<" b="<<b<<" c="<<c<<std::endl;
  change(a,b,c);
  std::cout<<"after  a="<<a<<" b="<<b<<" c="<<c<<std::endl;
  
  return 0;
}

void change(double& a)
{
  //change the value of a by doubling it
  a*=2;
}
void change(double& a, double& b, double& c)
{
  //change the values by doubling them
  a*=2;
  b*=2;
  c*=2;
}
