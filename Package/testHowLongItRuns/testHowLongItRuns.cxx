#include "testHowLongItRuns.h"

int main()
{
  std::cout<<" ***** Start test.exe ***** "<<std::endl;
  //will use these to count the number of seconds it took to run our code
  clock_t t_start, t_end;
  t_start=clock();

  
  t_end=clock();
  float seconds=((float)t_end-(float)t_start)/CLOCKS_PER_SEC;
  float minutes=seconds/60.0;
  float hours=seconds/3600.0;
  std::cout<<"Ran for "<<seconds<<" seconds; or "<<minutes<<" minutes, or "
	   <<hours<<" hours."<<std::endl;
  std::cout<<" ***** End test.exe ***** "<<std::endl;
  return 0;
}
