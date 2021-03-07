/*
  Anthony Flores-Alvarez
  CS 136: Intro to Data Structures
  March 5, 2021
  
  Header file for extDateType class

*/

//Define the header
//file extDateType.h.
#include "dateType.h"
#include <string>
#pragma once
#ifndef EXTDATETYPE_H
#define EXTDATETYPE_H

using namespace std;

// Class declaration
class extDateType:public dateType{

   private:

      // Stores user month as string
      // 1) Add a data member to the class extDateType so that the month can also be stored in string form.
      string userMonthString;

   public:

      // Constructor
      extDateType(int userMonth = 0, int userDay = 0, int userYear = 0);

      // Overrides setMonth() function.
      int setMonth(int userMonth);

      // Prints date in Month Day, Year format
      // 2) Add a function member to output the month in the string format followed by the year
      void printNewFormat();
      
      // Prompts user to select type of date print formatting
      void printMenu();

};

#endif EXTDATETYPE_H