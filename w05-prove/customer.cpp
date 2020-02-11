// File: customer.cpp
#include <string>
#include <iostream>
using namespace std;

#include "customer.h"

string Customer::getName()
{
   return name;
}

void Customer::setName(string pName)
{
   name = pName;
}

Address Customer::getAddress()
{
   return address;
}

void Customer::setAddress(Address pAddress)
{
   address = pAddress;
}

void Customer::display()
{
   cout << name << endl;
   cout << address.getStreet() << endl;
   cout << address.getCity() << ", " << address.getState()
   << " " << address.getZip();
   cout << endl;
}