//
//  SFDate.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include "SFDate.hpp"
#include <time.h>
#include <math.h>

SFDate::SFDate(){
  time_t rawtime;
  struct tm * ptm;
  time ( &rawtime );
  ptm = gmtime ( &rawtime );
  day = ptm->tm_mday;
  month = ptm->tm_mon+1;
  year = ptm->tm_year+1900;
}


//must parse the given string of the form MM/DD/YYYY, "02/15/2018"
SFDate::SFDate(const char *aDateTimeString){
  char month[3];
  strncpy(month, aDateTimeString, 2);
  month[2] = '\0';
  this->month = atoi(month);
  
  char day[3];
  strncpy(day, &aDateTimeString[3], 2);
  day[2] = '\0';
  this->day = atoi(day);
  
  char year[5];
  strncpy(year, &aDateTimeString[6], 4);
  year[4] = '\0';
  this->year = atoi(year);
}


//build date from individual parts
SFDate::SFDate(int month, int day, int year){
  this->day = day;
  this->month = month;
  this->year = year;
}


SFDate::SFDate(const SFDate &aCopy){
  this->day = aCopy.day;
  this->month = aCopy.month;
  this->year = aCopy.year;
}


SFDate::SFDate(const SFDateTime &aCopy){
  /*
  this->day = aCopy.getDay();
  this->month = aCopy.getMonth();
  this->year = aCopy.getYear();
  */
}


bool SFDate::operator ++(){
  if(this->day == daysInMonth()){
    if(this->month == 12){
      this->year++;
      this->month = 1;
    }
    else{
      this->month++;
    }
    this->day = 1;
  }
  else{
    this->day++;
  }
  return true;
}


bool SFDate::operator --(){
  if(this->day == 1){
    if(this->month == 1){
      this->year--;
      this->month = 12;
    }
    else{
      this->month--;
    }
    this->day = daysInMonth();
  }
  else{
    this->day--;
  }
  return true;
}


SFInterval SFDate::operator -(const SFDate &other) const{
  SFInterval * res;
  res = new SFInterval();
  res->hours = 0;
  res->minutes = 0;
  res->seconds = 0;
  int offset_day = 0;
  int offset_month = 0;
  int offset_year = 0;
  // this: 2019/9/21, other: 2016/8/20
  if(this->ahead(other)){
    res->positive = false;
    if(month == other.getMonth()){
      if(day < other.getDay()){
        offset_day = day + other.daysInMonth()-other.getDay();
        offset_month = 11;
        offset_year = year - other.getYear()-1;
      }
      else{
        offset_day = day - other.getDay();
        offset_month = 0;
        offset_year = year - other.getYear();
      }
    }
    else{
      if(day > other.getDay()){
        offset_day = day - other.getDay();
        if(month > other.getMonth()){
          offset_month = month - other.getMonth();
          offset_year = year - other.getYear();
        }
        else{
          offset_month = month + 12 - other.getMonth();
          offset_year =year - other.getYear() - 1;
        }
      }
      else{
        offset_day = day + other.daysInMonth() - other.getDay();
        if(month > other.getMonth()){
          offset_month = month - other.getMonth()-1;
          offset_year = year - other.getYear();
        }
        else{
          offset_month = month + 12 - other.getMonth()-1;
          offset_year = year - other.getYear() - 1;
        }
      }
    }
  }
  // this: 2016/8/20, other: 2019/9/21
  else{
    res->positive = true;
    if(month == other.getMonth()){
      if(day > other.getDay()){
        offset_day = other.getDay() + daysInMonth() - day;
        offset_month = 11;
        offset_year = other.getYear() - year - 1;
      }
      else{
        offset_day = other.getDay() - day;
        offset_month = 0;
        offset_year = other.year - year;
      }
    }
    else{
      if(day < other.getDay()){
        offset_day = other.getDay() - day;
        if(month < other.getMonth()){
          offset_month = other.getMonth() - month;
          offset_year = other.getYear() - year;
        }
        else{
          offset_month = other.getMonth() + 12 - month;
          offset_year = other.getYear() - year - 1;
        }
      }
      else{
        offset_day = other.getDay() + daysInMonth() - day;
        if(month < other.getMonth()){
          offset_month = other.getMonth() - month - 1;
          offset_year = other.getYear() - year;
        }
        else{
          offset_month = other.getMonth() + 12 - month - 1;
          offset_year = other.getYear() - year - 1;
        }
      }
    }
  }
  res->days = offset_day;
  res->months = offset_month;
  res->years = offset_year;
  return *res;
  
} //determine interval between two dates...
/*
SFInterval SFDate::operator-(const SFDateTime &other) const{
  
}*/ //determine interval between two objects...


SFDate& SFDate::adjustByDays(int n){
  while(n > 0){
    day++;
    if(day > daysInMonth()){
      if(month == 12){
        year++;
        month = 1;
      }
      else{
        month++;
      }
      day = 1;
    }
    n--;
  }
  
  while(n < 0){
    day--;;
    if(day == 0){
      if(month == 1){
        year--;
        month = 12;
      }
      else{
        month--;
      }
      day = daysInMonth();
    }
    n++;
  }
  return *this;
} //-- to add or subtract N days from the given date


SFDate& SFDate::adjustByWeeks(int n){
  while(n > 0){
    day += 7;
    if(day > daysInMonth()){
      int over = daysInMonth() - day;
      if(month == 12){
        year++;
        month = 1;
      }
      else{
        month++;
      }
      day = over;
    }
    n--;
  }
  
  while(n < 0){
    day -= 7;
    if(day <= 0){
      if(month == 1){
        year--;
        month = 12;
      }
      else{
        month--;
      }
      day = daysInMonth()+day;
    }
    n++;
  }
  
  return *this;
} //-- to add or subtract N weeks from the given date


SFDate& SFDate::adjustByMonths(int n){
  int des_month = month + n;
  if(des_month > 0){
    year += des_month/13;
    month = des_month%12;
    if(month == 0){
      month = 12;
    }
  }
  
  if(des_month <= 0){
    year += (des_month/(-12))+1;
    //todo
    month = des_month%(-12);
    if(month == 0){
      month = 12;
    }
  }
  int day_offset = day - daysInMonth(); // in case the date like 2/30 is invalid
  if(day_offset != 0){
    month++;
    day = day_offset;
  }
  return *this;
} //-- to add or subtract N months from the given date


SFDate& SFDate::adjustByYears(int n){
  this->year += n;
  return *this;
} //-- to add or subtract N years from the given date


SFDate& SFDate::setDay(int aDay){
  if(aDay <= 0 || aDay > daysInMonth()){
    std::cout<<"Invalid day in setDay"<<std::endl;
    exit(2);
  }
  this->day = aDay;
  return *this;
}  //set the current day of the given date object; aDay must be in valid range


SFDate& SFDate::setMonth(int aMonth){
  if(aMonth <= 0 || aMonth > 12){
    std::cout<<"Invalid month in setMonth"<<std::endl;
    exit(2);
  }
  this->month = aMonth;
  return *this;
}  //set the current month of the given date object aMonth must be in valid range


SFDate& SFDate::setYear(int aYear){
  if(aYear <= 0){
    std::cout<<"Invalid year in setYear"<<std::endl;
    exit(2);
  }
  this->year = aYear;
  return *this;
}   //set the current year; must be in valid range


int SFDate::getDay() const{
  return this->day;
}//if date is 12/15/2018, the day is the 15th


int SFDate::getMonth() const{
  return this->month;
}  //if date is 12/15/2018, the month is 12 (dec)


int SFDate::getYear() const{
  return this->year;
}   //if date is 12/15/2018, the year is 2018

int SFDate::getWeekOfYear() const{
  return ceil(getDayOfYear()/7);
} //if date is 01/10/2018, the week of year is 2 (range is 1..52)


int SFDate::getDayOfYear() const{
  int res = 0;
  for(int i = 1; i < month; i++){
    res += daysInMonth(i);
  }
  res += day;
  return res;
}  //if date is 01/04/1961, the day of year is 4 (range is 1..365)



int SFDate::getDayOfweek() const{
  time_t rawtime;
  struct tm * timeinfo;
  /*
  const char * weekday[] = { "Sunday", "Monday",
    "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"};
  */
  time ( &rawtime );
  timeinfo = gmtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;
  
  /* call mktime: timeinfo->tm_wday will be set */
  mktime ( timeinfo );
  return timeinfo->tm_wday;
}  //range (0..6 -- 0==sunday)


int SFDate::daysInMonth() const{
  return daysInMonth(month);
}


int SFDate::daysInMonth(int month_number) const{
  if(month_number == 1){
    return 31;
  }
  if(month_number == 2){
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
      return 29;
    else{
      return 28;
    }
  }
  if(month_number == 3){
    return 31;
  }
  if(month_number == 4){
    return 30;
  }
  if(month_number == 5){
    return 31;
  }
  if(month_number == 6){
    return 30;
  }
  if(month_number == 7){
    return 31;
  }
  if(month_number == 8){
    return 31;
  }
  if(month_number == 9){
    return 30;
  }
  if(month_number == 10){
    return 31;
  }
  if(month_number == 11){
    return 30;
  }
  if(month_number == 12){
    return 31;
  }
  else{
    std::cout<<"something wrong in helper daysInMonth"<<std::endl;
    return -1;
  }
}

SFDate& SFDate::startOfMonth(){
  day = 1;
  return *this;
} //if date is 12/15/2018, return 12/01/2018

SFDate& SFDate::endOfMonth(){
  day = daysInMonth();
  return *this;
}   //if date is 12/15/2018, return 12/31/2018

SFDate& SFDate::startOfYear(){
  day = 1;
  month = 1;
  return *this;
}  //if date is 12/15/2018, return 01/01/2018

SFDate& SFDate::endOfYear(){
  day = 31;
  month = 12;
  return *this;
}    //if date is 12/15/2018, return 12/31/2018

std::string SFDate::toDateString(){
  std::string res;
  if(day < 10){
    res.append(std::to_string(0));
  }
  res.append(std::to_string(day));
  res.append("/");
  if(month < 10){
    res.append(std::to_string(0));
  }
  res.append(std::to_string(month));
  res.append("/");

  res.append(std::to_string(year));
  return res;

}  //Returns string of the form MM/DD/YYYY


//Returns string of the form Jan 4, 1961
std::string SFDate::toEnglishDateString(){
  std::string res;
  res.append(month_to_abrev(month));
  res.append(" ");
  res.append(std::to_string(day));
  res.append(", ");
  res.append(std::to_string(year));
  return res;
}

std::string SFDate::month_to_abrev(int m){
  switch (m) {
    case 1:
      return "Jan";
      break;
    case 2:
      return "Feb";
      break;
    case 3:
      return "Mar";
      break;
    case 4:
      return "Apr";
      break;
    case 5:
      return "May";
      break;
    case 6:
      return "Jun";
      break;
    case 7:
      return "Jul";
      break;
    case 8:
      return "Aug";
      break;
    case 9:
      return "Sep";
      break;
    case 10:
      return "Oct";
      break;
    case 11:
      return "Nov";
      break;
    case 12:
      return "Dec";
      break;
    default:
      break;
  }
  return "NAN";
}

bool SFDate::operator >(SFDate & other) const{
  if(year > other.getYear()) return true;
  if(year == other.getYear() && month > other.getMonth()) return true;
  if(year == other.getYear() && month == other.getMonth() && day > other.getDay()) return true;
  return false;
}

bool SFDate::operator ==(SFDate & other) const{
  if(day == other.getDay() && month == other.getMonth() && year == other.getYear()){
    return true;
  }
  else return false;
}

bool SFDate::operator <(SFDate & other) const{
  if(year < other.getYear()) return true;
  if(year == other.getYear() && month < other.getMonth()) return true;
  if(year == other.getYear() && month == other.getMonth() && day < other.getDay()) return true;
  return false;
}

bool SFDate::ahead(const SFDate & other) const{
  if(year > other.getYear()) return true;
  if(year == other.getYear() && month > other.getMonth()) return true;
  if(year == other.getYear() && month == other.getMonth() && day > other.getDay()) return true;
  return false;
}

