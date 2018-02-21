//
//  SFDateTime.hpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#ifndef SFDateTime_hpp
#define SFDateTime_hpp

#include <stdio.h>
#include <iostream>

#include "SFTime.hpp"
#include "SFTimezone.hpp"
#include "SFInterval.hpp"

class SFDateTime: public SFDate, public SFTime {
  
  SFDateTime(SFTimezone *aTimezone=nullptr); //init a new datetime based on GMT, unless a valid timezone is provided
  SFDateTime(const SFDateTime &aCopy); //copy construct
  SFDateTime(int aMonth, int aDay, int aYear, int anHour=0, int aMinutes=0, int aSeconds=0, SFTimezone *aTimezone=nullptr);
  SFDateTime(const char* aString, SFTimezone *aTimezone=nullptr); //parse the given string of the form "MM/DD/YYYY HH:MM:SS"
  
  SFDateTime(const SFDate &aDate, const SFTime &aTime, SFTimezone *aTimezone=nullptr);
  
  SFInterval operator-(const SFDateTime &other) const; //determine interval between two objects...
  
  SFTimezone&  getTimezone(); //retrieve timezone currently associated with this object
  SFDateTime&  setTimezone(SFTimezone &aTimezone); //change timezone
  
  //ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==
  
  operator const char*();   //Returns string of the form "MON DATE, YEAR HH:MM:SS TIMEZONE" Ex. Jan 4, 1961 09:15:00 PST
  operator SFDate();
  operator SFTime();
  operator SFTimezone();
  
  std::string toDateTimeString();   //Jan 4, 1961 09:15:00 PST (always this format)
  
  //... more members here as necessary...
private:
  /*
  int day;
  int month;
  int year;
  int hour;
  int min;
  int sec;
   */
  int zone_offset;
};

#endif /* SFDateTime_hpp */
