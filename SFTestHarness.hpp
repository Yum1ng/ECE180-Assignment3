//
//  SFTestHarness.hpp
//  ECE180-Assignment3
//
//  Created by rick gessner on 2/12/18.
//  Copyright © 2018 rick gessner. All rights reserved.
//

#ifndef SFTestHarness_hpp
#define SFTestHarness_hpp

namespace SoftwareFoundations {

  class SFTestHarness {
  public:
    static int runAllTests();
    static int runDateTests();
    static int runTimeTests();
    static int runDateTimeTests();
    static int runIntervalTests();
    static int runTimezoneTests();
  };

}

#endif /* SFTestHarness_hpp */
