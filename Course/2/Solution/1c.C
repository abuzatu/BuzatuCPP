// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// now compute the absolute value
// 2. Print on each line the name of the planet followed by its mass, in order of the mass.
// Solution. Since when filling a map of two items, the first is the key and the second is the value, they are already ordered by the key. If the key is a string, then they are ordered alphabetically. If the key is a number, they are ordered by value. 

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <vector>
#include <map>
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
  std::map<std::string,double> map_name_mass;//new
  std::map<double,std::string> map_mass_name;//new
  std::map<double,std::string> map_distance_name;//new
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
      map_name_mass[name]=mass;//new
      map_mass_name[mass]=name;//new
      map_distance_name[distance]=name;//new
    }//end loop over lines in the file
    myfile.close();
  }//end if file is open 
  else {
    std::cout << "Unable to open file"; 
  }//end if file is not open
  //print the names in the order in the file

  std::cout<<" "<<std::endl;
  std::cout<<"Printing the map_name_mass in the order they are read, meaning already in alphabetical order of the planets"<<std::endl;
  std::map<std::string,double>::iterator iter_string_double;
  for(iter_string_double=map_name_mass.begin(); iter_string_double!=map_name_mass.end(); ++iter_string_double) {
    std::cout<<iter_string_double->first<<" "<<iter_string_double->second<<std::endl;
  }

  std::cout<<" "<<std::endl;
  std::cout<<"Printing the map_mass_name in the order they are read, meaning already in the order of the mass of the planets"<<std::endl;
  std::map<double,std::string>::iterator iter_double_string;
  for(iter_double_string=map_mass_name.begin(); iter_double_string!=map_mass_name.end(); ++iter_double_string) {
    std::cout<<iter_double_string->first<<" "<<iter_double_string->second<<std::endl;
  }

  std::cout<<" "<<std::endl;
  std::cout<<"Printing the map_distance_name in the order they are read, meaning already in the order of the distance of the planets"<<std::endl;
  //std::map<double,std::string>::iterator iter_double_string;
  for(iter_double_string=map_distance_name.begin(); iter_double_string!=map_distance_name.end(); ++iter_double_string) {
    std::cout<<iter_double_string->first<<" "<<iter_double_string->second<<std::endl;
  }

  return 0;
}//end if main
