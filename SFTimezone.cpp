//
//  SFTimezone.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include "SFTimezone.hpp"

SFTimezone::SFTimezone(){
  zone = "GMT";
  offset = 0;
}

SFTimezone::SFTimezone(const char* aTimezoneAbbrev){
  if(strcmp("GMT", aTimezoneAbbrev) == 0){
    zone = "GMT";
    offset = 0;
  }
  else if(strcmp("EST", aTimezoneAbbrev) == 0){
    zone = "EST";
    offset = -5;
  }
  else if(strcmp("CST", aTimezoneAbbrev) == 0){
    zone = "CST";
    offset = -6;
  }
  else if(strcmp("PST", aTimezoneAbbrev) == 0){
    zone = "PST";
    offset = -8;
  }
  else{
    std::cout<<"not support time zone"<<std::endl;
    exit(2);
  }
  
}

SFTimezone::SFTimezone(const SFTimezone &aTimezone){
  zone = aTimezone.zone;
  offset = aTimezone.offset;
}


int SFTimezone::get_offset(){
  return offset;
}

std::string SFTimezone::get_zone(){
  return zone;
}


SFTimezone::operator const char*(){
  return zone.c_str();
}

bool SFTimezone::operator ==(SFTimezone & other) const{
  return (offset == other.get_offset() && (zone.compare(other.zone) == 0));
}
bool SFTimezone::operator !=(SFTimezone & other) const{
  return !(*this == other);
}
