/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

/**********************************************************************
 * prompt the user a date and display it into three formats
 ***********************************************************************/
int main()
{
   int day;
   int month;
   int year;

   cout << "Month: ";
   cin >> month;

   cout << "Day: ";
   cin >> day;

   cout << "Year: ";
   cin >> year;

   Date date;

   date.set(day, month, year);
   
   cout << endl;

   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
