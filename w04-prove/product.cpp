/***************************************************************
 * File: product.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

void Product::prompt()
{
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter description: ";
    getline(cin, description);

    cout << "Enter weight: ";
    cin >> weight;


    cout << "Enter price: ";
    cin >> price;   
}

void Product::displayAdvertising()
{
    cout << name << " - " << "$" << price << endl;
    cout << "(" << description << ")";
}
void Product::displayInventory()
{
    //$5.99 - Dry Erase Markers - 0.5 lbs
    cout << "$" << price << " - " << name << " - " << weight;
}

void Product::displayReceipt()
{
    /*
    Enter name: Bowling Ball
Enter description: Knock 'em all down!
Enter weight: 14
Enter price: 40


    Bowling Ball
  Price:         $   40.00
  Sales tax:     $    2.40
  Shipping cost: $    2.90
  Total:         $   45.30
    */
   cout << name << endl;
   cout << "  Price: " << setw(10) << "$" << setw(8) << price << endl;
   cout << "  Sales Tax: " << setw(6) << "$" << setw(8) << price << endl;
   cout << "  Shipping cost: " << setw(2) << "$" << setw(8) << price << endl;
   cout << "  Total: " << setw(10) << "$" << setw(8) << price << endl;
}
