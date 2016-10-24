#ifndef TemplatedClassStreamer_h
#define TemplatedClassStreamer_h

//C++ libraries
#include <iostream>

//ROOT libraries

//my libraries

//declarations of functions or classes 
//that are implmented in the .cxx of this folder
//read more: http://stackoverflow.com/questions/1297609/overloading-friend-operator-for-template-class
template <class T, class U> class Pair
{ 
 public:
  //the constructor, destructor and = operator are both declared here
  //and defined here, but they can be also defined outside the class
  //declaration, as in the example TemplatedClass
  //this is an example how they can also be defined inside the class
  //declaration
 Pair(T t, U u) : t_(t), u_(u){}
  ~Pair(){}
  Pair& operator=(const Pair&);
  //the << operator HAS TO be both declared and implemented in the class header
  //otherwise it will not work with a shared library
  friend std::ostream& operator<<(std::ostream& out, Pair<T,U>& pair)
  {
    out<<pair.t_ << " " << pair.u_;
    return out;
  }
  
 private:    
  T t_;
  U u_;
};

#endif 
