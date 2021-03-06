/*
  Anthony Flores-Alvarez
  CS 136: Intro to Data Structures
  February 27, 2021
  This program outputs the day of the week
  given the day of the week. It also outputs
  the day before and after. Lastly, given
  a certain number, it finds x days after.

*/

// For program functionality
#include <string>
#include <iostream>

using namespace std;

// Class declaration
class dayType {

    private:
        // Stores numerical value of user's day
        int numDay;
        // Stores user's day
        string Day;

    public:
        // Days of the Week
        static string daysInWeek[7];

        // Setter: Sets the day
        void setDayOfWeek(string userDay){

            // Sets/Stores string version of day
            Day = userDay;

            for(int dayIndex = 0; dayIndex < 7; dayIndex++){
                if(daysInWeek[dayIndex] == userDay){
                    // Sets/Stores index as numerical value
                    // of user's day
                    numDay = dayIndex;
                }

            }

        } 

        // Outputs the day
        void outputDayOfWeek() {
            cout << "\nCurrent Day: " << Day << endl;
            cout << "Numerical Value: " << numDay << endl;
        }

        // Returns the next day
        string getNextDay(){
            string nextDay;
            if(numDay == 6){
                nextDay = daysInWeek[0];
            }
            else{
                nextDay = daysInWeek[numDay + 1];
            }

            return nextDay; 
        }

        // Returns the previous day
        string getPrevDay(){
            string dayBefore;
            if(numDay == 0){
                dayBefore = daysInWeek[6];
            }
            else{
                dayBefore = daysInWeek[numDay - 1];
            }
            return  dayBefore; 
        }

        // Calculates and returns added days
        string calcAddedDays(int userAddDays){
            int userDayInt = numDay, 
                count = 0;
            
            // For subtracting days
            if (userAddDays < 0){
                while(count < (userAddDays * -1)){
                    // If Sunday
                    if(userDayInt == 0){
                        // Set to Saturday
                        userDayInt = 6;
                        count++;
                    }
                    else{
                        userDayInt--;
                        count++;
                    }
                }
            }

            // For adding days
            else{
                while(count < userAddDays){
                    // If Saturday
                    if(userDayInt == 6){
                        // Set to Sunday
                        userDayInt = 0;
                        count++;
                    }
                    else{
                        userDayInt++;
                        count++;
                    }
                }
            }
            return daysInWeek[userDayInt]; 

        }

        // Constructor
        dayType();
        dayType(string day); 

};

// Days of the week list
string dayType::daysInWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

dayType::dayType(){
        Day = "";
    }
dayType::dayType(string day_):Day(day_){
        Day = day_;
    }

// MAIN FUNCTION
int main(){

    dayType dayTypeObj;
    string userDay;
    int userAddDays;

    // TITLE
    cout << "\nWelcome to Day of the Week Tool!\n\n";

    // INPUT
    cout << "Enter the name of the day of the week you'd like: ";
    cin >> userDay;

    // Sets day
    dayTypeObj.setDayOfWeek(userDay);
    
    // Outputs day
    dayTypeObj.outputDayOfWeek();
    
    // Outputs next day
    cout << "\nNext Day: " << dayTypeObj.getNextDay() << endl;

    // Outputs previous day
    cout << "Previous Day: " << dayTypeObj.getPrevDay() << endl;

    // Asks for added days
    cout << "\nHow many days do you want to add (Enter negative number to subtract): ";
    cin >> userAddDays;

    // Outputs new day
    cout << "\n" << userAddDays << " days after " << userDay << " is " << dayTypeObj.calcAddedDays(userAddDays) << endl;
    cout << "\n";

    // Successfully terminates program
    return 0;
}