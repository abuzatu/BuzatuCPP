#ifndef __Date_h__
#define __Date_h__

//C++ libraries
#include <iostream> //for cout, endl, clock_t
#include <stdlib.h> //for atof, atoi
#include <assert.h> //for assert
#include <string>
#include <map>

//my libraries

//declarations of functions or classes 
//that are implmented in the .cxx of this folder
class Date
{
public:
  //constructors  
  Date();

  Date(const std::string& year, 
       const std::string& month,
       const std::string& day);

  //destructor
  ~Date();

  //setters

  //getters
  unsigned Year() const;
  unsigned Month() const;
  unsigned Day() const;
  std::string StrYear() const;
  std::string StrMonth() const;
  std::string StrDay() const;
  bool IsBisect() const;

  //other
  //method that computes the number of days between two Dates
  int Difference(const Date& date2, bool do_cout) const;
  //operator - overloading to do the same as the function
  int operator-(const Date& rhs) const;
  unsigned DaysUntilEndMonth(bool do_cout) const;
  unsigned DaysSinceStartMonth(bool do_cout) const;
  unsigned DaysUntilEndYear(bool do_cout) const;
  unsigned DaysSinceStartYear(bool do_cout) const;
  void Print() const;
  std::string Name() const;

private:
  //members
  std::string str_year_;
  std::string str_month_;
  std::string str_day_;
  unsigned year_;
  unsigned month_;
  unsigned day_;
  bool is_bisect_;
  std::map<unsigned,unsigned> map_months_;

  unsigned length_year_;
  //methods
  unsigned length_year(unsigned year) const;

};

#endif
