#include<iostream>

#include<cmath>

// define the name space of the program

using namespace std;

//class declaration

class dayType

{

public: int presday;

              int prevday;

              int nextday;

              dayType()

              {

                      presday = 0;

                      nextday = 0;

                      prevday = 0;

              }

              void set(int day); //function declarations

              void print(int day);

              int Next_day(int day);

              int day();

              int prev_day(int pres);

};

void dayType::set(int day) //member functions

{

       presday = day;

}

/* modify here*/

int dayType::prev_day(int day)

{

       // here change from absolute to simple

       prevday = presday - day;// =abs(presday-day);

       // than check the condtion

       if (prevday<0)prevday += 7;

       // then return previous day

       return prevday;

}

int dayType::day()

{

       return presday;

}

int dayType::Next_day(int day)

{

       nextday = presday + day;

       if (nextday>7)

       {

              nextday = nextday % 7;

       }

       return nextday;

}

void dayType::print(int d)

{

       if (d == 1)

              cout << "Monday" << endl;

       if (d == 2)

              cout << "Tuesday" << endl;

       if (d == 3)

              cout << "Wednesday" << endl;

       if (d == 4)

              cout << "Thursday" << endl;

       if (d == 5)

              cout << "Friday" << endl;

       if (d == 6)

              cout << "Saturday" << endl;

       if (d == 7)

              cout << "Sunday" << endl;

}

/* here modify change void to int type */

int main()

{

       int d, p, n;

       dayType obj;

       cout << "1-Mon" << endl << "2-Tue" << endl << "3-Wed" << endl << "4-Thur" << endl << "5-Fri" << endl << "6-Sat" << endl << "7-sun" << endl;

       cout << "Enter Day";

       cin >> d;

       obj.set(d);

       cout << "Present day is";

       obj.print(d);

       cout << "Enter number of days next";

       cin >> d;

       n = obj.Next_day(d);

       cout << "Next day is";

       obj.print(n);

       cout << "Enter number of days previous";

       cin >> d;

       p = obj.prev_day(d);

       cout << "previous day is";

       obj.print(p);

       system("Pause");// require only in visual studio

       // return zero

       return 0;

}