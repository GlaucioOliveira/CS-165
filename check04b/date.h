/********************************************************************
 * File: date.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;


class Date 
{
private:
   int day;
   int month;
   int year;

public:
   void set(int day, int month, int year);
   void displayAmerican();
   void displayEuropean();
   void displayISO();
};

#endif
