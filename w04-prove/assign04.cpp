/***************************************************************
 * File: assign04.cpp
 * Author: (your name here)
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "product.h"



int main()
{
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

    Product p;

   p.prompt();
 
   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   if (choice == 1)
   {
      p.displayAdvertising();
   }
   else if (choice == 2)
   {
      p.displayInventory();
   }
   else
   {
      p.displayReceipt();
   }

   return 0;
}
