//
//  SFTime.hpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#ifndef SFTime_hpp
#define SFTime_hpp

#include <stdio.h>
#include <iostream>

#include "SFInterval.hpp"

class SFDateTime;

class SFTime {
public:
  SFTime();                             //default to now(HH:MM:SS)
  SFTime(const char *aTimeString);      //must parse the given string of the form "HH:MM:SS"
  SFTime(int anHour, int aMinutes, int aSeconds); //build time from individual parts
  SFTime(const SFTime &aCopy);
  SFTime(const SFDateTime &aCopy);
  
  SFTime& adjustByMinutes(int n); //-- to +/- N minutes from the given time
  SFTime& adjustByHours(int n); //-- to +/- N hours from the given time. 11:15pm + 2hours is 1:15a (rolls over)
  
  SFInterval operator-(const SFTime &other) const; //determine interval between two times...
  SFInterval operator-(const SFDateTime &other) const; //determine interval between two objects...
  
  int   getHour();
  int   getMinutes();
  int   getSeconds();
  
  SFTime& startOfDay(); //change time to (00:00:00)
  SFTime& endOfDay();   //change time to (23:59:59)
  
  std::string toTimeString();  //Returns string of the form HH:MM:SS
  bool operator >(SFTime & other) const;
  bool operator ==(SFTime & other) const;
  bool operator !=(SFTime & other) const;
  bool operator <(SFTime & other) const;
  bool operator >=(SFTime & other) const;
  bool operator <=(SFTime & other) const;
  
  //ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==
  
  //... more members here as necessary...
protected:
  int hour = 0;
  int min = 0;
  int sec = 0;
};

#endif /* SFTime_hpp */
