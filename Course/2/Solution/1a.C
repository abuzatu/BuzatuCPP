// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// now compute the absolute value

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <sstream> //for stringstream
#include <math.h> //for sqrt

int main () {
  bool debug=true;
  std::string line;
  std::ifstream myfile ("input.txt");
  std::string name;
  double mass;
  double distance;
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      if(line=="") continue; //ignore empty lines, may appear at end of file
      std::cout << line << std::endl;
      std:: stringstream ss(line);
      ss >> name >> mass >> distance;
      if(debug) {
	std::cout 
	  << " name=" << name 
	  << " mass=" << mass 
	  << " distance=" << distance
	  << std::endl;
      }//end if debug
    }//end loop over lines in the file
    myfile.close();
  }//end if file is open 
  else {
    std::cout << "Unable to open file"; 
  }//end if file is not open
  return 0;
}//end if main
