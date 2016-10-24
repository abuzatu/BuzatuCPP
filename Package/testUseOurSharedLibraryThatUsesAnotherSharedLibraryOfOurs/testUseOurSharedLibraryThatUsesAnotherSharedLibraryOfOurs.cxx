#include "testUseOurSharedLibraryThatUsesAnotherSharedLibraryOfOurs.h"

int main()
{
  double a=3.0;
  std::cout<<"using function defined in Helper:"<<std::endl;
  std::cout<<"square of a="<<a<<" is "<<square(a)<<std::endl;
  std::cout<<"using function defined in Helper2:"<<std::endl;
  print_square(a);

  return 0;
}
