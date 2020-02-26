/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include <iostream>

void SmartPhone::prompt()
{
   promptNumber();

   cin.ignore();

   cout << "Email: ";
   getline(cin, email);
}

void SmartPhone::display()
{
   Phone::display();
   cout << endl << email;
}
