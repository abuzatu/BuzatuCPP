#include "testFunctionDefaultValue.h"

int main()
{
  //adds 10.0, 10.0, 10.0
  std::cout<<sum(10.0,10.0,10.0)<<std::endl;
  //if we don't specify the last value, the last value
  //will take the default value from the .h file, 3.0
  std::cout<<sum(10.0,10.0)<<std::endl;
  //if we don't specify the last two values
  //they are taken from the .h file
  std::cout<<sum(10.0)<<std::endl;
  //if we don't specify the last three values (all of them)
  //they are taken from the .h file
  std::cout<<sum()<<std::endl;
  //but if we want to not specify the second value
  //we can't do that,as then we would give two values
  //and the code would think that the last one is not given
  //in conclusion, we can only give up giving values 
  //from the end to the start

  return 0;
}

double sum(double a, double b, double c)
{
  return a+b+c;
}
