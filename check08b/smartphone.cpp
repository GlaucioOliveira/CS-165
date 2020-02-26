/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include <iostream>

void SmartPhone::prompt()
{
   promptNumber();
}

void SmartPhone::display()
{
   Phone::display();
   cout << "Email: " << email;
}
