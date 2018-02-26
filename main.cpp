//
//  main.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include <stdio.h>
//#include "SFDate.hpp"
#include "SFDateTime.hpp"
#include <time.h>
int main(int argc, const char * argv[]) {

  /*
  time_t rawtime;
  struct tm * timeinfo;
  int year, month ,day;
  const char * weekday[] = { "Sunday", "Monday",
    "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"};
  

  printf ("Enter year: "); fflush(stdout); scanf ("%d",&year);
  printf ("Enter month: "); fflush(stdout); scanf ("%d",&month);
  printf ("Enter day: "); fflush(stdout); scanf ("%d",&day);
  
 
  time ( &rawtime );
  timeinfo = gmtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;
  
  
  mktime ( timeinfo );
  
  printf ("That day is a %s.\n", weekday[timeinfo->tm_wday]);
  */
  
  SFDate sfd1 = SFDate(8, 20, 2016);
  SFDate sfd2 = SFDate(9, 21, 2019);
  SFInterval interval1 = sfd1 - sfd2;
  std::cout<<"interval result: "<<(const char*)interval1<<std::endl;
  
  /*
  SFDateTime sfdt1 = SFDateTime(8, 20, 2016);
  SFDateTime sfdt2 = SFDateTime(9, 21, 2019);
  SFInterval interval2 = sfdt1 - sfdt2;
  std::cout<<"interval result: "<<(const char*)interval<<std::endl;
  */
  return 0;
  
}
