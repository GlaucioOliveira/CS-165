#pragma once
#include <string>
#include <iostream>

using namespace std;

class Employee
{
public:
   void setName(string name);
   string getName() const;
   virtual void display();
   virtual float getPayCheck();
private:
   string name;

};

