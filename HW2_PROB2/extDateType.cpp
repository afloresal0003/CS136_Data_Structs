/*
  Anthony Flores-Alvarez
  CS 136: Intro to Data Structures
  March 5, 2021
  
   CPP File for extDateType class
   
*/

// For program functionality
#include "dateType.h"
#include "extDateType.h"
#include <iostream>
#include <string>

using namespace std;

// CLASS METHOD DECLARATIONS
// 3) Write the definitions of the functions to implement the operations for the class extDateType.

// Constructor
extDateType::extDateType(int userMonth, int userDay, int userYear):dateType(userMonth, userDay, userYear){

   // Default month
   userMonthString = "Invalid Month";

   // Sets month according to case number
   switch (userMonth){

      case 1:
            userMonthString = "January";
            break;

      case 2:
            userMonthString = "February";
            break;

      case 3:
            userMonthString = "March";
            break;

      case 4:
            userMonthString = "April";
            break;

      case 5:
            userMonthString = "May";
            break;

      case 6:
            userMonthString = "June";
            break;

      case 7:
            userMonthString = "July";
            break;

      case 8:
            userMonthString = "August";
            break;

      case 9:
            userMonthString = "September";
            break;

      case 10:
            userMonthString = "October";
            break;

      case 11:
            userMonthString = "November";
            break;

      case 12:
            userMonthString = "December";
            break;
    }
}

int extDateType::setMonth(int userMonth){

   // Default month
   userMonthString = "Invalid Month";

   // Sets month according to case number
   switch (userMonth){

      case 1:
         userMonthString = "January";
         break;

      case 2:
         userMonthString = "February";
         break;

      case 3:
         userMonthString = "March";
         break;

      case 4:
         userMonthString = "April";
         break;

      case 5:
         userMonthString = "May";
         break;

      case 6:
         userMonthString = "June";
         break;

      case 7:
         userMonthString = "July";
         break;

      case 8:
         userMonthString = "August";
         break;

      case 9:
         userMonthString = "September";
         break;

      case 10:
         userMonthString = "October";
         break;

      case 11:
         userMonthString = "November";
         break;

      case 12:
         userMonthString = "December";
         break;

   }

   // Returns days in month by calling setMonth() of super class
   return dateType::setMonth(userMonth);

}

void extDateType::printNewFormat(){

   cout << "\n---------------------------------------" << endl;
   cout << "\nYour Date: " << userMonthString << " " << getDay() << ", " << getYear() << endl;
}

void extDateType::printMenu(){

   int userOption;

   // PROMPT
   cout << "\nHow would you like to print the date?: " << endl;
   cout << "1) MM/DD/YYYY " << endl;
   cout << "2) Month Day, Year" << endl;
   cout << "\nEnter 1 or 2 only: ";
   cin >> userOption;

   // Error catching
   while (userOption>2 || userOption<1){

      cout << "\nPlease choose a valid format: " << endl;
      cout << "1) MM/DD/YYYY " << endl;
      cout << "2) Month Day, Year" << endl;
      cout << "\nEnter 1 or 2 only: ";
      cin >> userOption;

   }

   // MM/DD/YYYY FORMAT
   if (userOption == 1){
      printDate();
   }

   // Month Day, Year FORMAT
   else{
      printNewFormat();
   }
}