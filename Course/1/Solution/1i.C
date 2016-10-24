// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// now compute the absolute value
// write to the output file
// write exactly two digits all the time
// http://www.umich.edu/~eecs381/handouts/formatting.pdf for digits
// add the calculation to a function
// add 2D and 3D functions, hence function overloading
// replacing all the float with int to do the same exercise for int
// we don't want two sets of code, but one that works in all cases,
// hence function templating


#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <sstream> //for stringstream
#include <math.h> //for sqrt
#include <iomanip> //std::setprecision, std::setw for nice columns of numbers

int calculate_absolute_value(int x, int y);
int calculate_absolute_value(int x, int y, int z);

int main () {
  std::string inputfilename="input3D_int.txt";
  std::string outputfilename="output3D_int.txt";

  std::string line;
  std::ifstream myfile (inputfilename.c_str());
  int x;
  int y;
  int z;
  std::ofstream outputfile (outputfilename.c_str());
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  std::cout << line << std::endl;
	  std:: stringstream ss(line);
	  ss >> x >> y >> z;
	  int absolute_value_2D = calculate_absolute_value(x,y);
	  int absolute_value_3D = calculate_absolute_value(x,y,z);
	  if(outputfile.is_open())
	    {
	      outputfile << std::fixed<<std::setprecision(3)
			 << std::setw(5)<<"x"<<std::setw(6)<<x 
			 << std::setw(5)<<"y"<<std::setw(6)<<y 
			 << std::setw(5)<<"z"<<std::setw(6)<<z
			 << std::setw(20)<<"absolute_value_2D"<<std::setw(6)<<absolute_value_2D
			 << std::setw(20)<<"absolute_value_3D"<<std::setw(6)<<absolute_value_3D

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

int calculate_absolute_value(int x, int y)
{
  return sqrt(x*x+y*y);
}

int calculate_absolute_value(int x, int y, int z)
{
  return sqrt(x*x+y*y+z*z);
}

