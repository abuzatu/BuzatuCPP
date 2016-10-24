#include "Output.h"

//constructors
Output::Output() {

}

Output::Output(const System& system, const std::string& extension, bool info, bool debug)
  : m_extension(extension), m_info(info), m_debug(debug) {
  if(m_extension=="csv") m_separator=",";
  else if(m_extension=="txt") m_separator=" ";
  else {
    std::cout<<"m_extension "<<m_extension<<" not known. Choose csv or txt. Will ABORT!!!"<<std::endl;
    assert(false);
  }
			   
  for(unsigned i=0; i!=system.GetVecBody().size(); i++) {
    const std::string Name=system.GetVecBody().at(i).GetName();
    const std::string outfilename="./output/"+Name+"."+m_extension;
    m_map_name_outfilename[Name]=outfilename;
    m_map_name_outfilepointer[Name]=new std::ofstream(outfilename.c_str());
    if(m_info) {
      std::cout<<"Created output file for body "<<Name<<" at location "<<outfilename<<std::endl;
    }
  }
}

//destructor
Output::~Output() {

}

//other
void Output::Fill(const System& system) {
  if(m_debug) {
    std::cout<<"Nr planets "<<system.GetVecBody().size()<<std::endl;
  }
  for(unsigned i=0; i!=system.GetVecBody().size(); i++) {
    const std::string Name=system.GetVecBody().at(i).GetName();
    std::stringstream ss;
    ss<< system.GetVecBody().at(i).GetX().GetX()
      << m_separator
      << system.GetVecBody().at(i).GetX().GetY()
      //<< m_separator
      //<< system.GetVecBody().at(i).GetX().GetZ();
      << std::endl;    
    std::string line=ss.str();
    if(m_debug) std::cout<<Name<<" "<<line;
    *(m_map_name_outfilepointer[Name])<<line;
  }
}

void Output::Close(const System& system) {
  for(unsigned i=0; i!=system.GetVecBody().size(); i++) {
    const std::string Name=system.GetVecBody().at(i).GetName();
    m_map_name_outfilepointer[Name]->close();
    if(m_info || m_debug) {
      std::cout<<"Closed output file for body "<<Name<<" at location "<<m_map_name_outfilename[Name]<<std::endl;
    }
  }
}
