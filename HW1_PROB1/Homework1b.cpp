/*
  Anthony Flores-Alvarez
  LACC CS 136: Intro to Data Structures
  Homework #1 Problem 1
  February 25, 2021
*/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
const static int M = 1000;
const static int D = 500;
const static int C = 100;
const static int L = 50;
const static int X = 10;
const static int V = 5;
const static int I = 1;
class RomanNumeral
{
    public:
        RomanNumeral( const int decimal ) :
        m_roman( "" ),
        m_decimal( ((decimal > 0) ? decimal : 0) ){

            if( decimal > 0 ){

                int i = decimal;
                while( i > 0 ){

                    if( ( i - M ) >= 0 ){

                        m_roman += "M";
                        i -= M;
                        continue;
                    }
                    if( ( i - D ) >= 0 ){

                        m_roman += "D";
                        i -= D;
                        continue;
                    }
                    if( ( i - C ) >= 0 ){

                        m_roman += "C";
                        i -= C;
                        continue;
                    }

                    if( ( i - L ) >= 0 ){

                        m_roman += "L";
                        i -= L;
                        continue;
                    }

                    if( ( i - X ) >= 0 ){

                        m_roman += "X";
                        i -= X;
                        continue;
                    }

                    if( ( i - V ) >= 0 ){

                        m_roman += "V";
                        i -= V;
                        continue;
                    }

                    if( ( i - I ) >= 0 ){

                        m_roman += "I";
                        i -= I;
                        continue;
                    }
                }
            }
            else{
                m_roman = "0";
            }
        }

        RomanNumeral( const std::string& string ) :
        m_roman( ((string.size() > 0 ) ? string : "0" ) ),
        m_decimal( 0 ){

            int i = 0;
            while( i < (int)string.size() ){

                char c = string[i++];
                switch( c ){

                    case 'M':
                    case 'm':
                    m_decimal += M;
                    break;

                    case 'D':
                    case 'd':
                    m_decimal += D;
                    break;

                    case 'C':
                    case 'c':
                    m_decimal += C;
                    break;

                    case 'L':
                    case 'l':
                    m_decimal += L;
                    break;

                    case 'X':
                    case 'x':
                    m_decimal += X;
                    break;

                    case 'V':
                    case 'v':
                    m_decimal += V;
                    break;

                    case 'I':
                    case 'i':
                    m_decimal += I;
                    break;

                    default:
                        throw new std::out_of_range( "Not a valid Roman numeral!" );
                        break;
                }
            }
        }

        int getDecimal(){
            return m_decimal;
        }

        void setDecimal( const int decimal );

        const std::string& getRoman(){
            return m_roman;
        }
    protected:
        std::string m_roman;
        int m_decimal;
};

int main(){
    cout << "Welcome to the Roman numeral to decimal converter!\nPlease enter a number in Roman numerals to be converted: ";

    std::string roman;
    cin >> roman;
    try{
        RomanNumeral rn( roman );
        cout << "Roman Numeral: " << roman << " Decimal: " << rn.getDecimal() << endl;
    }
    catch( exception* ex ){
        cout << roman << " " << ex->what() << endl;
    }

    cout << "Now enter a decimal number to be converted to Roman numerals: ";
    int decimal;
    cin >> decimal;
    try{
    RomanNumeral rn( decimal );
    cout << "Decimal number: " << decimal << " Roman: " << rn.getRoman() << endl;
    }
    catch( ... ){
    cout << "error during processing...too bad, I'm outta here!" << endl;
    }

    return 0;
}