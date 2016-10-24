#ifndef testFunctionTemplate_h
#define testFunctionTemplate_h

//C++ libraries
#include <iostream> //for cout, endl

//my libraries

//declarations of functions or classes 
//that are implmented in the .cxx of this folder
int sum_int(int a, int b);
float sum_float(float a, float b);
double sum_double(double a, double b);
std::string sum_string(std::string a, std::string b);

//if we define a templated function, only one, it's enough
//to do what the other four functions from above can do
//also using other classes that we can create, such as Vector
//for which the + opertor is defined

template <typename type> type sum(type a, type b);


#endif
