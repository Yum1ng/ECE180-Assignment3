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
  return 0;
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
