//
//  SFDateTime.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include "SFDateTime.hpp"

SFDateTime::SFDateTime(SFTimezone *aTimezone){
  /*
  time_t rawtime;
  struct tm * ptm;
  time ( &rawtime );
  ptm = gmtime ( &rawtime );
  day = ptm->tm_wday;
  month = ptm->tm_mon;
  year = ptm->tm_year;
  hour = ptm->tm_hour;
  min = ptm->tm_min;
  sec = ptm->tm_sec;
   */
  zone_offset = 0;
   
  if(aTimezone != nullptr){
    zone_offset = aTimezone->get_offset();
  }
  if(zone_offset != 0){
    if(zone_offset + hour < 0){
      adjustByDays(-1);
    }
    else if(zone_offset + hour >= 24){
      adjustByDays(1);
    }
    adjustByHours(zone_offset);
  }
}


SFDateTime::SFDateTime(const SFDateTime &aCopy): SFDate(aCopy), SFTime(aCopy), zone_offset(aCopy.zone_offset){
}


SFDateTime::SFDateTime(int aMonth, int aDay, int aYear, int anHour, int aMinutes, int aSeconds, SFTimezone *aTimezone): SFDate(aMonth, aDay, aYear), SFTime(anHour, aMinutes, aSeconds){
  if(aTimezone == nullptr){
    zone_offset = 0;
  }
  else zone_offset = aTimezone->get_offset();
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
  }
  else zone_offset = aTimezone->get_offset();
}

