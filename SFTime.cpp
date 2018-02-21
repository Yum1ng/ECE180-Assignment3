//
//  SFTime.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include "SFTime.hpp"
#include <math.h>

SFTime::SFTime(){
  time_t rawtime;
  struct tm * ptm;
  time ( &rawtime );
  ptm = gmtime ( &rawtime );
  hour = ptm->tm_hour;
  min = ptm->tm_min;
  sec = ptm->tm_sec;
}                            //default to now(HH:MM:SS)

SFTime::SFTime(const char *aTimeString){
  char hourstr[3];
  strncpy(hourstr, aTimeString, 2);
  hourstr[2] = '\0';
  hour = atoi(hourstr);
  
  char minstr[3];
  strncpy(minstr, &aTimeString[3], 2);
  minstr[2] = '\0';
  min = atoi(minstr);
  
  char secstr[3];
  strncpy(secstr, &aTimeString[6], 2);
  secstr[2] = '\0';
  sec = atoi(secstr);
}      //must parse the given string of the form "HH:MM:SS"


SFTime::SFTime(int anHour, int aMinutes, int aSeconds){
  hour = anHour;
  min = aMinutes;
  sec = aSeconds;
} //build time from individual parts


SFTime::SFTime(const SFTime &aCopy){
  hour = aCopy.hour;
  min = aCopy.min;
  sec = aCopy.sec;
}


SFTime::SFTime(const SFDateTime &aCopy){
  // TODO
}


SFTime& SFTime::adjustByMinutes(int n){
  if(n > 0){
    adjustByHours(n/60);
    n %= 60;
    while(n > 0){
      min++;
      if(min > 59){
        if(hour == 23){
          hour = 0;
        }
        else{
          hour++;
        }
        min = 0;
      }
      n--;
    }
  }
  if(n < 0){
    adjustByHours(n/60);
    n %= -60;
    while(n < 0){
      min--;
      if(min < 0){
        if(hour == 0){
          hour = 23;
        }
        else{
          hour--;
        }
        min = 59;
      }
      n++;
    }
  }
    
  return *this;
} //-- to +/- N minutes from the given time

  
SFTime& SFTime::adjustByHours(int n){
  hour += n;
  hour %= 24;
  return *this;
} //-- to +/- N hours from the given time. 11:15pm + 2hours is 1:15a (rolls over)


/*
SFInterval SFTime::operator-(const SFTime &other) const{
  SFInterval res = SFInterval();
  //res.hours =
  return res;
  
} //determine interval between two times...
SFInterval SFTime::operator-(const SFDateTime &other) const{
  
} //determine interval between two objects...
*/


int SFTime::getHour(){
  return hour;
}
int SFTime::getMinutes(){
  return min;
}
int SFTime::getSeconds(){
  return sec;
}

SFTime& SFTime::startOfDay(){
  hour = 0;
  min = 0;
  sec = 0;
  return *this;
} //change time to (00:00:00)


SFTime& SFTime::endOfDay(){
  hour = 23;
  min = 59;
  sec = 59;
  return *this;
}   //change time to (23:59:59)

std::string SFTime::toTimeString(){
  std::string res;
  if(hour < 10){
    res.append(std::to_string(0));
  }
  res.append(std::to_string(hour));
  res.append(":");
  if(min < 10){
    res.append(std::to_string(0));
  }
  res.append(std::to_string(min));
  res.append(":");
  if(sec < 10){
    res.append(std::to_string(0));
  }
  res.append(std::to_string(sec));
  return res;
  
}  //Returns string of the form HH:MM:SS

//ADD RELATIONAL OPERATORS HERE... >, <, <=, >=, !=, ==

