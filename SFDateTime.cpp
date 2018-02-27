//
//  SFDateTime.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include "SFDateTime.hpp"

SFDateTime::SFDateTime(SFTimezone *aTimezone): SFDate(), SFTime(){

  if(aTimezone == nullptr){
    zone_offset = 0;
    zone = "GMT";
  }
  else{
    zone_offset = aTimezone->get_offset();
    zone = (const char*)aTimezone;
  }
  /*
  if(zone_offset != 0){
    if(zone_offset + hour < 0){
      adjustByDays(-1);
    }
    else if(zone_offset + hour >= 24){
      adjustByDays(1);
    }
    adjustByHours(zone_offset);
  }
   */
}


SFDateTime::SFDateTime(const SFDateTime &aCopy): SFDate(aCopy), SFTime(aCopy), zone_offset(aCopy.zone_offset), zone(aCopy.zone){
}


SFDateTime::SFDateTime(int aMonth, int aDay, int aYear, int anHour, int aMinutes, int aSeconds, SFTimezone *aTimezone): SFDate(aMonth, aDay, aYear), SFTime(anHour, aMinutes, aSeconds){
  if(aTimezone == nullptr){
    zone_offset = 0;
    zone = "GMT";
  }
  else{
    zone_offset = aTimezone->get_offset();
    zone = (const char *)aTimezone;
  }
}

//parse the given string of the form "MM/DD/YYYY HH:MM:SS"
SFDateTime::SFDateTime(const char* aString, SFTimezone *aTimezone){
  char month[3];
  strncpy(month, aString, 2);
  month[2] = '\0';
  this->month = atoi(month);
  
  char day[3];
  strncpy(day, &aString[3], 2);
  day[2] = '\0';
  this->day = atoi(day);
  
  char year[5];
  strncpy(year, &aString[6], 4);
  year[4] = '\0';
  this->year = atoi(year);
  
  //Time
  char hourstr[3];
  strncpy(hourstr, &aString[11], 2);
  hourstr[2] = '\0';
  hour = atoi(hourstr);
  
  char minstr[3];
  strncpy(minstr, &aString[14], 2);
  minstr[2] = '\0';
  min = atoi(minstr);
  
  char secstr[3];
  strncpy(secstr, &aString[17], 2);
  secstr[2] = '\0';
  sec = atoi(secstr);
  
  if(aTimezone == nullptr){
    zone_offset = 0;
    zone = aTimezone->get_zone();
  }
  else{
    zone_offset = aTimezone->get_offset();
    zone = aTimezone->get_zone();
  }
}


SFDateTime::SFDateTime(const SFDate &aDate, const SFTime &aTime, SFTimezone *aTimezone): SFDate(aDate), SFTime(aTime){
  if(aTimezone == nullptr){
    zone_offset = 0;
    zone = "GMT";
  }
  else{
    zone_offset = aTimezone->get_offset();
    zone = (const char *)aTimezone;
  }
}


SFInterval SFDateTime::operator-(const SFDateTime &other) const{
  SFTimezone GMT_zone = SFTimezone("GMT");
  SFDateTime this_date_GMT = SFDateTime(*this).setTimezone(GMT_zone);
  SFDateTime other_date_GMT = SFDateTime(other).setTimezone(GMT_zone);
  SFDate this_date = SFDate(this_date_GMT);
  SFTime this_time = SFTime(this_date_GMT);
  SFDate other_date = SFDate(other_date_GMT);
  SFTime other_time = SFTime(other_date_GMT);
  SFInterval date_interval = this_date - other_date;
  SFInterval time_interval = this_time - other_time;
  if(date_interval.isZero()) return time_interval;
  if(time_interval.isZero()) return date_interval;
  
  SFInterval * res;
  res = new SFInterval();
  if(time_interval.positive == true){
    if(date_interval.positive == true){
      res->positive = true;
      res->years = date_interval.years;
      res->months = date_interval.months;
      res->days = date_interval.days;
      res->hours = time_interval.hours;
      res->minutes = time_interval.minutes;
      res->seconds = time_interval.seconds;
    }
    else{
      res->positive = false;
      time_interval.flip();
      this_date.adjustByDays(-1);
      date_interval = this_date - other_date;
      res->years = date_interval.years;
      res->months = date_interval.months;
      res->days = date_interval.days;
      res->hours = time_interval.hours;
      res->minutes = time_interval.minutes;
      res->seconds = time_interval.seconds;
    }
  }
  else{
    if(date_interval.positive == false){
      res->positive = false;
      res->years = date_interval.years;
      res->months = date_interval.months;
      res->days = date_interval.days;
      res->hours = time_interval.hours;
      res->minutes = time_interval.minutes;
      res->seconds = time_interval.seconds;
    }
    else{
      res->positive = true;
      time_interval.flip();
      this_date.adjustByDays(1);
      date_interval = this_date - other_date;
      res->years = date_interval.years;
      res->months = date_interval.months;
      res->days = date_interval.days;
      res->hours = time_interval.hours;
      res->minutes = time_interval.minutes;
      res->seconds = time_interval.seconds;
    }
  }
  
  return *res;
} //determine interval between two objects...


SFTimezone& SFDateTime::getTimezone(){
  SFTimezone * tz = new SFTimezone(zone.c_str());
  return *tz;
}

SFDateTime& SFDateTime::setTimezone(SFTimezone &aTimezone){
  int offset = aTimezone.get_offset() - zone_offset;
  adjustByHours(offset);
  zone_offset = aTimezone.get_offset();
  zone = (const char *)aTimezone;
  return *this;
}


std::string SFDateTime::toDateTimeString(){
  std::string res;
  res.append(SFDate::toEnglishDateString());
  res.append(" ");
  res.append(SFTime::toTimeString());
  res.append(" ");
  //TODO is-a or has -a ???
  res.append(zone);
  return res;
}


SFDateTime::operator SFTimezone(){
  return SFTimezone(zone.c_str());
}


SFDate::SFDate(const SFDateTime &aCopy):SFDate(aCopy.getMonth(), aCopy.getDay(), aCopy.getYear()){
}


SFInterval SFDate::operator-(const SFDateTime &other) const{
  SFDate temp = SFDate(other);
  return (*this-temp);
} //determine interval between two objects...


SFTime::SFTime(const SFDateTime &aCopy):SFTime(aCopy.hour, aCopy.min, aCopy.sec){
}


SFInterval SFTime::operator-(const SFDateTime &other) const{
  SFTime temp = SFTime(other);
  return (*this-temp);
}

bool SFDateTime::operator >(SFDateTime & other) const{
  SFInterval res = (*this)-other;
  if(res.isZero()) return false;
  return (res.positive == false);
}

bool SFDateTime::operator ==(SFDateTime & other) const{
  SFInterval res = (*this)-other;
  return res.isZero();
}

bool SFDateTime::operator !=(SFDateTime & other) const{
  return !(*this == other);
}

bool SFDateTime::operator <(SFDateTime & other) const{
  return (*this != other && !(*this > other));
}

bool SFDateTime::operator >=(SFDateTime & other) const{
  return (*this==other || *this > other);
}

bool SFDateTime::operator <=(SFDateTime & other) const{
  return (*this == other || *this < other);
}
