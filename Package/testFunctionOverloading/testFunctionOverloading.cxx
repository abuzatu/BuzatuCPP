#include "testFunctionOverloading.h"

int main()
{
  std::cout<<"Adding 1.0 and 2.0 gets "<<sum(1.0,2.0)<<std::endl;
  std::cout<<"Adding 1.0, 2.0, and 3.0 gets "<<sum(1.0,2.0,3.0)<<std::endl;
  std::cout<<"Adding 2.2, and blah gets "<<sum(2.2,"blah")<<std::endl;
  return 0;
}

double sum(double a, double b)
{
  return a+b;
}

double sum(double a, double b, double c)
{
  return a+b+c;
}

std::string sum(double a, std::string b)
{
  //first convert a number to a string
  std::stringstream s;
  s<<a;
  std::string a_string=s.str();
  return a_string+b;
}


