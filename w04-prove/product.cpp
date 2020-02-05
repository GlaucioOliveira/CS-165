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
	cout.precision(1);
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
	//setFixedPoint();
	cout << name << " - " << "$" << price << endl;
	cout << "(" << description << ")" << endl;
}
void Product::displayInventory()
{
	//$5.99 - Dry Erase Markers - 0.5 lbs
	cout.precision(2);
	cout << "$" << price << " - " << name << " - ";

	cout.precision(1);
	cout << weight << " lbs\n";
}

double Product::getSalesTaxes() {
	return price * 0.06;
}

double Product::getShippingCost() {
	//Create a getShippingCost method that returns a flat rate of $2.00 
	//if the item is less than 5 lbs, and $2.00 + $0.10 per pound over 5 lbs.
	if (weight < 5)
	{
		return 2.0;
	}
	else
	{
		return 2.0 + ((weight - 5) * 0.10);
	}
}

double Product::getTotalPrice() {
	//Create a getTotalPrice method that uses your other methods to return a total price.
	return price + getSalesTaxes() + getShippingCost();
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
	//setFixedPoint();

	cout << name << endl;
	cout << "  Price:" << setw(10) << "$" << setw(8) << price << endl;
	cout << "  Sales tax:" << setw(6) << "$" << setw(8) << getSalesTaxes() << endl;
	cout << "  Shipping cost:" << setw(2) << "$" << setw(8) << getShippingCost() << endl;
	cout << "  Total:" << setw(10) << "$" << setw(8) << getTotalPrice() << endl;
}