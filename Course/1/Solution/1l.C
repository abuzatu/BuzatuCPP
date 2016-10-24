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
// now we remove the redundant functions and we keep only the templated ones
// we can go furthe and notice that we have two large functions
// one do_it_for_int, one do_it_for_float
// these can also be templated, so that we have only one function
// so that if we change something in one function, we change in both two
// we will copy one of the functions above the int main() and will replace int by T
// while having template<typname> T above; then we can easily call it twice
// we can also pass a string "int" or "float" to choose the appropriate input file
// that is all

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <sstream> //for stringstream
#include <math.h> //for sqrt
#include <iomanip> //std::setprecision, std::setw for nice columns of numbers

template<typename T>
T calculate_absolute_value(T x, T y)
{
  return sqrt(x*x+y*y);
}

template<typename T>
T calculate_absolute_value(T x, T y, T z)
{
  return sqrt(x*x+y*y+z*z);
}

template<typename T>
void do_it (const std::string& name) { //passing variable by reference
  std::cout<<std::endl;
  std::cout<<"**** Start for "<<name<<" ****"<<std::endl;

  std::string inputfilename="input3D_"+name+".txt"; //string concatenation
  std::string outputfilename="output3D_"+name+".txt";  //string concatenation

  std::string line;
  std::ifstream myfile (inputfilename.c_str());
  T x; //notice T instead of int before, here and in other places
  T y; //notice T instead of int before, here and in other places
  T z; //notice T instead of int before, here and in other places
  std::ofstream outputfile (outputfilename.c_str());
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  std::cout << line << std::endl;
	  std:: stringstream ss(line);
	  ss >> x >> y >> z;
	  T absolute_value_2D = calculate_absolute_value<T>(x,y); //notice T instead of int before, here and in other places
	  T absolute_value_3D = calculate_absolute_value<T>(x,y,z); //notice T instead of int before, here and in other places

	  if(outputfile.is_open())
	    {
	      outputfile << std::fixed<<std::setprecision(2)
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

//the main function
int main () {
  do_it<int>("int");
  do_it<float>("float");
  return 0;
}
