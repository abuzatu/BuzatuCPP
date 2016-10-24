#include "Vector.h"

//constructors

Vector::Vector()
  :x_(0.0),y_(0.0)
{
}

//Vector::Vector(double x, double y)
//{
//  x_=x;
//  y_=y;
//}
//but it's more memory efficienty this way:
Vector::Vector(double x, double y)
  :x_(x),y_(y)
{
}

//the copy constructor
Vector::Vector(const Vector& v)
{
  x_=v.GetX();
  y_=v.GetY();
}

//destructor
Vector::~Vector()
{
}

//setters

void Vector::SetX(double x)
{
  x_=x;
}

void Vector::SetY(double y)
{
  y_=y;
}

void Vector::SetXY(double x, double y)
{
  x_=x;
  y_=y;
}

//getters
double Vector::GetX() const
{
  return x_;
}

double Vector::GetY() const
{
  return y_;
}

double Vector::GetModule() const
{
  return sqrt(x_*x_+y_*y_);
}

//overloading streaming << operator for our class
//it is defined outside of the class, that's why it is not Vector::operator<<, but simply operator<<
std::ostream& operator<<(std::ostream& os, const Vector& rhs)
{
  os <<" x="<<rhs.GetX()<<" y="<<rhs.GetY()<<" module="<<rhs.GetModule();
  //since it is friend, it can access the private members directly, as if they were private, like this
  //os <<" x="<<v.x_<<" y="<<v.y_<<" module="<<v.GetModule();
  return os;
}

//for operators read here:
//http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html

//overload assignement operator
Vector& Vector::operator=(const Vector &rhs) 
{
  //Step 1: check for self-assignement:
  //we should not be allowed to do v=v;

  //this = is a pointer to the object being called
  //&rhs = is a pointer to the object being passed in as the argument

  // Check for self-assignment!
  if (this == &rhs)      // Same object?
    return *this;        // Yes, so skip assignment, and just return *this.
  
  //... // Deallocate, allocate new space, copy values...
  x_=rhs.GetX();
  y_=rhs.GetY();

  //return
  return *this;
}

Vector& Vector::operator+=(const Vector& rhs)
{
  x_+=rhs.GetX();
  y_+=rhs.GetY();
  return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
  x_-=rhs.GetX();
  y_-=rhs.GetY();
  return *this;
}

Vector& Vector::operator*=(double rhs)
{
  x_*=rhs;
  y_*=rhs;
  return *this;
}

const Vector Vector::operator+(const Vector& rhs) const
{
  //declare a new object of type Vector called result
  //and initialize it to the value of the left hand side vector (*this)
  //using the assignement operator defined above
  //this has the same effect of Vector result(*this);
  Vector result=*this;
  //use the compound assignment operator to add the right hand side value to the left hand side value (result)
  result+=rhs;
  //all done, so returning the new object result
  return result;
  //in fact, we wrote three lines to write explicitely all the steps, but we could also write just one line
  //return Vector(*this)+=rhs;
  //This creates an unnamed instance of Vector, which is a copy of *this. Then, the += operator is called on the temporary value, and then returns it. 
}

const Vector Vector::operator-(const Vector& rhs) const
{
  Vector result=*this;
  result-=rhs;
  return result;
}

const Vector Vector::operator*(double rhs) const
{
  Vector result=*this;
  result*=rhs;
  return result;
}

double Vector::operator*(const Vector& rhs) const
{
  return (this->GetX()*rhs.GetX()+this->GetY()*rhs.GetY());
}

bool Vector::operator==(const Vector& rhs) const
{
  bool result;
  double comparison=0.0000001;
  //we can not compare double numbers using == due to rounding errors may seem them be different
  //so we consider they are equal if their absolute difference is smaller tan some very small number
  bool x_the_same = fabs(this->GetX()-rhs.GetX())<comparison;
  bool y_the_same = fabs(this->GetY()-rhs.GetY())<comparison;
  result= x_the_same && y_the_same;
  return result;
}

bool Vector::operator!=(const Vector& rhs) const
{
  return !(*this==rhs);
}
