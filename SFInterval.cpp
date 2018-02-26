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
