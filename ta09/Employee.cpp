#include "Employee.h"

void Employee::setName(string name)
{
   this->name = name;
}

string Employee::getName() const
{
   return this->name;
}

void Employee::display()
{
   cout << this->name << endl;
}

float Employee::getPayCheck()
{
   return 0.0f;
}
