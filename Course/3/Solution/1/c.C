// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// we create a class Planet in the same .C file, and use it for testing

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <vector>
#include <sstream> //for stringstream
#include <math.h> //for sqrt

class Planet;

class Planet {

public:
  //public methods

  //constructors
  //Planet()
  //{
  //  m_name="";
  //  m_mass=0.0;
  //  m_distance=0.0;
  //};
  //the code from above is faster if written this way
  //Planet():
  //  m_name(""),m_mass(0.0),m_distance(0.0) {
  //}
  //in fact, since C++ already initializes strings to empty strings 
  //and doubles to zero, even this one is not needed
  //so the one below is enough
  Planet(){}

  //now we need a constructor that takes as arguments the three values
  //we use the method described above, which is faster
  Planet(const std::string& name, double mass, double distance):
    m_name(name),m_mass(mass),m_distance(distance) {    
  }

  //destructors
  ~Planet(){}

  //setters
  void SetName(const std::string& name) {m_name=name;}
  void SetMass(double mass) {m_mass=mass;}
  void SetDistance(double distance) {m_distance=distance;}

  //getters
  //notice const on the right, meaning it enforces that
  //this method will not change the object, so if by mistake we change it
  //inside the method, the compile will complain
  std::string GetName() const {return m_name;}
  double GetMass() const {return m_mass;}
  double GetDistance() const {return m_distance;}

  //others
  void Print(){
    std::cout<<"Name="<<m_name<<" Mass="<<m_mass<<" DistanceToSun="<<m_distance<<std::endl;
  }

  //public members
  //none

private:
  //private methods
  //none

  //private members
  std::string m_name;
  double m_mass;
  double m_distance;

};

//the main method
int main () {
  bool debug=false;
  std::string line;
  std::ifstream myfile ("input.txt");
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
  std::cout<<"Name="<<planet.GetName()<<" Mass="<<planet.GetMass()<<std::endl;
  //let's change its properties
  planet.SetName("Vulcan");
  planet.SetMass(7e+49);
  planet.SetDistance(342.3);
  std::cout<<"After changing its member values, we print it again"<<std::endl;
  planet.Print();
  

  return 0;
}//end if main
