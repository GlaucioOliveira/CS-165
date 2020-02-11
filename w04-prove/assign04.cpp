/***************************************************************
 * File: assign04.cpp
 * Author: Glaucio Oliveira
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
#include "product.h"

using namespace std;

/**********************************************************************
 * prompt the user for information of a product and then 
 * display it to the user in the desired format.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   Product product;

   product.prompt();

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
      product.displayAdvertising();
   }
   else if (choice == 2)
   {
      product.displayInventory();
   }
   else
   {
      product.displayReceipt();
   }

   return 0;
}