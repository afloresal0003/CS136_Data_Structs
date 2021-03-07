/*
  Anthony Flores-Alvarez
  CS 136: Intro to Data Structures
  March 5, 2021
  
  // CPP File for dateType class | 
  // Method declarations

*/

// For program functionality
#include "dateType.h"
#include <iostream>

using namespace std;

// 1) set the month
int dateType::setMonth(int userMonth){

   int userYear;
   
   userYear = _year;

   if (userMonth <= 12){

      _month = userMonth;

      switch (userMonth){

         case 1:

         case 3:

         case 5:

         case 7:

         case 8:

         case 10:

         case 12: 

            _numDays = 31;
            break;

         case 4:

         case 6:

         case 9:

         case 11:

            _numDays = 30;
            break;

         case 2:
            if (testLeapYear(userYear)){
               _numDays = 29;
            }

            else{
               _numDays = 28;
            }

      }

   }

   else{
      cout << "Error! Invalid month. Please try again" << endl;
      _month = 0;
   }

   // 7) return the number of days in the month
   return _numDays;

}

// 2) set the day
void dateType::setDay(int userDay){

   if (userDay <= _numDays){
      _day = userDay;   
   }

   else{
      cout << "Error! Invalid day. Please try again!" << endl;
      _day = 0;
   }
}

void dateType::setYear(int userYear){
   _year = userYear; // 3) set the year
}

int dateType::getDay() const{

   return _day; 
}

int dateType::getMonth() const{

   return _month; // 4) return the month
}

int dateType::getYear() const{

   return _year; // 5) return the year
}

//print the date as DD/MM/YYYY
void dateType::printDate()const{

   cout << "\nYour Date: " << _month << "/" << _day << "/" << _year << endl;
}

//Constructor with parameters
dateType::dateType(int userMonth, int userDay, int userYear){

   _month = userMonth;
   _day = userDay;
   _year = userYear;

}

bool dateType::testLeapYear(int userYear){

   return userYear % 4 == 0; // 6) test whether the year is a leap year
}

int dateType::getNumDaysPasseed(int userMonth, int userDay){

   int prevMonths, 
      daysPassed = 0;

   for (prevMonths = 1; prevMonths < userMonth; prevMonths++){

      if (prevMonths == userMonth){
         _numDays = _numDays + 1;
      }

      else{
         daysPassed += setMonth(prevMonths);
      }

   }

   daysPassed += userDay;
   _daysPassed = daysPassed;

   // 8) return the days passed in the year.
   return daysPassed;
}

int dateType::getNumDaysRemaining(int userYear){

   int daysRemaining;

   if (testLeapYear(userYear)){
      daysRemaining = 366 - _daysPassed;
   }

   else{
      daysRemaining = 365 - _daysPassed;
   }

   // 9) return the number of days remaining in the year.
   return daysRemaining;
}