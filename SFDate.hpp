//
//  SFDate.hpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#ifndef SFDate_hpp
#define SFDate_hpp

#include <iostream>
#include <stdio.h>

#include "SFInterval.hpp"

class SFDateTime;
//class SFInterval;

class SFDate {
public:
  SFDate();                             //default to today, in GMT timezone
  SFDate(const char *aDateTimeString);  //must parse the given string of the form MM/DD/YYYY
  SFDate(int month, int day, int year); //build date from individual parts
  SFDate(const SFDate &aCopy);
  SFDate(const SFDateTime &aCopy);
  
  bool operator ++(); //advance by one day
  bool operator --(); //back up by one day...
  
  SFInterval operator-(const SFDate &other) const; //determine interval between two dates...
  SFInterval operator-(const SFDateTime &other) const; //determine interval between two objects...
  
  SFDate& adjustByDays(int n); //-- to add or subtract N days from the given date
  SFDate& adjustByWeeks(int n); //-- to add or subtract N weeks from the given date
  SFDate& adjustByMonths(int n); //-- to add or subtract N months from the given date
  SFDate& adjustByYears(int n); //-- to add or subtract N years from the given date
  
  SFDate& setDay(int aDay);      //set the current day of the given date object; aDay must be in valid range
  SFDate& setMonth(int aMonth);  //set the current month of the given date object aMonth must be in valid range
  SFDate& setYear(int aYear);    //set the current year; must be in valid range
  
  int   getDay() const;    //if date is 12/15/2018, the day is the 15th
  int   getMonth() const;  //if date is 12/15/2018, the month is 12 (dec)
  int   getYear() const;   //if date is 12/15/2018, the year is 2018
  
  int   getWeekOfYear() const; //if date is 01/10/2018, the week of year is 2 (range is 1..52)
  int   getDayOfYear() const;  //if date is 01/04/1961, the day of year is 4 (range is 1..365)
  int   getDayOfweek() const;  //range (0..6 -- 0==sunday)
  int   daysInMonth() const;   //based on month/year, return # of days in the month
  
  SFDate& startOfMonth(); //if date is 12/15/2018, return 12/01/2018
  SFDate& endOfMonth();   //if date is 12/15/2018, return 12/31/2018
  
  SFDate& startOfYear();  //if date is 12/15/2018, return 01/01/2018
  SFDate& endOfYear();    //if date is 12/15/2018, return 12/31/2018
  
  std::string toDateString();  //Return a string of the form MM/DD/YYYY
  std::string toEnglishDateString();
  //ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==
  bool operator >(SFDate & other) const;
  bool operator ==(SFDate & other) const;
  bool operator <(SFDate & other) const;
  //... other members here as necessary...
protected:
  int day;
  int month;
  int year;
  //int index; //
  int daysInMonth(int month_number) const;
  std::string month_to_abrev(int m);
  bool ahead(const SFDate & other) const;
};

#endif /* SFDate_hpp */
