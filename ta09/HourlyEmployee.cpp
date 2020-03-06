#include "HourlyEmployee.h"

void HourlyEmployee::setHourlyWage(int hourlyWage)
{
   this->hourlyWage = hourlyWage;
}

int HourlyEmployee::getHourlyWage() const
{
   return this->hourlyWage;
}

void HourlyEmployee::setHour(int hour)
{
   this->hour = hour;
}

int HourlyEmployee::getHour() const
{
   return this->hour;
}

void HourlyEmployee::display()
{
   cout << this->getName() << " - $" << this->getHourlyWage() << "/hour - payCheck - " << this->getPayCheck() << endl;
}


float HourlyEmployee::getPayCheck()
{
   return this->getHour() * this->getHourlyWage();
}
