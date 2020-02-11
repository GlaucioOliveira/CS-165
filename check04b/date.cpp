/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include "date.h"
#include <string>
#include <iomanip>
#include <iostream>


using namespace std;

/**********************************************************************
 * set the variables day, month and year
 ***********************************************************************/
void Date::set(int pDay, int pMonth, int pYear)
{
   day = pDay;
   month = pMonth;
   year = pYear;
}

/**********************************************************************
 * display a date in American format.
 ***********************************************************************/
void Date::displayAmerican() 
{
   cout << month << "/" << day << "/" << year << endl;
}

/**********************************************************************
 * display a date in European format.
 ***********************************************************************/
void Date::displayEuropean() 
{
   cout << day << "/" << month << "/" << year << endl;
}

/**********************************************************************
 * display a date in ISO format.
 ***********************************************************************/
void Date::displayISO() 
{
   cout << year << "-" << month << "-" << day << endl;
}