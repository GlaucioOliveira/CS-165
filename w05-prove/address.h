// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;


class Address
{
private:
   string street;
   string address;
   string city;
   string state;
   string zip;

public:

   Address() {
      street = "unkown";
      address = "";
      city = "";
      state = "";
      zip = "00000";

   }

   Address(string pStreet, string pCity, string pState, string pZip) {
      street = pStreet;
      city = pCity;
      state = pState;
      zip = pZip;
   }

   string getStreet();
   void setStreet(string pStreet);

   string getCity();
   void setCity(string pCity);

   string getState();
   void setState(string pState);

   string getZip();
   void setZip(string pZip);

   void display();

};
#endif
