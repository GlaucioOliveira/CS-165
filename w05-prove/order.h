// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;

#include "product.h"
#include "customer.h"

class Order
{
private:
   Product product;
   int quantity;
   Customer customer;

public:
   Order()
   {
      quantity = 0;
      product = Product();
      customer = Customer();
   }

   Order(Product pProduct, int pQuantity, Customer pCustomer)
   {
      product = pProduct;
      quantity = pQuantity;
      customer = pCustomer;
   }

   Product getProduct();
   void setProduct(Product pProduct);

   int getQuantity();
   void setQuantity(int pQuantity);

   Customer getCustomer();
   void setCustomer(Customer pCustomer);

   string getShippingZip();

   double getTotalPrice();

   void displayShippingLabel();

   void displayInformation();

};
#endif
