/***************************************************************
 * File: assign04.cpp
 * Author: Gláucio Oliveira
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
#include "product.h"

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    Product product;

   product.prompt();

   /* product.name = "Finding Peace, Happiness, and Joy by Richard G. Scott";
    product.description = "Elder Scott powerfully outlines the truths we need to understand and embrace in order to experience the gifts of peace, happiness, and joy.";
    product.price = 14.49;
    product.weight = 1.5;*/

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