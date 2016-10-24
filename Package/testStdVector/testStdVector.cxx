#include "testStdVector.h"

int main()
{
  //fill a vector with three integers, then loop over them and print them
  //define the vector of int
  //note <  > the sign of templating
  //the fector can store anything inside and then we can loop over the elements
  //in the same way, irrespective of what the vector holds
  std::vector<int> v_int;
  v_int.push_back(1);
  v_int.push_back(9);
  v_int.push_back(7);
  //push_back adds the element after the last element
  //for a vector the order matters and an element can be there twice
  //let's loop over the vectors
  //std::vector is a class and it has methods called algorithms
  //.size() tells us the number of elements in the list
  std::cout<<"v_int has "<<v_int.size()<<" elements."<<std::endl;
  std::cout<<"The vector with int:"<<std::endl;
  //let's loop over the elements of the vector
  for (unsigned iter=0; iter!=v_int.size(); iter++)
    {
      int current=v_int[iter];
      //[iter] is something inherited from C arrays
      int also_current=v_int.at(iter);
      //iter is another method that is generic for other STL containers too
      std::cout<<"current="<<current<<" also_current="<<also_current<<std::endl;
    }
  //end loop over the elements in the vector

  //now we can do the same for a vector of double
  //and as you see, it all works the same as for int
  std::vector<double> v_double;
  v_double.push_back(1.0);
  v_double.push_back(9.0);
  v_double.push_back(7.0);  
  std::cout<<"The vector with doubles:"<<std::endl;
  for(unsigned iter=0; iter!=v_double.size(); iter++)
    {
      std::cout<<"current="<<v_double.at(iter)<<std::endl;
    }

  //we can do the same for an std::string
  //and as you see, it all works the same as for int
  std::vector<std::string> v_string;
  v_string.push_back("house");
  v_string.push_back("dog");
  v_string.push_back("tree");  
  std::cout<<"The vector with strings:"<<std::endl;
  for(unsigned iter=0; iter!=v_string.size(); iter++)
    {
      std::cout<<"current="<<v_string.at(iter)<<std::endl;
    }

  //but we can also loop in a new way, using iterators
  //iterators are pointers to each element in the vector
  std::vector<int>::iterator iter_int;
  std::cout<<"The vector with int with iterators:"<<std::endl;
  for(iter_int=v_int.begin(); iter_int!=v_int.end(); iter_int++)
    {
      //iter is a pointer to the element, thus *iter is the value
      std::cout<<"current="<<*iter_int<<std::endl;
    }

  //but we can also loop in a new way, using iterators
  //iterators are pointers to each element in the vector
  std::vector<double>::iterator iter_double;
  std::cout<<"The vector with double with iterators:"<<std::endl;
  for(iter_double=v_double.begin(); iter_double!=v_double.end(); iter_double++)
    {
      //iter is a pointer to the element, thus *iter is the value
      std::cout<<"current="<<*iter_double<<std::endl;
    }

  //but we can also loop in a new way, using iterators
  //iterators are pointers to each element in the vector
  std::vector<std::string>::iterator iter_string;
  std::cout<<"The vector with string with iterators:"<<std::endl;
  for(iter_string=v_string.begin(); iter_string!=v_string.end(); iter_string++)
    {
      //iter is a pointer to the element, thus *iter is the value
      std::cout<<"current="<<*iter_string<<std::endl;
    }

  return 0;
}
