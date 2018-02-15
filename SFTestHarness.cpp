//
//  SFTestHarness.cpp
//  ECE180-Assignment3
//
//  Created by rick gessner on 2/12/18.
//

#include "SFTestHarness.hpp"

using SoftwareFoundations::SFTestHarness;

int SFTestHarness::runDateTests() {
  return 0;
}

int SFTestHarness::runTimeTests() {
  return 0;
}

int SFTestHarness::runDateTimeTests() {
  return 0;
}

int SFTestHarness::runIntervalTests() {
  return 0;
}

int SFTestHarness::runTimezoneTests() {
  return 0;
}

int SFTestHarness::runAllTests() {
  int theResult = runDateTests();
  theResult+=runTimeTests();
  theResult+=runDateTimeTests();
  theResult+=runIntervalTests();
  theResult+=runTimezoneTests();
  return theResult;
}
