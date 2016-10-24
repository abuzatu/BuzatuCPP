// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// now compute the absolute value
// write to the output file

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <sstream> //for stringstream
#include <math.h> //for sqrt

int main () {
  std::string line;
  std::ifstream myfile ("input2D_float.txt");
  float x;
  float y;
  std::ofstream outputfile ("output2D_float.txt");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  std::cout << line << std::endl;
	  std:: stringstream ss(line);
	  ss >> x >> y;
	  std::cout << "x=" << x << " y=" << y << std::endl;
	  float absolute_value = sqrt(x*x+y*y);
	  std::cout << "x=" << x << " y=" << y 
		    << "absolute_value="<<absolute_value<<std::endl;
	  if(outputfile.is_open())
	    {
	      outputfile << "x=" << x << " y=" << y 
		    << " absolute_value="<<absolute_value<<std::endl;
	    }
	  else
	    {
	      std::cout << "Unable to open output file" << std::endl;
	    }
	  
	}
      myfile.close();
    }
  else 
    {
      std::cout << "Unable to open file" << std::endl; 
    }
  return 0;
}
