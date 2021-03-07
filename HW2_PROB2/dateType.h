/*
  Anthony Flores-Alvarez
  CS 136: Intro to Data Structures
  March 5, 2021
  
  Header file for dateType class

*/

// For program functionality
#ifndef DATATYPE_H
#define DATATYPE_H

// Class declaration 
class dateType{

   private:

      int _month; //variable to store the month
      int _day; //variable to store the day
      int _year;//variable to store the year
      int _numDays;
      int _daysPassed;

   public:

      // Sets the month as that given by the user
      // and returns the days in that month 
      int setMonth(int userMonth);

      // Sets the day as that given by the user
      void setDay(int userDay);

      // Sets the year as that given by the user
      void setYear(int userYear);

      // Returns the day
      int getDay() const;

      // Returns the month
      int getMonth() const;

      // Returns the year
      int getYear() const;

      // Prints the date in mm-dd-yy form
      void printDate() const;

      // Constructor: Sets the date with parameters
      // If no values are given, uses default values
      dateType(int month = 1, int day = 31, int year = 2020);

      // Tests whether the year is a leap year
      bool testLeapYear(int year);

      // Returns the number of days that have passed
      int getNumDaysPasseed(int, int);

      // Returns the remaining days
      int getNumDaysRemaining(int);

};

#endif DATATYPE_H