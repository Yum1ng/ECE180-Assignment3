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
#include "SFTestHarness.hpp"
int main(int argc, const char * argv[]) {

  
  SFDate sfd1 = SFDate(8, 20, 2016);
  SFDate sfd2 = SFDate(9, 21, 2019);
  SFInterval interval1 = sfd2 - sfd1;
  std::cout<<"interval result: "<<(const char*)interval1<<std::endl;
  SFDateTime sfdt1 = SFDateTime(3, 16, 2018);
  SFDate sfd3 = SFDate(sfdt1);
  std::cout<<"constructor result: "<<sfd3.toDateString()<<std::endl;
  
  SFInterval interval2 = sfd2 - sfdt1;
  std::cout<<"interval result: "<<(const char*)interval2<<std::endl;
  
  
  SFTime sft1 = SFTime(2, 10, 9);
  SFTime sft2 = SFTime(12, 10, 10);
  SFInterval interval3 = sft2 - sft1;
  std::cout<<"interval result: "<<(const char*)interval3<<std::endl;
  
  SFDateTime sfdt2 = SFDateTime(3, 16, 2018, 12, 10, 10);
  SFTime sft3 = SFTime(sfdt2);
  std::cout<<"constructor result: "<<sft3.toTimeString()<<std::endl;
  SFInterval interval4 = sft3 - sft1;
  std::cout<<"interval result: "<<(const char*)interval4<<std::endl;
  
  
  SFDateTime sf_dt1 = SFDateTime(2, 27, 2018, 10, 20, 10);
  SFDateTime sf_dt2 = SFDateTime(3, 1, 2018, 2, 10, 05);
  SFInterval interval_dt = sf_dt2 - sf_dt1;
  std::cout<<"interval_dt result: "<<(const char*)interval_dt<<std::endl;
  
  SFDateTime sf_dt3 = SFDateTime(2, 27, 2018, 10, 20, 10);
  SFDateTime sf_dt4 = SFDateTime(3, 1, 2018, 2, 10, 05);
  SFInterval interval_dt2 = sf_dt3 - sf_dt4;
  std::cout<<"interval_dt result: "<<(const char*)interval_dt2<<std::endl;
  
  std::cout<<"####### Start SFTest #######"<<std::endl;
  int error = SoftwareFoundations::SFTestHarness::runAllTests();
  std::cout<<"Total error : "<< error <<std::endl;
  return 0;
  
  
}
