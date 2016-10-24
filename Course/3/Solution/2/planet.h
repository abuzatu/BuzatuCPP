#include <iostream> //for cout, endl
#include <iomanip> //for std::setw

class Planet {

public:
  //public methods
  Planet();

  //now we need a constructor that takes as arguments the three values
  //we use the method described above, which is faster
  Planet(const std::string& name, double mass, double distance);   

  //destructors
    ~Planet();
      
  //setters
  void SetName(const std::string& name);
  void SetMass(double mass);
  void SetDistance(double distance);

  //getters
  std::string GetName() const;
  double GetMass() const;
  double GetDistance() const;

  //others
  void Print();

  //public members
  //none

private:
  //private methods
  //none

  //private members
  std::string m_name;
  double m_mass;
  double m_distance;

};//end class

bool compare_by_name(const Planet& left, const Planet& right);
bool compare_by_mass(const Planet& left, const Planet& right);
bool compare_by_distance(const Planet& left, const Planet& right);
