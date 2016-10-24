#ifndef __Output_h__
#define __Output_h__

//C++ libraries
#include <map>      //for std::map

//my libraries
#include "System.h"

//declarations of functions or classes 
//that are implmented in the .cxx of this folder

class Output {

public:
  //public methods
  Output();

  Output(const System& system, const std::string& extension, bool info, bool debug);

  //destructors
  ~Output();

  //other
  void Fill(const System& system);
  void Close(const System& system);
  
  //public members
  //none

private:
  //private methods
  //none

  //private members
  std::map<std::string, std::ofstream*> m_map_name_outfilepointer;
  std::map<std::string, std::string> m_map_name_outfilename;
  std::string m_extension;
  std::string m_separator;
  bool m_info;
  bool m_debug;

};//end class

#endif
