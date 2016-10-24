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
// we will have now only one function instead of two, one for float, one for int


#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <sstream> //for stringstream
#include <math.h> //for sqrt
#include <iomanip> //std::setprecision, std::setw for nice columns of numbers

//these two are redunandant 
//and can be replaced by only one function that works on any type
//not just on these two
int calculate_absolute_value(int x, int y);
float calculate_absolute_value(float x, float y);
//this is the templated function that we replace with
template<typename T>
T calculate_absolute_value(T x, T y)
{
  return sqrt(x*x+y*y);
}


//these two are redunandant 
//and can be replaced by only one function that works on any type
//not just on these two
int calculate_absolute_value(int x, int y, int z);
float calculate_absolute_value(float x, float y, float z);
//this is the templated function that we replace with
template<typename T>
T calculate_absolute_value(T x, T y, T z)
{
  return sqrt(x*x+y*y+z*z);
}

//
void do_it_for_int ();
void do_it_for_float ();

//the main function
int main () {
  do_it_for_int();
  do_it_for_float();
  return 0;
}

//int
void do_it_for_int () {
  std::cout<<std::endl;
  std::cout<<"**** Start for int ****"<<std::endl;

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
	  int absolute_value_2D_templated = calculate_absolute_value<int>(x,y);
	  int absolute_value_3D_templated = calculate_absolute_value<int>(x,y,z);
	  std::cout<<"absolute_value_2D="<<absolute_value_2D
		   <<" absolute_value_2D_templated="<<absolute_value_2D_templated
		   <<std::endl;
	  std::cout<<"absolute_value_3D="<<absolute_value_3D
		   <<" absolute_value_3D_templated="<<absolute_value_3D_templated
		   <<std::endl;

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
  return;
}

//float
void do_it_for_float () {
  std::cout<<std::endl;
  std::cout<<"**** Start for float ****"<<std::endl;

  std::string inputfilename="input3D_float.txt";
  std::string outputfilename="output3D_float.txt";

  std::string line;
  std::ifstream myfile (inputfilename);
  float x;
  float y;
  float z;
  std::ofstream outputfile (outputfilename);
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  std::cout << line << std::endl;
	  std:: stringstream ss(line);
	  ss >> x >> y >> z;
	  float absolute_value_2D = calculate_absolute_value(x,y);
	  float absolute_value_3D = calculate_absolute_value(x,y,z);
	  float absolute_value_2D_templated = calculate_absolute_value<float>(x,y);
	  float absolute_value_3D_templated = calculate_absolute_value<float>(x,y,z);
	  std::cout<<"absolute_value_2D="<<absolute_value_2D
		   <<" absolute_value_2D_templated="<<absolute_value_2D_templated
		   <<std::endl;
	  std::cout<<"absolute_value_3D="<<absolute_value_3D
		   <<" absolute_value_3D_templated="<<absolute_value_3D_templated
		   <<std::endl;

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
  return;
}


//these also become redundant by having the templated functions
int calculate_absolute_value(int x, int y)
{
  return sqrt(x*x+y*y);
}


float calculate_absolute_value(float x, float y)
{
  return sqrt(x*x+y*y);
}

int calculate_absolute_value(int x, int y, int z)
{
  return sqrt(x*x+y*y+z*z);
}

float calculate_absolute_value(float x, float y, float z)
{
  return sqrt(x*x+y*y+z*z);
}
