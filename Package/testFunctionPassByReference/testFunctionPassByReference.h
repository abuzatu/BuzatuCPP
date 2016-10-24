#ifndef testFunctionPassByReference_h
#define testFunctionPassByReference_h

//C++ libraries
#include <iostream> //for cout, endl

//my libraries

//declarations of functions or classes 
//that are implmented in the .cxx of this folder

//function takes the variable a of type double by reference
//in the function we have access to the same variable a
//if we did void change(double a) inside the function
//we would not have access to a, but to a clone of a, a new copy of a
//that is why if we changed a in the function, outside the function a
//would remain unchanged
//but if we pass by reference, we can change the original value in the function
void change(double& a);

//by the same logic we can pass several variables by reference
//this is a way to change several variables inside a function
//in C++ a function can only return one variable (returning a clone to it)
//so if we want to return more than one variable, the only way is to 
//pass them by reference (or by pointer) 
//and change them inside the function and not
//return anything at all, so returning void
void change(double& a, double& b, double& c);

#endif
