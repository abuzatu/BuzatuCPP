#include "testReadFromFile.h"

int main()
{
  const char* filename("../data/inputfile.txt");
  std::ifstream inputfile(filename);
  if (!inputfile.is_open())
    {
      std::cout<<"File named "<<filename<<" could not be opened. Will ABORT"<<std::endl;
      assert(false);
    }

  std::string name="";
  int number_integer=0;
  float number_float=0.0;
  std::string sum_name="";
  int sum_number_integer=0;
  float sum_number_float=0.0;
  while(inputfile>>name>>number_integer>>number_float)
    {
      std::cout<<"name="<<name;
      std::cout<<" number_integer="<<number_integer;
      std::cout<<" number_float="<<number_float;
      std::cout<<std::endl;
      sum_name+=name;
      sum_number_integer+=number_integer;
      sum_number_float+=number_float;
    }
  std::cout<<"sum_name="<<sum_name;
  std::cout<<" sum_number_integer="<<sum_number_integer;
  std::cout<<" sum_number_float="<<sum_number_float;
  std::cout<<std::endl;

  //we prove that they are treated as numbers as their sum looks good
  //for strings, the + opertor means concatenation  

  return 0;
}
