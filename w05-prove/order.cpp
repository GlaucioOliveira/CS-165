// File: order.cpp

#include "order.h"
#include <iostream>

// Put your the method bodies for your order class here

Product Order::getProduct()
{
   return product;
}

void Order::setProduct(Product pProduct)
{
product = pProduct;
}

int Order::getQuantity()
{
   return quantity;
}

void Order::setQuantity(int pQuantity)
{
   quantity = pQuantity;
}

Customer Order::getCustomer()
{
   return customer;
}

void Order::setCustomer(Customer pCustomer)
{
   customer = pCustomer;
}

string Order::getShippingZip()
{
   return customer.getAddress().getZip();
}

double Order::getTotalPrice()
{
   return product.getTotalPrice() * getQuantity();
}

void Order::displayShippingLabel()
{
   customer.display();
}

void Order::displayInformation()
{
   cout << customer.getName() << endl;
   cout << product.getName() << endl;
   cout << "Total Price: " << getTotalPrice();
   cout << endl;
}
