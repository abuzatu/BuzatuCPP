#ifndef __TemplatedClass_h__
#define __TemplatedClass_h__

//read more: http://www.cprogramming.com/tutorial/templates.html
//read more: http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part

//C++ libraries
#include <iostream>

//my libraries

//declarations of functions or classes 
//that are implmented in the .cxx of this folder
//class calc declaration
class calc
{
  public:
    int multiply(int x, int y);
    int add(int x, int y);
};

//the implementation for class calc
//can be in the .cxx file, as normally
//however, for the template class
//the implementation has to be in the header file

//class templatedcalc declaration
template <class T> class templatedcalc
{
 public:
  T multiply(T x, T y);
  T add(T x, T y);
};

//the implementation for templatedcalc has to be 
//in the same header file, otherweise this class 
//will compile, but testTemplatedClass won't
template <class T> 
T templatedcalc<T>::multiply(T x,T y)
{
  return x*y;
}

template <class T> 
T templatedcalc<T>::add(T x, T y)
{
  return x+y;
}

#endif
