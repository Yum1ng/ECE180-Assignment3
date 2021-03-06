//
//  SFInterval.hpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#ifndef SFInterval_hpp
#define SFInterval_hpp

#include <stdio.h>
#include <iostream>

class SFInterval {
public:
  SFInterval();
  SFInterval(int ayears, int amonths, int adays, int ahours, int aminutes, int aseconds, bool apositive);
  int years;
  int months;
  int days;
  int hours;
  int minutes;
  int seconds;
  bool positive;
  operator const char*(); // Returns the interval of the form "Y years, M months, D days, H hours, M minutes and S seconds"
  // Ex. 5 years, 3 months, 2 days, 6 hours, 7 minutes and 10 seconds
  bool isZero();
  void flip();
  bool operator ==(SFInterval & other) const;
  bool operator !=(SFInterval & other) const;
  bool operator >(SFInterval & other) const;
  bool operator >=(SFInterval & other) const;
  bool operator <(SFInterval & other) const;
  bool operator <=(SFInterval & other) const;
  
};
#endif /* SFInterval_hpp */
