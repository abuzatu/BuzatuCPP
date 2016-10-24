#include "testWriteToFile.h"

int main()
{
  const char* filename="./data/outputfile.txt";
  std::ofstream file(filename);
  if (!file.is_open())
    {
      std::cout<<"file called "<<filename<<" could not be opened. Will ABORT!"<<std::endl;
      assert(false);
    }
  std::string name="car";
  int number_integer=2;
  float number_float=2.2;
  file<<name<<" "<<number_integer<<" "<<number_float<<std::endl;
  file.close();

  return 0;
}
