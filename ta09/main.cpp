/**********************************************************************
 * File: main.cpp
 * Author: Gláucio Oliveira
 *
 * Description: 
 * 
 **********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalaryEmployee.h"

using namespace std;

/***********************************************************************
 * Function: main
 * Description: 
 ***********************************************************************/
int main()
{
   vector<Employee*> employees;// = new vector<Employee>;

   char letter;
   int count = 0;

   do
   {
      cout << "Please enter 'h' for hourly employee, 's' for salary employee, or 'q' to quit: ";
      cin >> letter;

      if(cin.fail()) cin.clear();

      cin.ignore(256, '\n');

      if (letter == 'h')
      {
         
         string name;
         int hourlyRate = 0;
         int hours = 0;

         cout << "Enter the name: ";
         getline(cin, name);

         cout << "Enter the Hourly Rate: ";
         cin >> hourlyRate;

         cout << "Enter the hours: ";
         cin >> hours;
         HourlyEmployee * hourlyEmployee = new HourlyEmployee();

         hourlyEmployee->setName(name);
         hourlyEmployee->setHourlyWage(hourlyRate);
         hourlyEmployee->setHour(hours);


         //employees[count] = hourlyEmployee;
         employees.push_back(hourlyEmployee);
         //count++; 
      }
      else if (letter == 's')
      {
         string name;
         int salary = 0;
         cout << "Enter the name: ";
         getline(cin, name);

         cout << "Enter the salary: ";
         cin >> salary;

         SalaryEmployee * salaryEmployee = new SalaryEmployee();

         salaryEmployee->setName(name);
         salaryEmployee->setSalary(salary);

         //employees[count] = salaryEmployee;
         //count++;
         employees.push_back(salaryEmployee);
      }

   } while (letter != 'q');

   
   // Now we will display each employee
   for (int i = 0; i < employees.size(); i++)
   {
      employees[i]->display();
   }

 	return 0;
}


