#include "testFunctionTemplate.h"

int main()
{
  int a_int=2;
  int b_int=3;
  int sum_of_int=sum_int(a_int,b_int);
  std::cout<<"sum_of_int="<<sum_of_int<<std::endl;

  float a_float=2.0;
  float b_float=3.0;
  float sum_of_float=sum_float(a_float,b_float);
  std::cout<<"sum_of_float="<<sum_of_float<<std::endl;
  
  double a_double=2.0;
  double b_double=3.0;
  double sum_of_double=sum_double(a_double,b_double);
  std::cout<<"sum_of_double="<<sum_of_double<<std::endl;

  std::string a_string="a";
  std::string b_string="b";
  std::string sum_of_string=sum_string(a_string,b_string);
  std::cout<<"sum_of_string="<<sum_of_string<<std::endl;

  //the same thing using a templated class, leading to 
  //a reusable code to use, making our code smaller and easier to maintain
  std::cout<<"sum_of_int="<<sum(a_int,b_int)<<std::endl;
  std::cout<<"sum_of_float="<<sum(a_float,b_float)<<std::endl;
  std::cout<<"sum_of_double="<<sum(a_double,b_double)<<std::endl;
  std::cout<<"sum_of_string="<<sum(a_string,b_string)<<std::endl;

  return 0;
}

int sum_int(int a, int b)
{
  return a+b;
}

float sum_float(float a, float b)
{
  return a+b;
}

double sum_double(double a, double b)
{
  return a+b;
}

std::string sum_string(std::string a, std::string b)
{
  return a+b;
}

template <typename type> type sum(type a, type b)
{
  return a+b;
}
