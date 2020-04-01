// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "address.h"

class Customer
{
private:
   string name;
   Address address;

public:
   Customer() {
      name = "unspecified";
      address = Address();
   }

   Customer(string pName, Address pAddress) {
      name = pName;
      address = pAddress;
   }

   string getName();
   void setName(string pName);

   Address getAddress();
   void setAddress(Address pAddress);

   void display();
};
#endif
