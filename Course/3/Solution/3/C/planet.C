#include "planet.h"

//constructors
Planet::Planet() {

}

Planet::Planet(const std::string& name, double mass, double distance):
  m_name(name),m_mass(mass),m_distance(distance) {    
}

//destructor
Planet::~Planet() {

}

//setters

void Planet::SetName(const std::string& name) {
  m_name=name;
}

void Planet::SetMass(double mass) {
  m_mass=mass;
}

void Planet::SetDistance(double distance) {
  m_distance=distance;
}

//getters

std::string Planet::GetName() const {
  return m_name;
}

double Planet::GetMass() const {
  return m_mass;
}

double Planet::GetDistance() const {
  return m_distance;
}

//others
void Planet::Print() {
    std::cout<<std::setw(6)<<"Name"<<std::setw(12)<<m_name<<std::setw(10)<<"Mass"<<std::setw(15)<<m_mass<<std::setw(20)<<"DistanceToSun"<<std::setw(10)<<m_distance<<std::endl;
}


//these do not belong to do the class, so no need of Planet::

bool compare_by_name(const Planet& left, const Planet& right) {
  return left.GetName()<right.GetName();
}

bool compare_by_mass(const Planet& left, const Planet& right) {
  return left.GetMass()<right.GetMass();
}

bool compare_by_distance(const Planet& left, const Planet& right) {
  return left.GetDistance()<right.GetDistance();
}
