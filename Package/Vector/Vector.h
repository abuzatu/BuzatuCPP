#ifndef __Vector_h__
#define __Vector_h__

//C++ libraries
#include <math.h> //for sqrt()
#include <iostream> //for cout, endl, ostream

//my libraries

//declarations of functions or classes 
//that are implmented in the .cxx of this folder
class Vector
{
  //methods
 public:
  //constructor
  Vector();
  Vector(double x, double y);
  Vector(const Vector& v);
  
  //destructor
  ~Vector();

  //setters
  void SetX(double x);
  void SetY(double y);
  void SetXY(double x, double y);

  //getters
  double GetX() const;
  double GetY() const;
  double GetModule() const;
  
  //overloading streamer operator, so that we can print the content to cout
  //ex: std::cout<<v<<std::endl;
  //a friend function of the class, i.e. it can access private members of the class
  friend std::ostream& operator<<(std::ostream& os, const Vector& rhs);

  //overloading the assignment operator
  //ex: Vector v1(3.0,4.0); Vector v2=v1;
  //we assign to v2 the value of v1
  //rhs=right hand side
  //Notice that the = operator takes a const-reference to the right hand side of the assignment
  //The reason for this should be obvious, since we don't want to change that value
  //We only want to change what's on the left hand side.
  //Return a reference to the left hand side, which allows to chain and do:
  //Vector v(3.0,4.0);
  //Vector v1,v2,v3,v4;
  //v1=v2=v3=v4=v;
  //read more: http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
  Vector& operator=(const Vector& rhs);

  //compound assignement operators are += , -= and *=
  //they are destructive operators because they change the value on the left

  //addition compounds assignment operator +=

  Vector& operator+=(const Vector& rhs);

  //subtraction compound assignement operator -=
  //ex: Vector v1(3,3); Vector v2(1,1); v1-=v2; 
  //v1 becomes (2,2), v2 remains (1,1)
  Vector& operator-=(const Vector& rhs);

  //multiplication with a number assignement operator *=
  //ex: Vector v1(3,3); double a=2; v1*=2;
  //v1 becomes (6,6), a remans 2
  Vector& operator*=(double rhs);

  //binary arithmetic operators + - *
  //they don't modify either operand, they return a new value from the two arguments
  //it seems complicated, but we can use the already defined compound assignment operators
  //notice the const everywhere
  const Vector operator+(const Vector& rhs) const;
  const Vector operator-(const Vector& rhs) const;
  const Vector operator*(double rhs) const;
  //the vectorial product can only exist in 3D and we have a 2D vector
  //but scalar product can exist in 2D as well; there are no compound assignement operators
  double operator*(const Vector& rhs) const;

  //the comparison operators == and !=
  bool operator==(const Vector& rhs) const;
  bool operator!=(const Vector& rhs) const;
  

 private:

  //members

 private:
  double x_;
  double y_;
  

};

#endif
