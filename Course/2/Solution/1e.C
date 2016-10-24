// reading a text file line by line and printing the entire line
// breaking up the line into elements of certain types
// to do that we convert the string called line into a stringstream
// and from it we get the variable of the right type, float in our case
// now compute the absolute value
// 4. Compute the weighted average distance to the Sun of all the planets, defined as sum over the planets of mass times distance, and all divided by the sum of the masses of all planets (\frac{\Sum mi*di}{\Sum mi}). 
// Solution: we can compute ourselves, or use other algorithms to help us

#include <iostream> //for cout, endl
#include <fstream> //to read the file
#include <string>
#include <vector>
#include <map>
#include <sstream> //for stringstream
#include <math.h> //for sqrt
#include <algorithm> //for sort for vector
#include <numeric> //for accumulate for vector

int main () {
  bool debug=true;
  std::string line;
  std::ifstream myfile ("input.txt");
  std::string name;
  double mass;
  double distance;
  std::vector<std::string> vec_name;
  std::vector<double> vec_mass;
  std::vector<double> vec_distance;
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
      vec_name.push_back(name);
      vec_mass.push_back(mass);
      vec_distance.push_back(distance);
    }//end loop over lines in the file
    myfile.close();
  }//end if file is open 
  else {
    std::cout << "Unable to open file"; 
  }//end if file is not open
  //print the names in the order in the file

  for(unsigned i=0; i!=vec_name.size(); ++i) {
    std::cout<<"name="<<vec_name.at(i)<<" mass="<<vec_mass.at(i)<<" distance="<<vec_distance.at(i)<<std::endl;
  }

  //calculate the sum of the masses
  //for this we use std::accumulate
  //http://en.cppreference.com/w/cpp/algorithm/accumulate
  //use 0.0 because we have double, if it were int we would have used 0
  double mass_sum=std::accumulate(vec_mass.begin(),vec_mass.end(),0.0);
  std::cout<<"mass_sum="<<mass_sum<<std::endl;

  //multiply each element from the vector of masses with 1/mass_sum
  //to obtain a vector of the weights for the distance
  //for this we use std::transform
  //http://stackoverflow.com/questions/3885095/multiply-vector-elements-by-a-scalar-value-using-stl
  std::vector<double> vec_massweight=vec_mass;
  std::transform(vec_massweight.begin(), vec_massweight.end(), vec_massweight.begin(),
               std::bind1st(std::multiplies<double>(),1/mass_sum));

  for(unsigned i=0; i!=vec_name.size(); ++i) {
    std::cout<<"name="<<vec_name.at(i)<<" mass="<<vec_mass.at(i)<<" massweight="<<vec_massweight.at(i)<<" distance="<<vec_distance.at(i)<<std::endl;
  }

  //do the scalar product of the vectors of distance and weightmass to obtain the mass-weighted-average of the distance betwween the planets and the sun
  double mass_weighted_average_distance=
    std::inner_product(vec_distance.begin(), vec_distance.end(), vec_massweight.begin(), 0.0);
  std::cout<<" "<<std::endl;
  std::cout<<"mass_weighted_average_distance="<<mass_weighted_average_distance<<std::endl;

  return 0;
}//end if main
