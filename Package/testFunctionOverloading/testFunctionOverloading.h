#ifndef testFunctionOverloading_h
#define testFunctionOverloading_h

//C++ libraries
#include <iostream> //for cout, endl
#include <sstream>  //for stringstream

//my libraries

//declarations of functions that are implmented in the .cxx of this folder
//overloading functions means we can define two different functions
//with the same name if they have a different number of arguments
//or even the same number of arguments if the types are not ambiguous
double sum(double a, double b);
double sum(double a, double b, double c);
std::string sum(double a, std::string b);

#endif
