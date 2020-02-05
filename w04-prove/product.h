/***************************************************************
 * File: product.h
 * Author: Gláucio Oliveira
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;
// put your class definition here

class Product
{
private:


public:
    void prompt();
    double getSalesTaxes();
    double getShippingCost();
    double getTotalPrice();

    void displayAdvertising();
    void displayInventory();
    void displayReceipt();

    string name;
    double price;
    double weight;
    string description;

};

#endif