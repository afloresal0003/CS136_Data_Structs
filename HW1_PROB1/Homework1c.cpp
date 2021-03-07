/*
  Anthony Flores-Alvarez
  CS 136: Intro to Data Structures
  February 25, 2021
  This program converts a given roman numeral
  to a decimal value. 

*/

// For program functionality
#include <iostream>
#include <string>

using namespace std;

// Class Declaration
class romanType{

  private:

    int DecimalNum;
    string RomanNum;

  public:
    
    // Constructor
    romanType(string = "");
    
    // Setter
    void setRomanType(string userRomNum){
      DecimalNum = 0;
      RomanNum = userRomNum;
    }

    // Converts roman numeral to decimal value
    void decimalConverter();

    // Outputs decimal value
    void decimalOutput(){
      cout << "\nDecimal Version: " << DecimalNum << "\n";
    }

    // Outputs roman numeral
    void romanOutput(){
      cout << "\nRomal Numeral Version: " << RomanNum << "\n";
    }
};

// Constructor definition
romanType::romanType(string userRomNum){
  DecimalNum = 0;
  RomanNum = userRomNum;
}

// Decimal conversion definition
void romanType::decimalConverter(){

  const int SIZE = 7;
  int decEquivalents[SIZE] = {1000, 500, 100,50, 10, 5, 1}, 
      romIndex, 
      temp;

  char rNumChars[SIZE] = {'M', 'D', 'C', 'L','X', 'V', 'I'};
 
  for (int i = 0; i < RomanNum.length() - 1; i++ ){

    // Finds index of user roman numeral in rNumChars
    for (romIndex = 0; romIndex < SIZE; romIndex++){
      
      if (RomanNum[i] == rNumChars[romIndex]){
        break;
      }
    }

    // Ensures index is in range
    if (romIndex < SIZE){

      // Determines successive roman numeral value
      for (temp = 0; temp < romIndex; temp++){

        if (RomanNum[i + 1] == rNumChars[temp]){

          break;
        }
      }

      if (temp == romIndex){
        DecimalNum += decEquivalents[romIndex];
      }

      else{
        DecimalNum -= decEquivalents[romIndex];
      }

    }

  }

  // Determines index of final roman numeral
  for (temp = 0; temp < SIZE; temp++){

    if (RomanNum[RomanNum.length() - 1] == rNumChars[temp]){

      break;
    }
  }

  // Stores decimal value of roman numeral, given index
  DecimalNum += decEquivalents[temp];

} 

// MAIN FUNCTION
int main(){

  romanType romObj;
  string userRomanNumeral;
  char userOutputChoice;

  // TITLE
  cout << "\nWelcome to Roman Numeral to Decimal Converter!\n\n";

  // INPUT
  cout << "Enter a Roman Numeral: ";
  cin >> userRomanNumeral;
  
  // Sets class variable with given user numeral
  romObj.setRomanType(userRomanNumeral);

  // Converts roman numeral to decimal value
  romObj.decimalConverter();

  // Ensures appropiate user choice
  while (true){

    // CHOICES
    cout << "\nWhat would you like?\n\n Enter 'R' for Roman Numeral version\n Enter 'D' for Decimal Number version\n\nChoice: ";
    cin >> userOutputChoice;

    // Prints Roman Numeral
    if (userOutputChoice == 'R' || userOutputChoice == 'r'){
      romObj.romanOutput();
      break;
    }

    // Prints Decimal Value
    else if (userOutputChoice == 'D' || userOutputChoice == 'd'){
      romObj.decimalOutput();
      break;
    }
    
    else{
      cout << "\nInvalid choice! Please try again: " << endl;
      
    }
  }

  // Successfully terminates program
  return 0;
}