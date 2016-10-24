#include "testUseOurSharedLibrary.h"

int main()
{
  //test usage of functions in Helper file
  //just regular functions can be compiled as a shared library
  double a=3.0;
  double b=4.0;
  double sum_in_quadrature=add_in_quadrature(a,b);
  std::cout<<"a="<<a<<" b="<<b
	   <<" sum in quadrature="<<sum_in_quadrature<<std::endl;
  double square_of_a=square(a);
  std::cout<<"a="<<a<<" a*a="<<square_of_a<<std::endl;

  return 0;
}
