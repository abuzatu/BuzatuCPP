#include "testDate.h"

int main()
{
  Date date1=Date("2012","02","23");
  Date date2=Date("2014","03","14");
  date1.Print();
  date2.Print();
  std::cout<<"Number of days between the two dates evaluated using a function: "<<date1.Difference(date2,0)<<std::endl;
  std::cout<<"Number of days between the two dates evaluated using an operator: "<<date1-date2<<std::endl;
  //or we can do the same with the operator -
  

  return 0;
}
