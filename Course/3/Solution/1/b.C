// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// we create a class Planet in the same .C file, without using it so far

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <sstream> //for stringstream
#include <math.h> //for sqrt

class Planet {

public:
  //public methods

  //constructors
  Planet();
  Planet(const std::string& name, double mass, double distance):
    m_name(name),m_mass(mass),m_distance(distance) {    
  }

  //destructors
  ~Planet();

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
