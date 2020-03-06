#include "SalaryEmployee.h"

int SalaryEmployee::getSalary() const
{
   return this->salary;
}

void SalaryEmployee::setSalary(int salary)
{
   this->salary = salary;
}

void SalaryEmployee::display()
{
   cout << this->getName() << " - " << this->getSalary() << "/year - paycheck - " << this->getPayCheck() << endl;
}

float SalaryEmployee::getPayCheck()
{
   return getSalary() / 24.0f;
}
