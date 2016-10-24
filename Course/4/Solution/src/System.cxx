#include "System.h"

//constructors
System::System() {

}

System::System(const std::string& inputfilename, bool info, bool debug): m_info(info), m_debug(debug) {
  std::string line;
  std::ifstream myfile (inputfilename.c_str());
  std::string name;
  //the expectation is that all numbers are in SI units
  double mass;
  double x,y,z;
  double vx,vy,vz;
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      if(line=="") continue; //ignore empty lines, may appear at end of file
      if(m_debug) {
	std::cout << line << std::endl;
      }
      std:: stringstream ss(line);
      ss >> name >> mass >> x >> y >> z >> vx >> vy >> vz;
      if(m_debug) {
	std::cout 
	  << " name=" << name 
	  << " mass=" << mass 
	  << " x=" << x
	  << " y=" << y
	  << " z=" << z
	  << " vx=" << vx
	  << " vy=" << vy
	  << " vz=" << vz
	  << std::endl;
      }//end if m_debug
      if(m_debug) {
	Vector3D X(x,y,z);
	X.Print();
      }
      if(m_debug) {
	Body b(name,mass,Vector3D(x,y,z),Vector3D(vx,vy,vz));
	b.Print();
      }
      //what we actually use in just one line
      AddBody(Body(name,mass,Vector3D(x,y,z),Vector3D(vx,vy,vz)));
    }//end loop over lines in the file
    myfile.close();
  }//end if file is open 
  else {
    std::cout << "Unable to open input file called "<<inputfilename<<" Will ABORT!!!"<<std::endl; 
    assert(false);
  }//end if file is not open

  if(m_debug) {
    Print();
    std::cout<<"run"<<std::endl;
  }

  if(m_info) {
    std::cout<<"The system has the following bodies:"<<std::endl;
    for(unsigned i=0; i!=m_vec_body.size(); i++) {
      std::cout<<m_vec_body.at(i).GetName()<<std::endl;
    }
  }

}

//destructor
System::~System() {

}

//setters

void System::AddBody(const Body& body) {
  m_vec_body.push_back(body);
}

//getters

std::vector<Body> System::GetVecBody() const {
  return m_vec_body;
}

//others
void System::Print() {
  std::cout<<"Start print system"<<std::endl;
  for (unsigned i=0; i!=m_vec_body.size(); i++) {
    m_vec_body.at(i).Print();
  }
  std::cout<<"End   print system"<<std::endl;
}

void System::Evolve(double dt) {
  //we create a copy of the current system
  //but independent of our system,
  //used to compute the accelerations using the copy 
  //then let our system to evolve
  const System previous=*this;
  //loop over every planet
  for(unsigned i=0; i!=previous.GetVecBody().size(); i++) {
    //for this planet I want to compute the total acceleration
    Body bi=previous.GetVecBody().at(i);
    Vector3D Ai;//the acceleration on the body i; initialized at (0.0, 0.0, 0.0) by default
    //for this I need the acceleration from each planet
    //for this I loop over all the planets again and I skip myself
    //calculate the acceleration of body j on body i as Vector3D Aji, and add it to Ai
    for(unsigned j=0; j!=previous.GetVecBody().size(); j++) {
      //skipping the partner planet if that is the same as the planet I want to calculate acceleratioon for
      if(j==i) continue; 
      Body bj=previous.GetVecBody().at(j);
      //calculate the distance between the two planets
      //it is the module of the Vector3D that is the difference between the Vector3D of the two planets
      Vector3D Xji=bj.GetX()-bi.GetX();
      double Rji=Xji.GetModule();
      //Newton's gravitational constant
      double G=6.674e-11;
      //mass of bj
      double mj=bj.GetMass();
      //calculate the absolute value of the acceleration given by the body j on the body i
      double aji=G*mj/(Rji*Rji);
      //calculate the x, y, z componenets of the acceleration aji
      //ax = aji * (xj-xi) / Rji
      //xj-xi = Xji.GetX();
      //same for ay and az
      //we need the Vector3D Aji;
      //Vector3D Aji(aji * (xj-xi) / Rji, aji * (yj-yi) / Rji, aji * (zj-zi) / Rji);
      //we notice how a and Rji are scalers that can be moved out
      //and the remaining Vector3D is exactly Xji.
      Vector3D Aji=Xji*(aji/Rji);
      //add the current acceleration to the total one for boy i
      Ai+=Aji;
    }//end loop over the other planets
    //now we have the acceleration on body i, so we can evolve the body
    //but crucially, not the body from previous, but from the current one
    m_vec_body.at(i).Evolve(dt,Ai);
  }//end loop over every body
  //now the entire system has evolved
  //when we exit this scope, the object previous will be deleted
}
