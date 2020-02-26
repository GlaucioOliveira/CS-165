/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include <iostream>

void SmartPhone::prompt()
{
   promptNumber();

   cout << "Email: ";
   getline(cin, email);
}

void SmartPhone::display()
{
   Phone::display();
   cout << "Email: " << email;
}
