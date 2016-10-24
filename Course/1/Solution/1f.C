// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// now compute the absolute value
// write to the output file
// write exactly two digits all the time
// http://www.umich.edu/~eecs381/handouts/formatting.pdf for digits
// add the calculation to a function

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <sstream> //for stringstream
#include <math.h> //for sqrt
#include <iomanip> //std::setprecision, std::setw for nice columns of numbers

float calculate_absolute_value(float x, float y);

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
	  float absolute_value = calculate_absolute_value(x,y);
	  if(outputfile.is_open())
	    {
	      outputfile << std::fixed<<std::setprecision(3)
			 << std::setw(5)<<"x"<<std::setw(6)<<x 
			 << std::setw(5)<<"y"<<std::setw(6)<<y 
			 << std::setw(20)<<"absolute_value"<<std::setw(6)<<absolute_value
			 <<std::endl;
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

float calculate_absolute_value(float x, float y)
{
  return sqrt(x*x+y*y);
}
