/***************************************************************
 * File: product.cpp
 * Author: Glaucio Oliveira
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

/**********************************************************************
 * set float numbers precision.
 ***********************************************************************/
void setFixedPoint(int precision)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(precision);
}

/**********************************************************************
 * prompt the user for the name, description, weight and price of a 
 * product.
 ***********************************************************************/
void Product::prompt()
{
   cout << "Enter name: ";
   getline(cin, name);

   cout << "Enter description: ";
   getline(cin, description);

   cout << "Enter weight: ";
   cin >> weight;

   bool validPrice = false;
   while (!validPrice)
   {
      cout << "Enter price: ";
      cin >> price;
      
      if (!cin.fail() && price >= 0)
      {
         validPrice = true;
      }

      cin.clear();
      cin.ignore(256, '\n');
   }
   
}

/**********************************************************************
 * Display the product in an advertising description.
 ***********************************************************************/
void Product::displayAdvertising()
{
   setFixedPoint(2);
   cout << name << " - " << "$" << price << endl;
   cout << "(" << description << ")" << endl;
}


/**********************************************************************
 * Display the product in an inventory description.
 ***********************************************************************/
void Product::displayInventory()
{
   cout.precision(2);
   cout << "$" << price << " - " << name << " - ";

   cout.precision(1);
   cout << weight << " lbs\n";
}


/**********************************************************************
 * return the Sales Taxes (6% of the price)
 ***********************************************************************/
double Product::getSalesTaxes()
{
   return price * 0.06;
}


/**********************************************************************
 * Returns the shipping cost
 ***********************************************************************/
double Product::getShippingCost()
{
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


/**********************************************************************
 * get the total price (price + sales taxes + shipping cost).
 ***********************************************************************/
double Product::getTotalPrice()
{
   //Create a getTotalPrice method that uses your other methods to return a total price.
   return price + getSalesTaxes() + getShippingCost();
}


/**********************************************************************
 * Display the product in an receipt description.
 ***********************************************************************/
void Product::displayReceipt()
{
   setFixedPoint(2);

   cout << name << endl;
   cout << "  Price:" << setw(10) << "$" << setw(8) << price << endl;
   cout << "  Sales tax:" << setw(6) << "$" << setw(8) << getSalesTaxes() << endl;
   cout << "  Shipping cost:" << setw(2) << "$" << setw(8) << getShippingCost() << endl;
   cout << "  Total:" << setw(10) << "$" << setw(8) << getTotalPrice() << endl;
}

string Product::getName()
{
   return name;
}

void Product::setName(string pName)
{
   name = pName;
}

string Product::getDescription()
{
   return description;
}

void Product::setDescription(string pDescription)
{
   description = pDescription;
}

double Product::getBasePrice()
{
   return price;
}

void Product::setBasePrice(double pPrice)
{
   price = pPrice;
}

double Product::getWeight()
{
   return weight;
}

void Product::setWeight(double pWeight)
{
   weight = pWeight;
}
