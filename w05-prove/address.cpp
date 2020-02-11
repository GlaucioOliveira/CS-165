// File: address.cpp
#include <iostream>
#include "address.h"

string Address::getStreet()
{
return street;
}
void Address::setStreet(string pStreet)
{
   street = pStreet;
}

string Address::getCity()
{
   return city;
}
void Address::setCity(string pCity)
{
   city = pCity;
}

string Address::getState()
{
   return state;
}
void Address::setState(string pState)
{
   state = pState;
}

string Address::getZip()
{
   return zip;
}

void Address::setZip(string pZip)
{
   zip = pZip;
}

void Address::display()
{
   cout << street << endl;
   cout << city << ", " << state << " " << zip;
   cout << endl;
}