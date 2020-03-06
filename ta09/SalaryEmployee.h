#pragma once
#include "Employee.h"
class SalaryEmployee :
   public Employee
{
public:
   int getSalary() const;
   void setSalary(int salary);
   virtual void display();
   virtual float getPayCheck();

private:
   int salary;
};

