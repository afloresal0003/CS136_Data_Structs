/*
  Anthony Flores-Alvarez
  CS 136: Intro to Data Structures
  March 3, 2021
  
  Driver program to test the dateType

*/

// For program functionality
#include "dateType.cpp"
#include <iostream>

using namespace std;

// MAIN Function
int main(){

   // Initialize required variables
   int userMonth, 
       userDay, 
       userYear;

   // HEADER
   cout << "---------------------------------------" << endl;
   cout << "Please enter integer values for each" << endl;
   cout << "---------------------------------------\n" << endl;

   // INPUTS
   cout << "Enter month: ";
   cin >> userMonth;

   cout << "Enter day: ";
   cin >> userDay;

   cout << "Enter year: ";
   cin >> userYear;

   // Create date instance with given date
   dateType date(userMonth, userDay, userYear);

   // OUTPUTS
   cout << "\n---------------------------------------" << endl;
   date.printDate();

   if(date.testLeapYear(userYear)){
            cout << "\n" << userYear << " is a leap year." << endl;
   }
   else{
            cout<< "\n" << userYear << " is not a leap year." << endl;
   }

   cout << "Number of days in month: " << date.setMonth(userMonth) << endl;
   cout << "Number of days that passed: " << date.getNumDaysPasseed(userMonth, userDay) << endl;
   cout << "Number of days remaining: " << date.getNumDaysRemaining(userYear) << endl;
   cout << "\n---------------------------------------" << endl;

   // Successfully terminates program
   return 0;

}