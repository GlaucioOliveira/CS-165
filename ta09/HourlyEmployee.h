#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee
{
   public:
   void setHourlyWage(int hourlyWage);
   int getHourlyWage() const;

   void setHour(int hour);
   int getHour() const;

   virtual void display();
   virtual float getPayCheck();

   private:
   int hourlyWage;
   int hour;
};

