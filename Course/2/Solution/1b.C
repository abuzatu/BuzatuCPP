// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// now compute the absolute value
// 1. Print on each line the name of the planets, in alphabetical order.
// Solution: fill the names in a vector
// then use the sort algorithm on the vector. 

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <vector>
#include <sstream> //for stringstream
#include <math.h> //for sqrt
#include <algorithm> //for sort for vector

int main () {
  bool debug=true;
  std::string line;
  std::ifstream myfile ("input.txt");
  std::string name;
  double mass;
  double distance;
  std::vector<std::string> vec_name;//new
  std::cout<<"Reading in the file"<<std::endl;
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
      vec_name.push_back(name);//new
    }//end loop over lines in the file
    myfile.close();
  }//end if file is open 
  else {
    std::cout << "Unable to open file"; 
  }//end if file is not open
  //print the names in the order in the file

  std::cout<<" "<<std::endl;
  std::cout<<"Printing the names in the order they are read"<<std::endl;
  for(unsigned i=0; i!=vec_name.size(); ++i) {
    std::cout<<"name="<<vec_name.at(i)<<std::endl;
  }

  //now sort the vector, and for strings it means alphabetical order
  std::sort(vec_name.begin(),vec_name.end());

  std::cout<<" "<<std::endl;
  std::cout<<"Printing the names in alphabetical order"<<std::endl;
  for(unsigned i=0; i!=vec_name.size(); ++i) {
    std::cout<<"name="<<vec_name.at(i)<<std::endl;
  }

  return 0;
}//end if main
