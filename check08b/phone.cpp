/*********************
 * phone.cpp
 *********************/
#include <iostream>
#include "phone.h"

using namespace std;

void Phone::promptNumber()
{
   cout << "Area Code: ";
   cin >> areaCode;

   cout << "Prefix: ";
   cin >> prefix;

   cout << "Suffix: ";
   cin >> suffix;

}

void Phone::display()
{
   cout << "(" << areaCode << ")" << prefix << "-" << suffix << endl;
}
