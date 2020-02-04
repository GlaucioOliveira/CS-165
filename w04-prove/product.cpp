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

void setFixedPoint()
{
     cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);   
}

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
    setFixedPoint();
    cout << name << " - " << "$" << price << endl;
    cout << "(" << description << ")" << endl;
}
void Product::displayInventory()
{
    //$5.99 - Dry Erase Markers - 0.5 lbs
    setFixedPoint();
    cout << "$" << price << " - " << name << " - " << weight << " lbs\n";
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
   setFixedPoint();
   
   cout << name << endl;
   cout << "  Price: " << setw(11) << "$" << setw(8) << price << endl;
   cout << "  Sales tax: " << setw(7) << "$" << setw(8) << price << endl;
   cout << "  Shipping cost: " << setw(3) << "$" << setw(8) << price << endl;
   cout << "  Total: " << setw(11) << "$" << setw(8) << price << endl;
}
