#ifndef __System_h__
#define __System_h__

//C++ libraries
#include <vector>   //for std::vector
#include <sstream>  //for std::stringstream
#include <fstream>  //to read the file
#include <string>   // for std::string
#include <iostream> //for std::cout, std::endl
#include <assert.h> //for assert
#include <map>      //for std::map

//my libraries
#include "Body.h"

//declarations of functions or classes 
//that are implmented in the .cxx of this folder

class System {

public:
  //public methods
  System();
  System(const std::string& inputfilename, bool info, bool debug);

  //destructors
  ~System();
  
  //setters
  void AddBody(const Body& body);

  //getters
  std::vector<Body> GetVecBody() const;

  //others
  void Print();
  void Evolve(double dt);//dt - time interval

  //public members
  //none

private:
  //private methods
  //none

  //private members
  std::vector<Body> m_vec_body;
  bool m_info;
  bool m_debug;

};//end class

#endif
