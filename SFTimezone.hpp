//
//  SFTimezone.hpp
//  ECE180-Assignment3
//
//  Created by Yuming on 2/17/18.
//  Copyright © 2018 Yuming. All rights reserved.
//

#ifndef SFTimezone_hpp
#define SFTimezone_hpp

#include <stdio.h>
#include <iostream>
class SFTimezone {
public:
  SFTimezone();
  SFTimezone(const char* aTimezoneAbbrev); //GMT, EST, CST, PST
  SFTimezone(const SFTimezone &aTimezone);
  int get_offset();
  std::string get_zone();
  operator const char*(); // Returns the 3 letter abbreviation of the timezone object
  
  bool operator ==(SFTimezone & other) const;
  bool operator !=(SFTimezone & other) const;
  //...other members as needed...
  /*
  GMT (GMT as described above)
  EST (US Eastern standard time)
  CST (US Central standard time)
  PST (US Pacific standard time)
   */
private:
  std::string zone;
  int offset;
};

#endif /* SFTimezone_hpp */
