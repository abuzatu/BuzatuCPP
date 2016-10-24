#include "testVector.h"

int main()
{
  double x=3.0;
  double y=4.0;

  //create a vector object using the default (empty constructor)
  Vector v1;
  //add the x and y values to it
  v1.SetX(x);
  v1.SetY(y);
  //cout the values
  std::cout<<"v1"<<" x="<<v1.GetX()<<" y="<<v1.GetY()<<" module="<<v1.GetModule()<<std::endl;

  //replace this long expression by the streamer operator
  std::cout<<"v1"<<v1<<std::endl;

  //create a vector using the other contructor that takes as inputs the values x and y
  //then we don't need the SetX(x) and SetY(y) methods any more
  Vector v2(x,y);
  //cout the values
  std::cout<<" "<<std::endl;
  std::cout<<"v2"<<v2<<std::endl;

  //now let's create a vector by using the contructor that takes as an input another vector
  //notice how we pass as an argument not another vector, but a reference to a constant Vector
  //i.e. just the memory address of the Vector object, to pass only a byte of memory
  //as the Vector object is much larger and could be as large as we put quantities in it
  //also note the const, enforcing that the object that is passed by reference will not be changed
  //we will simply read it's values and fill other values
  Vector v3(v1);
  //cout the values
  std::cout<<"v3"<<v3<<std::endl;

  //now let's use the assignment operator
  Vector v4=v1;
  //cout the values
  std::cout<<" "<<std::endl;
  std::cout<<"v4"<<v4<<std::endl;

  //now let's use the addition compound assignement operator
  Vector v5(2.0,2.0);
  Vector v6(1.0,1.0);
  std::cout<<" "<<std::endl;
  std::cout<<"v5"<<v5<<std::endl;
  std::cout<<"v6"<<v6<<std::endl;
  v5+=v6;
  //this will add v6 to v5, but v6 will remain unchanged, we check it
  std::cout<<"v5"<<v5<<std::endl;
  std::cout<<"v6"<<v6<<std::endl;

  //now let's use the subtraction compound assignement operator
  Vector v7(3.0,3.0);
  Vector v8(1.0,1.0);
  std::cout<<" "<<std::endl;
  std::cout<<"v7"<<v7<<std::endl;
  std::cout<<"v8"<<v8<<std::endl;
  v7-=v8;
  //this will subract v8 from v7, but v8 will remain unchanged, we check it
  std::cout<<"v7"<<v7<<std::endl;
  std::cout<<"v8"<<v8<<std::endl;

  Vector v9(3.0,3.0);
  double a=2;
  std::cout<<" "<<std::endl;
  std::cout<<"v9"<<v9<<std::endl;
  std::cout<<"a="<<a<<std::endl;
  v9*=a;
  std::cout<<"v9"<<v9<<std::endl;
  std::cout<<"a="<<a<<std::endl;
  Vector v91=v9*a;
  std::cout<<"v91"<<v91<<std::endl;
  std::cout<<"a="<<a<<std::endl;

  Vector v10(3.0,3.0);
  Vector v11(1.0,1.0);
  Vector v12;
  Vector v13;
  double scalar=0.0;
  std::cout<<" "<<std::endl;
  std::cout<<"v10"<<v10<<std::endl;
  std::cout<<"v11"<<v11<<std::endl;
  std::cout<<"v12"<<v12<<std::endl;
  std::cout<<"v13"<<v13<<std::endl;
  std::cout<<"scalar="<<scalar<<std::endl;
  v12=v10+v11;
  v13=v10-v11;
  scalar=v10*v11;
  std::cout<<"v10"<<v10<<std::endl;
  std::cout<<"v11"<<v11<<std::endl;
  std::cout<<"v12"<<v12<<std::endl;
  std::cout<<"v13"<<v13<<std::endl;
  std::cout<<"scalar="<<scalar<<std::endl;

  Vector v14(3.0,3.0);
  Vector v15(1.0,1.0);
  Vector v16(3,3);
  std::cout<<" "<<std::endl;
  std::cout<<"v14"<<v14<<std::endl;
  std::cout<<"v15"<<v15<<std::endl;
  std::cout<<"v16"<<v16<<std::endl;
  std::cout<<"v14 same to v15 "<<(v14==v15)<<std::endl;
  std::cout<<"v14 same to v16 "<<(v14==v16)<<std::endl;
  std::cout<<"v15 same to v16 "<<(v15==v16)<<std::endl;
  std::cout<<"v14 different than v15 "<<(v14!=v15)<<std::endl;
  std::cout<<"v14 different than v16 "<<(v14!=v16)<<std::endl;
  std::cout<<"v15 different than v16 "<<(v15!=v16)<<std::endl;

  return 0;
}//end main function

