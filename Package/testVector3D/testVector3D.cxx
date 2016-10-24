#include "testVector3D.h"

int main()
{
  double x=3.0;
  double y=4.0;
  double z=4.0;

  //create a vector object using the default (empty constructor)
  Vector3D v1;
  //add the x, y and z values to it
  v1.SetX(x);
  v1.SetY(y);
  v1.SetY(z);
  //cout the values
  std::cout<<"v1"<<" x="<<v1.GetX()<<" y="<<v1.GetY()
	   <<" z="<<v1.GetZ()<<" module="<<v1.GetModule()<<std::endl;

  //replace this long expression by the streamer operator
  std::cout<<"v1"<<v1<<std::endl;

  //create a vector using the other contructor that takes as inputs the values x and y
  //then we don't need the SetX(x) and SetY(y) methods any more
  Vector3D v2(x,y,z);
  //cout the values
  std::cout<<" "<<std::endl;
  std::cout<<"v2"<<v2<<std::endl;

  //now let's create a vector by using the contructor that takes as an input another vector
  //notice how we pass as an argument not another vector, but a reference to a constant Vector3D
  //i.e. just the memory address of the Vector3D object, to pass only a byte of memory
  //as the Vector3D object is much larger and could be as large as we put quantities in it
  //also note the const, enforcing that the object that is passed by reference will not be changed
  //we will simply read it's values and fill other values
  Vector3D v3(v1);
  //cout the values
  std::cout<<"v3"<<v3<<std::endl;

  //now let's use the assignment operator
  Vector3D v4=v1;
  //cout the values
  std::cout<<" "<<std::endl;
  std::cout<<"v4"<<v4<<std::endl;

  //now let's use the addition compound assignement operator
  Vector3D v5(2.0,2.0,5.0);
  Vector3D v6(1.0,1.0,3.0);
  std::cout<<" "<<std::endl;
  std::cout<<"v5"<<v5<<std::endl;
  std::cout<<"v6"<<v6<<std::endl;
  v5+=v6;
  //this will add v6 to v5, but v6 will remain unchanged, we check it
  std::cout<<"v5"<<v5<<std::endl;
  std::cout<<"v6"<<v6<<std::endl;

  //now let's use the subtraction compound assignement operator
  Vector3D v7(3.0,3.0,5.0);
  Vector3D v8(1.0,1.0,2.0);
  std::cout<<" "<<std::endl;
  std::cout<<"v7"<<v7<<std::endl;
  std::cout<<"v8"<<v8<<std::endl;
  v7-=v8;
  //this will subract v8 from v7, but v8 will remain unchanged, we check it
  std::cout<<"v7"<<v7<<std::endl;
  std::cout<<"v8"<<v8<<std::endl;

  Vector3D v9(3.0,3.0,3.0);
  double a=2;
  std::cout<<" "<<std::endl;
  std::cout<<"v9"<<v9<<std::endl;
  std::cout<<"a="<<a<<std::endl;
  v9*=a;
  std::cout<<"v9"<<v9<<std::endl;
  std::cout<<"a="<<a<<std::endl;
  Vector3D v91=v9*a;
  std::cout<<"v91"<<v91<<std::endl;
  std::cout<<"a="<<a<<std::endl;


  Vector3D v10(3.0,4.0,5.0);
  Vector3D v11(1.0,2.0,3.0);
  Vector3D v12;
  Vector3D v13;
  double scalar_product=0.0;
  Vector3D vectorial_product;
  std::cout<<" "<<std::endl;
  std::cout<<"v10"<<v10<<std::endl;
  std::cout<<"v11"<<v11<<std::endl;
  std::cout<<"v12"<<v12<<std::endl;
  std::cout<<"v13"<<v13<<std::endl;
  std::cout<<"scalar_product="<<scalar_product<<std::endl;
  std::cout<<"vectorial_product="<<vectorial_product<<std::endl;
  v12=v10+v11;
  v13=v10-v11;
  scalar_product=v10*v11;
  vectorial_product=v10^v11;
  std::cout<<"v10"<<v10<<std::endl;
  std::cout<<"v11"<<v11<<std::endl;
  std::cout<<"v12"<<v12<<std::endl;
  std::cout<<"v13"<<v13<<std::endl;
  std::cout<<"scalar_product="<<scalar_product<<std::endl;
  std::cout<<"vectorial_product="<<vectorial_product<<std::endl;

  Vector3D v14(3.0,3.0,3.0);
  Vector3D v15(1.0,1.0,1.0);
  Vector3D v16(3,3,3);
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

