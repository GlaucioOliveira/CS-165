/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

Money::Money()
{
   setDollars(0);
   setCents(0);
}

Money::Money(double dollars)
{
   setDollars(dollars);
   setCents(0);
}

Money::Money(double dollars, double cents)
{
   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money::prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}


/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money::display() const
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}

/*****************************************************************
 * Function: getDollars
 * Purpose: return the value of the dollars.
 ****************************************************************/
double Money::getDollars() const
{
   return dollars;
}

/*****************************************************************
 * Function: setDollars
 * Purpose: Set dollars value (if the value is negative, convert
 * it to a positive number)
 ****************************************************************/
void Money::setDollars(double pDollars)
{
   if (pDollars < 0)
   {
      pDollars *= -1;
   }

   dollars = pDollars;
}

/*****************************************************************
 * Function: getCents
 * Purpose: return the value of cents.
 ****************************************************************/
double Money::getCents() const
{
   return cents;
}

/*****************************************************************
 * Function: setCents
 * Purpose: Set cents value (if the value is negative, convert
 * it to a positive number).
 ****************************************************************/
void Money::setCents(double pCents)
{
   if (pCents < 0)
   {
      pCents *= -1;
   }

   cents = pCents;
}
