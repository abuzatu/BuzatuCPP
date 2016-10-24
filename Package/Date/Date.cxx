#include "Date.h"

//constructors
Date::Date()
{
}


Date::Date(const std::string& year, 
       const std::string& month,
       const std::string& day)
{
  str_year_=year;
  str_month_=month;
  str_day_=day;

  year_   = atoi(str_year_.c_str());
  month_  = atoi(str_month_.c_str());
  day_    = atoi(str_day_.c_str());

  //
  is_bisect_=(year_%4==0);
  //year lenght
  //
  length_year_=length_year(year_);
  //month length 
  map_months_[1]=31;//Jan 
  if(is_bisect_)//Feb
    {
      map_months_[2]=29;
    }
  else
    {
      map_months_[2]=28;
    }
  map_months_[3]=31;//Mar
  map_months_[4]=30;//Apr
  map_months_[5]=31;//May
  map_months_[6]=30;//June
  map_months_[7]=31;//Jul
  map_months_[8]=31;//Aug
  map_months_[9]=30;//Sep
  map_months_[10]=31;//Oct
  map_months_[11]=30;//Nov
  map_months_[12]=31;//Dec

  //asserts
  if(!(month_>0 && month_<13))
    {
      Print();
      assert(false);
    }
  if(!(day_>0 && day_<map_months_[month_]+1))
    {
      Print();
      assert(false);
    }
  

}

//destructor
Date::~Date()
{
}

//setters

//getters
unsigned Date::Year() const
{
  return year_;
}

unsigned Date::Month() const
{
  return month_;
}

unsigned Date::Day() const
{
  return day_;
}

std::string Date::StrYear() const
{
  return str_year_;
}

std::string Date::StrMonth() const
{
  return str_month_;
}

std::string Date::StrDay() const
{
  return str_day_;
}

bool Date::IsBisect() const
{
  return is_bisect_;
}

unsigned Date::length_year(unsigned year) const
{
  unsigned result=365;
  if(year%4==0)
    result = 366;

  return result;
}

int Date::Difference(const Date& date2, bool do_cout) const
{
  int result = 0;
  unsigned year1=year_;
  unsigned year2=date2.Year();
  Date date1(str_year_, str_month_, str_day_);

  if(year2==year1)
    {
      result += 
	(date2.DaysSinceStartYear(do_cout) - date1.DaysSinceStartYear(do_cout));
    }//end if(year2==year1)
  else if(year2>year1)
    {
      //add days until end of year1
      result += date1.DaysUntilEndYear(do_cout);
      //add days in the intermediate years
      for(unsigned iter_year=year1+1;iter_year!=year2;iter_year++)
	{
	  if(do_cout)
	    {
	      std::cout<<"iter_year="<<iter_year
		       <<" lenght="<<length_year(iter_year)<<std::endl;
	    }
	  result += length_year(iter_year);
	}
      //ad days since start of year2
      result += date2.DaysSinceStartYear(do_cout);
    }//end if(year2>year1)
  else //year2<year1
    {
     //add days until end of year2
      result += date2.DaysUntilEndYear(do_cout);
      //add days in the intermediate years
      for(unsigned iter_year=year2+1;iter_year!=year1;iter_year++)
	{
	  if(do_cout)
	    {
	      std::cout<<"iter_year="<<iter_year
		       <<" lenght="<<length_year(iter_year)<<std::endl;
	    }
	  result += length_year(iter_year);
	}
      //add days since start of year1
      result += date1.DaysSinceStartYear(do_cout);
      //now change sign to return the negative number
      result = -result;
    }//end if(year2<year1)
  //
  return result;
}

int Date::operator-(const Date& rhs) const
{
  return this->Difference(rhs,0);
}

unsigned Date::DaysUntilEndMonth(bool do_cout) const
{
  unsigned result = 0;
  unsigned day=day_;
  unsigned month=month_;
  unsigned lenght_month=map_months_.at(month);
  result = lenght_month - day;
  if(do_cout)
    {
      std::cout<<"current_day="<<day<<" current_month="<<month
	       <<" lenght_month="<<lenght_month
	       <<" days_until_end_month="<<result
	       <<std::endl;
    }
  return result;
}

unsigned Date::DaysSinceStartMonth(bool do_cout) const
{
  unsigned result = 0;
  unsigned day=day_;
  result = day;
  if(do_cout)
    {
      std::cout<<"current_day="<<day
	       <<" days_since_start_month="<<result
	       <<std::endl;
    }
  return result;
}

unsigned Date::DaysUntilEndYear(bool do_cout) const
{
  if(do_cout)
    {
      std::cout<<"current year="<<year_<<std::endl;
    }
  unsigned result = 0;
  result += this->DaysUntilEndMonth(do_cout);
  for(unsigned iter_month=month_+1; iter_month!=13; iter_month++)
    {
      if(do_cout)
	{
	  std::cout<<"iter_month="<<iter_month
		   <<" lenght="<<map_months_.at(iter_month)
		   <<std::endl;
	}//end if(do_cout)
      result += map_months_.at(iter_month); 
    }//end loop over months
  if(do_cout)
    {
      std::cout<<"days_until_end_year "<<year_<<"="<<result<<std::endl;
    }  
  return result;
}

unsigned Date::DaysSinceStartYear(bool do_cout) const
{
  if(do_cout)
    {
      std::cout<<"current year="<<year_<<std::endl;
    }
  unsigned result = 0;
  for(unsigned iter_month=1; iter_month!=month_; iter_month++)
    {
      if(do_cout)
	{
	  std::cout<<"iter_month="<<iter_month
		   <<" lenght="<<map_months_.at(iter_month)
		   <<std::endl;
	}//end if(do_cout)
      result += map_months_.at(iter_month); 
    }//end loop over months
  result += this->DaysSinceStartMonth(do_cout);
  if(do_cout)
    {
      std::cout<<"days_since_start_year "<<year_<<"="<<result<<std::endl;
    }
  return result;
}

void Date::Print() const
{
  std::cout<<"Year="<<year_<<" Month="<<month_<<" Day="<<day_<<std::endl;
}

std::string Date::Name() const
{
  std::string result;
  result=str_year_+"/"+str_month_+"/"+str_day_;
  return result;
}
