// run: g++ 1n.C -o 1n.exe && ./1n.exe 2
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
// add the command line arguments to run only on a few lines of code
// changes in int main() to make it use only the number of lines the user gives
// now we want to split the declarations in a header file

#include "./1n.h" //include the file where the others headers are included

//the templated functions must remain in the .C file, they can not be moved to the header unfortunately

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
void do_it (const std::string& name, unsigned number_of_steps) { //passing variable by reference
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
      unsigned current_number_of_steps=0;
      while ( getline (myfile,line) )
	{
	  current_number_of_steps++;//increase by 1
	  if (current_number_of_steps>number_of_steps)
	    {
	      continue; //meaning skip everything below and go to the next line
	    }
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
int main(int argc, char* argv[])
{
  //printing the arguments passed
  //note how the first argument is always the name of the file by default
  //so if you pass 2 arguments, argc is 3
  for(int i=0; i!=argc; i++)
    {
      std::cout<<"arg["<<i<<"]="<<argv[i]<<std::endl;
    }
  //unsigned number_steps=argv[1];//will not compile as what we get are 'char *', points to an array of type char; we need to convert to an int
  //to convert 
  int number_of_steps_as_int=atoi(argv[1]);
  //and now convert to unsigned; we choose unsigned as it is best practice, as the number of steps should not be negative
  unsigned number_of_steps=(unsigned) number_of_steps_as_int;
  //this could have been written in one line as
  //unsigned number_of_steps=(unsigned) atoi(argv[1]);


  do_it<int>("int",number_of_steps);
  do_it<float>("float",number_of_steps);
  return 0;
}
