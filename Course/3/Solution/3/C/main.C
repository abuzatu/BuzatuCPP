#include "main.h"

//the main method
int main () {
  bool debug=false;
  std::string line;
  std::ifstream myfile ("./input/input.txt");
  std::string name;
  double mass;
  double distance;
  std::vector<Planet> vec_planet;
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      if(line=="") continue; //ignore empty lines, may appear at end of file
      if(debug) {
	std::cout << line << std::endl;
      }
      std:: stringstream ss(line);
      ss >> name >> mass >> distance;
      if(debug) {
	std::cout 
	  << " name=" << name 
	  << " mass=" << mass 
	  << " distance=" << distance
	  << std::endl;
      }//end if debug
      vec_planet.push_back(Planet(name,mass,distance));
    }//end loop over lines in the file
    myfile.close();
  }//end if file is open 
  else {
    std::cout << "Unable to open file"; 
  }//end if file is not open

  //loop over all the planets and print them
  for(unsigned i=0; i!=vec_planet.size(); i++) {
    vec_planet.at(i).Print();
    //vec_planet.at(i) returns the object of type Planet at index i
    //we can act on this object with any public method by putting a dot (.)
  }

  std::cout<<" "<<std::endl;
  //let's test the other methods we can play with
  //let's get the first planet
  Planet planet=vec_planet.at(0);
  planet.Print();
  //use getter methods
  std::cout<<std::setw(6)<<"Name"<<planet.GetName()<<" Mass="<<planet.GetMass()<<std::endl;
  //let's change its properties
  planet.SetName("Vulcan");
  planet.SetMass(7e+49);
  planet.SetDistance(342.3);
  std::cout<<"After changing its member values, we print it again"<<std::endl;
  planet.Print();

  std::cout<<" "<<std::endl;
  //let's sort the planets by the name
  std::sort(vec_planet.begin(),vec_planet.end(), compare_by_name);
  //let's print the content
  std::cout<<"After sorting by name, let's print the planets in that order of name"<<std::endl;
  //loop over all the planets and print them
  for(unsigned i=0; i!=vec_planet.size(); i++) {
    vec_planet.at(i).Print();
  }

  std::cout<<" "<<std::endl;
  //let's sort the planets by the mass
  std::sort(vec_planet.begin(),vec_planet.end(), compare_by_mass);
  //let's print the content
  std::cout<<"After sorting by mass, let's print the planets in that order of name"<<std::endl;
  //loop over all the planets and print them
  for(unsigned i=0; i!=vec_planet.size(); i++) {
    vec_planet.at(i).Print();
  }

  std::cout<<" "<<std::endl;
  //let's sort the planets by the distance
  std::sort(vec_planet.begin(),vec_planet.end(), compare_by_distance);
  //let's print the content
  std::cout<<"After sorting by distance, let's print the planets in that order of distance"<<std::endl;
  //loop over all the planets and print them
  for(unsigned i=0; i!=vec_planet.size(); i++) {
    vec_planet.at(i).Print();
  }

  return 0;
}//end if main
