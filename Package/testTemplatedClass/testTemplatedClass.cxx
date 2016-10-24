#include "testTemplatedClass.h"

//read more: http://www.cprogramming.com/tutorial/templates.html
//read more: http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part

int main()
{

  {
  //normal class calc developed for int
  calc a;
  int int_x=2;
  int int_y=3;
  int product_int=a.multiply(int_x,int_y);
  int sum_int=a.add(int_x,int_y);
  std::cout<<"int:"
	   <<" x="<<int_x
	   <<" y="<<int_y
	   <<" product="<<product_int
	   <<" sum="<<sum_int
	   <<std::endl;
  }

 
  //if I wanted to create the same add and multiply for not only integers
  //but also float or double, I would have to create new classes
  //but with a template class I can instantiate it for any types we want
  //including the types we have already created as vectors

  //templated class templated calc used for different types

  //int
  templatedcalc<int> a_int;
  int int_x=2;
  int int_y=3;
  int product_int=a_int.multiply(int_x,int_y);
  int sum_int=a_int.add(int_x,int_y);
  std::cout<<"int:"
	   <<" x="<<int_x
	   <<" y="<<int_y
	   <<" product="<<product_int
	   <<" sum="<<sum_int
	   <<std::endl;

  //unsigned
  templatedcalc<unsigned> a_unsigned;
  unsigned unsigned_x=2;
  unsigned unsigned_y=3;
  unsigned product_unsigned=a_unsigned.multiply(unsigned_x,unsigned_y);
  unsigned sum_unsigned=a_unsigned.add(unsigned_x,unsigned_y);
  std::cout<<"unsigned:"
	   <<" x="<<unsigned_x
	   <<" y="<<unsigned_y
	   <<" product="<<product_unsigned
	   <<" sum="<<sum_unsigned
	   <<std::endl;

  //float
  templatedcalc<float> a_float;
  float float_x=2;
  float float_y=3;
  float product_float=a_float.multiply(float_x,float_y);
  float sum_float=a_float.add(float_x,float_y);
  std::cout<<"float:"
	   <<" x="<<float_x
	   <<" y="<<float_y
	   <<" product="<<product_float
	   <<" sum="<<sum_float
	   <<std::endl;

  //double
  templatedcalc<double> a_double;
  double double_x=2;
  double double_y=3;
  double product_double=a_double.multiply(double_x,double_y);
  double sum_double=a_double.add(double_x,double_y);
  std::cout<<"double:"
	   <<" x="<<double_x
	   <<" y="<<double_y
	   <<" product="<<product_double
	   <<" sum="<<sum_double
	   <<std::endl;

  //std::string
  //the * operator is not defined for our class, so we ignore it
  templatedcalc<std::string> a_string;
  std::string string_x=std::string("blah1");
  std::string string_y=std::string("blah2");
  std::string sum_string=a_string.add(string_x,string_y);
  std::cout<<"std::string:"
	   <<" x="<<string_x
	   <<" y="<<string_y
	   <<" sum="<<sum_string
	   <<std::endl;


  //Vector
  //the * operator is not defined for our class, so we ignore it
  templatedcalc<Vector> a_Vector;
  Vector Vector_x=Vector(4.0,5.0);
  Vector Vector_y=Vector(1.0,2.0);
  Vector sum_Vector=a_Vector.add(Vector_x,Vector_y);
  std::cout<<"Vector:"
	   <<" x="<<Vector_x
	   <<" y="<<Vector_y
	   <<" sum="<<sum_Vector
	   <<std::endl;

  //Vector3D
  //the * operator is not defined for our class, so we ignore it
  templatedcalc<Vector3D> a_Vector3D;
  Vector3D Vector3D_x=Vector3D(4.0,5.0,1.0);
  Vector3D Vector3D_y=Vector3D(1.0,2.0,3.0);
  Vector3D sum_Vector3D=a_Vector3D.add(Vector3D_x,Vector3D_y);
  std::cout<<"Vector3D:"
	   <<" x="<<Vector3D_x
	   <<" y="<<Vector3D_y
	   <<" sum="<<sum_Vector3D
	   <<std::endl;

  return 0;
}
