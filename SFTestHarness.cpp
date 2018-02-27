//
//  SFTestHarness.cpp
//  ECE180-Assignment3
//
//  Created by rick gessner on 2/12/18.
//

#include "SFTestHarness.hpp"
#include "SFDateTime.hpp"

using SoftwareFoundations::SFTestHarness;

int SFTestHarness::runDateTests() {
  std::cout<<"1. In SFDatetest"<<std::endl;
  int error = 0;
  SFDate today = SFDate();
  SFDate today_2_27 = SFDate(2, 27, 2018);
  if(today != today_2_27){
    std::cout<<"default constructor wrong"<<std::endl;
    error ++;
  }
  
  std::string today_str = "02/27/2018";
  std::string result =today_2_27.toDateString();
  if(today_str.compare(result) != 0){
    std::cout<<"default toDateString wrong"<<std::endl;
    error ++;
  }
  
  if(today != today_2_27){
    std::cout<<"default constructor wrong"<<std::endl;
    error ++;
  }
  
  today = SFDate("Feb 27, 2018");
  if(today != today_2_27){
    std::cout<<"default constructor reading string wrong"<<std::endl;
    error ++;
  }
  SFDate date1 = SFDate("02/27/2018");
  if(date1 != today_2_27){
    std::cout<<"parse constructor wrong"<<std::endl;
    error ++;
  }
  
  SFDate date2 = SFDate(date1);
  if(date2 != date1){
    std::cout<<"copy constructor wrong"<<std::endl;
    error ++;
  }
  SFDateTime date_time1 = SFDateTime(2,27,2018, 1, 1, 1);
  SFDate date3 = SFDate(date_time1);
  if(date3 != today_2_27){
    std::cout<<"SFDateTime to SFDate copy constructor wrong"<<std::endl;
    error ++;
  }
  SFDate date4 = SFDate(2, 26, 2018);
  ++date4;
  if(date4 != today_2_27){
    std::cout<<"SFDate ++ wrong"<<std::endl;
    error ++;
  }
  ++date4;
  --date4;
  if(date4 != today_2_27){
    std::cout<<"SFDate -- wrong"<<std::endl;
    error ++;
  }
  
  date1 = SFDate(8, 20, 2016);
  date2 = SFDate(9, 21, 2019);
  if(!(date1 < date2)){
    std::cout<<"SFDate < operator wrong"<<std::endl;
    error ++;
  }
  if(!(date1 <= date2)){
    std::cout<<"SFDate <= operator wrong"<<std::endl;
    error ++;
  }
  
  SFInterval inter1 = date1 - date2;
  SFInterval inter1_right = SFInterval(3, 1, 1, 0, 0, 0, true);
  if(inter1 != inter1_right){
    std::cout<<"SFDate - operator wrong"<<std::endl;
    error ++;
  }
  
  SFDateTime sfdate = SFDateTime(9, 21, 2019, 1, 1, 1);
  SFInterval inter2 = date1 - sfdate;
  SFInterval inter2_right = SFInterval(3, 1, 1, 0, 0, 0, true);
  if(inter2 != inter2_right){
    std::cout<<"SFDate - operator (SFDateTime) wrong"<<std::endl;
    error ++;
  }
  
  date1.adjustByDays(5);
  SFDate date1_after_adjust = SFDate(8, 25, 2016);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by days wrong"<<std::endl;
    error ++;
  }
  date1.adjustByWeeks(-1);
  date1_after_adjust = SFDate(8, 18, 2016);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by weeks wrong"<<std::endl;
    error ++;
  }
  
  date1.adjustByMonths(2);
  date1_after_adjust = SFDate(10, 18, 2016);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by months wrong"<<std::endl;
    error ++;
  }
  
  date1.adjustByYears(-2);
  date1_after_adjust = SFDate(10, 18, 2014);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by years wrong"<<std::endl;
    error ++;
  }
  
  date1.adjustByYears(1);
  date1.adjustByMonths(2);
  date1.adjustByWeeks(2);
  date1.adjustByMonths(2);
  date1.adjustByWeeks(-1);
  date1.adjustByDays(6);
  date1.adjustByDays(1);
  date1.adjustByDays(-1);
  date1.adjustByYears(1);
  date1.adjustByYears(1);
  date1.adjustByYears(1);
  date1.adjustByYears(1);
  date1.adjustByDays(-1);
  date1_after_adjust = SFDate(2, 29, 2020);
  
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by years wrong"<<std::endl;
    error ++;
  }
  
  int a = date1.getDayOfweek();
  int b = date1.getDayOfYear();
  int c = date1.getWeekOfYear();
  if(a != 6 || b != 60 || c != 9){
    std::cout<<"SFDate getDayOfWeek, getDayOfYear,  getWeekOfYear  wrong"<<std::endl;
    error ++;
  }
  
  date1.startOfMonth();
  date1_after_adjust = SFDate(2, 1, 2020);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by years wrong"<<std::endl;
    error ++;
  }
  date1.endOfMonth();
  date1_after_adjust = SFDate(2, 29, 2020);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by years wrong"<<std::endl;
    error ++;
  }
  
  date1.startOfYear();
  date1_after_adjust = SFDate(1, 1, 2020);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by years wrong"<<std::endl;
    error ++;
  }
  date1.endOfYear();
  date1_after_adjust = SFDate(12, 31, 2020);
  if(date1 != date1_after_adjust){
    std::cout<<"SFDate adjust by years wrong"<<std::endl;
    error ++;
  }
  return error;
}

int SFTestHarness::runTimeTests() {
  std::cout<<"2. In SFTime test"<<std::endl;
  int error = 0;
  SFTime now = SFTime();
  std::cout<< "Time now: " << now.toTimeString()<<std::endl;
  
  SFTime time_10_30_40 = SFTime(10, 30, 40);
  SFTime time_10_30_40_str = SFTime("10:30:40");
  if(time_10_30_40 != time_10_30_40_str){
    std::cout<<"time default constructor 1 2 wrong"<<std::endl;
    error ++;
  }
  
  SFTime time_10_30_40_copy = SFTime(time_10_30_40);
  if(time_10_30_40_copy != time_10_30_40){
    std::cout<<"time default constructor 3 wrong"<<std::endl;
    error ++;
  }
  
  std::string time_10_30_40_string = "10:30:40";
  std::string result = time_10_30_40.toTimeString();
  if(time_10_30_40_string.compare(result) != 0){
    std::cout<<"SFTime toTimeString wrong"<<std::endl;
    error ++;
  }
  
  SFDateTime sf_datetime_1 = SFDateTime(12, 31, 2018, 9, 30, 40);
  SFTime time_9_30_40 = SFTime(sf_datetime_1);
  SFTime time_9_30_40_1 = SFTime("09:30:40");
  if(time_9_30_40.toTimeString().compare(time_9_30_40_1.toTimeString()) != 0){
    std::cout<<"SFTime datetime constructor wrong"<<std::endl;
    error ++;
  }
  
  SFTime time_9_59_40 = SFTime(9, 59, 40);
  time_10_30_40.adjustByMinutes(-31);
  if(time_9_59_40 != time_10_30_40){
    std::cout<<"SFTime adjust by minutes wrong"<<std::endl;
    error ++;
  }
  
  SFTime time_01_59_40 = SFTime(1, 59, 40);
  time_10_30_40.adjustByHours(16);
  if(time_01_59_40 != time_10_30_40){
    std::cout<<"SFTime adjust by hours wrong"<<std::endl;
    error ++;
  }
  
  SFTime time_23_59_40 = SFTime(23, 59, 40);
  time_10_30_40.adjustByHours(-50);
  if(time_23_59_40 != time_10_30_40){
    std::cout<<"SFTime adjust by hours wrong"<<std::endl;
    error ++;
  }
  
  
  time_01_59_40.adjustByMinutes(-120);
  if(time_23_59_40 != time_01_59_40){
    std::cout<<"SFTime adjust by minutes 2 wrong"<<std::endl;
    error ++;
  }
  
  SFTime time_01_59_40_2 = SFTime(1, 58, 40);
  time_01_59_40_2.adjustByMinutes(-119);
  if(time_23_59_40 != time_01_59_40){
    std::cout<<"SFTime adjust by minutes 2 wrong"<<std::endl;
    error ++;
  }
  
  SFTime time_23_15 = SFTime(23, 15, 0);
  SFTime time_1_15 = SFTime(1, 15, 0);
  time_23_15.adjustByHours(2);
  if(time_1_15 != time_23_15){
    std::cout<<"SFTime adjust by hours 2 wrong"<<std::endl;
    error ++;
  }
  time_23_15.adjustByHours(-2);
  time_23_15.adjustByMinutes(120);
  if(time_1_15 != time_23_15){
    std::cout<<"SFTime adjust by hours 2 wrong"<<std::endl;
    error ++;
  }
  time_23_15.startOfDay();
  time_23_15.endOfDay();
  SFTime time_end_day = SFTime(23, 59, 59);
  if(time_23_15 != time_end_day){
    std::cout<<"SFTime adjust by hours 2 wrong"<<std::endl;
    error ++;
  }
  time_23_15 = SFTime(23, 15, 0);
  SFInterval inter_2hour = time_23_15 - time_1_15;
  SFInterval two_hour = SFInterval(0, 0, 0, 22, 0, 0, false);
  
  if(inter_2hour != two_hour){
    std::cout<<"SFTime - wrong"<<std::endl;
    error ++;
  }
  
  SFDateTime date_time_1_15 = SFDateTime(1, 2, 2019, 1, 15, 0);
  SFInterval inter_2hour_2 = time_23_15 - date_time_1_15;
  if(inter_2hour_2 != two_hour){
    std::cout<<"SFTime - wrong"<<std::endl;
    error ++;
  }
  return error;
}

int SFTestHarness::runDateTimeTests() {
  int error = 0;
  std::string aDateTime1 = "02/15/2018 09:05:15";
  std::string aTimeZone1 = "PST";
  std::string aDateTime2 = "02/15/2018 11:05:15";
  std::string aTimeZone2 = "EST";
  std::string res = SFTestHarness::dataTimeDifferenceTest(aDateTime1, aTimeZone1, aDateTime2, aTimeZone2);
  std::string correct = "-0 years, 0 months, 0 days, 1 hours, 0 minutes and 0 seconds";
  if(correct.compare(res) != 0){
    std::cout<<"SFDateTime - wrong"<<std::endl;
    error ++;
  }
  
  
  return error;
}

int SFTestHarness::runIntervalTests() {
  return 0;
}

int SFTestHarness::runTimezoneTests() {
  std::cout<<"3. In SFTimezone test"<<std::endl;
  int error = 0;
  SFTimezone timezone1 = SFTimezone();
  SFTimezone timezone1_GMT = SFTimezone("GMT");
  SFTimezone timezone_PST = SFTimezone("PST");
  if(timezone1_GMT == timezone_PST){
    std::cout<<"SFTimezone constructor wrong"<<std::endl;
    error ++;
  }
  if(timezone1 != timezone1_GMT){
    std::cout<<"SFTimezone constructor wrong"<<std::endl;
    error ++;
  }
  SFTimezone timezone_EST = SFTimezone("EST");
  if(timezone_EST.get_offset() != -5){
    std::cout<<"SFTimezone get_offset() wrong"<<std::endl;
    error ++;
  }
  SFTimezone timezone_CST = SFTimezone("CST");
  if(timezone_CST.get_offset() != -6){
    std::cout<<"SFTimezone constructor wrong"<<std::endl;
    error ++;
  }
  char cst[] = "CST";
  if(strcmp(cst, (const char*)timezone_CST) != 0){
    std::cout<<"SFTimezone string converter wrong"<<std::endl;
    error ++;
  }

  return error;
}

/*
 * Return string representation of interval between two dates
 * Ex. aDate1 = "02/15/2018"
 *     aDate2 = "02/17/2018"
 * Returns : "0 years, 0 months, 2 days, 0 hours, 0 minutes and 0 seconds"
 */
std::string SFTestHarness::dateDifferenceTest(std::string aDate1, std::string aDate2) {
  return 0;
}

/*
 * Return string representation of date with weeks adjusted
 * Ex. aDate = "02/15/2018"
 *     aWeeks = 1
 * Returns : "02/22/2018"
 */
std::string SFTestHarness::adjustDateByWeeksTest(std::string aDate, int aWeeks) {
  return 0;
}

/*
 * Return string representation of date with month changed
 * Ex. aDate = "02/15/2018"
 *     aMonth = 5
 * Returns : "05/15/2018"
 */
std::string SFTestHarness::setMonthDateTest(std::string aDate, int aMonth) {
  return 0;
}

/*
 * Return integer representation of the day of the week for the given date
 * Ex. aDate = "02/15/2018"
 * Returns : 4
 */
int SFTestHarness::getDayOfWeekDateTest(std::string aDate) {
  return 0;
}

/*
 * Return string representation of date at the end of month of the given date
 * Ex. aDate = "03/15/2018"
 * Returns : "03/31/2018"
 */
std::string SFTestHarness::endOfMonthDateTest(std::string aDate) {
  return 0;
}

/*
 * Return string representation of interval between two times
 * Ex. aTime1 = "09:05:15"
 *     aTime2 = "09:05:22"
 * Returns : "0 years, 0 months, 0 days, 0 hours, 0 minutes and 7 seconds"
 */
std::string SFTestHarness::timeDifferenceTest(std::string aTime1, std::string aTime2) {
  return 0;
}

/*
 * Return string representation of interval between two times
 * Ex. aTime1 = "09:05:15"
 *     aMinutes = 5
 * Returns : "09:10:15"
 */
std::string SFTestHarness::adjustTimeByMinutesTest(std::string aTime1, int aMinutes) {
  return 0;
}

/*
 * Return minutes from the given time
 * Ex. aTime = "09:05:15"
 * Returns : 5
 */
int SFTestHarness::getMinutesTimeTest(std::string aTime) {
  return 0;
}

/*
 * Return string representation of interval between two times
 * Ex. aDateTime1 = "02/15/2018 09:05:15"
 *     aTimeZone1 = "PST"
 *     aDateTime2 = "02/15/2018 11:05:15"
 *     aTimeZone2 = "EST"
 * Returns : "0 years, 0 months, 0 days, 1 hours, 0 minutes and 0 seconds"
 */
std::string SFTestHarness::dataTimeDifferenceTest(std::string aDateTime1, std::string aTimezone1, std::string aDateTime2, std::string aTimezone2) {
  
  SFTimezone * zone1 = new SFTimezone(aTimezone1.c_str());
  SFTimezone * zone2 = new SFTimezone(aTimezone2.c_str());
  SFDateTime dt1 = SFDateTime(aDateTime1.c_str(), zone1);
  SFDateTime dt2 = SFDateTime(aDateTime2.c_str(), zone2);
  SFInterval res = dt1-dt2;
  std::string res_str = (const char*)res;
  return res_str;
}

/*
 * Return string representation of given date-time
 * Ex. aDateTime = "02/15/2018 09:05:15"
 *     aTimeZone = "PST"
 * Returns : "Feb 15, 2018 09:05:15 PST"
 */
std::string SFTestHarness::dataTimeToStringTest(std::string aDateTime, std::string timezone) {
  return 0;
}

/*
 * Return string representation of given GMT date-time converted to given timezone
 * Ex. aDateTime = "02/15/2018 09:05:15"
 *     aTimeZone = "PST"
 * Returns : "Feb 15, 2018 01:05:15 PST"
 */
std::string SFTestHarness::timezoneConversionDateTimeTest(std::string aDateTime, std::string timezone) {
  return 0;
}

/*
 * Return true if aDateTime1 is stricty greater than aDateTime2
 * Ex. aDateTime1 = "02/15/2018 09:05:15"
 *     aTimeZone1 = "PST"
 *     aDateTime2 = "02/15/2018 11:05:15"
 *     aTimeZone2 = "EST"
 * Returns : true
 */
bool SFTestHarness::greaterThanDateTimeTest(std::string aDateTime1, std::string aTimezone1, std::string aDateTime2, std::string aTimezone2) {
  
  
  return false;
}

int SFTestHarness::runAllTests() {
  int theResult = runDateTests();
  theResult+=runTimeTests();
  theResult+=runDateTimeTests();
  theResult+=runIntervalTests();
  theResult+=runTimezoneTests();
  return theResult;
}
