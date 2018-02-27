//
//  SFInterval.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include "SFInterval.hpp"


SFInterval::SFInterval(){
  years = 0;
  months = 0;
  days = 0;
  hours = 0;
  minutes = 0;
  seconds = 0;
  positive = true;
}

SFInterval::SFInterval(int ayears, int amonths, int adays, int ahours, int aminutes, int aseconds, bool apositive):years(ayears), months(amonths), days(adays), hours(ahours), minutes(aminutes), seconds(aseconds), positive(apositive){
}

SFInterval::operator const char*(){
  std::string res;
  if(positive == false){
    res.append("-");
  }
  res.append(std::to_string(years));
  res.append(" years, ");
  res.append(std::to_string(months));
  res.append(" months, ");
  res.append(std::to_string(days));
  res.append(" days, ");
  res.append(std::to_string(hours));
  res.append(" hours, ");
  res.append(std::to_string(minutes));
  res.append(" minutes and ");
  res.append(std::to_string(seconds));
  res.append(" seconds");
  return res.c_str();
}

bool SFInterval::isZero(){
  return (years == 0 && months == 0 && days ==0 && hours == 0 && minutes == 0 && seconds ==0);
}


void SFInterval::flip(){
  if(seconds == 0){
    seconds = 0;
    if(minutes == 0){
      minutes = 0;
      if(hours == 0){
        hours = 0;
      }
      else{
        hours = 24 - hours;
      }
    }
    else{
      minutes = 60 - minutes;
      hours = 23 - hours;
    }
  }
  else{
    seconds = 60 - seconds;
    minutes = 59 - minutes;
    hours = 23 - hours;
  }
}

bool SFInterval::operator ==(SFInterval & other) const{
  return (years == other.years && months == other.months && days == other.days && hours == other.hours && minutes == other.minutes && seconds == other.seconds);
}

bool SFInterval::operator !=(SFInterval & other) const{
  return !(*this == other);
}

bool SFInterval::operator >(SFInterval & other) const{
  if(years>other.years) return true;
  if(years<other.years) return false;
  if(months>other.months) return true;
  if(months<other.months) return false;
  if(days>other.days) return true;
  if(days<other.days) return false;
  if(hours>other.hours) return true;
  if(hours<other.hours) return false;
  if(minutes>other.minutes) return true;
  if(minutes<other.minutes) return false;
  if(seconds>other.seconds) return true;
  if(seconds<other.seconds) return false;
  return false;
}

bool SFInterval::operator >=(SFInterval & other) const{
  return ((*this == other)||(*this>other));
}
bool SFInterval::operator <(SFInterval & other) const{
  return !(*this >= other);
}
bool SFInterval::operator <=(SFInterval & other) const{
  return (*this==other || *this<other);
}
