/****************
 * smartphone.h
 ****************/
#include "phone.h"
#include <string>

using namespace std;

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

// TODO: Put your SmartPhone definition here
class SmartPhone : public Phone
{
public:
   void prompt();
   void display();

private:
   string email;
};

#endif
