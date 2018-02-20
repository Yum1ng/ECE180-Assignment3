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

class SFTimezone {
  SFTimezone(const char* aTimezoneAbbrev); //GMT, EST, CST, PST
  SFTimezone(const SFTimezone &aTimezone);
  
  operator const char*(); // Returns the 3 letter abbreviation of the timezone object
  
  //...other members as needed...
};

#endif /* SFTimezone_hpp */
