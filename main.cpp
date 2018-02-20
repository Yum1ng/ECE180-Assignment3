//
//  main.cpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#include <stdio.h>
#include "SFDate.hpp"
#include <time.h>
int main(int argc, const char * argv[]) {

  
  time_t rawtime;
  struct tm * timeinfo;
  int year, month ,day;
  const char * weekday[] = { "Sunday", "Monday",
    "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"};
  
  /* prompt user for date */
  printf ("Enter year: "); fflush(stdout); scanf ("%d",&year);
  printf ("Enter month: "); fflush(stdout); scanf ("%d",&month);
  printf ("Enter day: "); fflush(stdout); scanf ("%d",&day);
  
  /* get current timeinfo and modify it to the user's choice */
  time ( &rawtime );
  timeinfo = gmtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;
  
  /* call mktime: timeinfo->tm_wday will be set */
  mktime ( timeinfo );
  
  printf ("That day is a %s.\n", weekday[timeinfo->tm_wday]);
  return 0;
  
}
