// reading a text file line by line and printing the entire line


#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>

int main () {
  std::string line;
  std::ifstream myfile ("input2D_float.txt");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  std::cout << line << std::endl;
	}
      myfile.close();
    }
  else 
    {
      std::cout << "Unable to open file"; 
    }
  return 0;
}
