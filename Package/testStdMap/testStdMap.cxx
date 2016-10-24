#include "testStdMap.h"

int main()
{
  //let's create a map between string and double and then loop through it
  //declare
  std::map<std::string,double> m;
  //add values
  m["option1"]=3.4;
  m["option2"]=4.5;
  m["option3"]=7.8;
  //to loop over the entries we can't use the usual for loop for vectors
  //but we can use the iterator way also used for vectors
  //this mode works in fact for all the STL containers
  std::map<std::string,double>::iterator iter;
  for(iter=m.begin(); iter!=m.end(); iter++)
    {
      //notice how iter is an iterator, that's why we use iter->
      //we access the first element of the map (key) by iter->first
      //and the second element of the map (value) by iter->second
      std::cout<<"current_first="<<iter->first
	       <<" current_second="<<iter->second
	       <<std::endl;
    }

  return 0;
}
