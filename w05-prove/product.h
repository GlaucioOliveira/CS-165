/***************************************************************
 * File: product.h
 * Author: Glaucio Oliveira
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;


class Product
{
private:
   string name;
   double price;
   double weight;
   string description;

public:

   Product()
   {
      name = "none";
      description = "";
      weight = 0;
      price = 0;
   }

   Product(string pName, string pDescription, double basePrice, double pWeight)
   {
      name = pName;
      description = pDescription;
      weight = pWeight;
      price = basePrice;
   }

   void prompt();
   double getSalesTaxes();
   double getShippingCost();
   double getTotalPrice();

   void displayAdvertising();
   void displayInventory();
   void displayReceipt();

   string getName();
   void setName(string pName);

   string getDescription();
   void setDescription(string pDescription);

   double getBasePrice();
   void setBasePrice(double pPrice);

   double getWeight();
   void setWeight(double pWeight);

};

#endif