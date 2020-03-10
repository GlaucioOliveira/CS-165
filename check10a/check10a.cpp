/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Walker, CS165
* Author:
*    Glaucio Oliveira
* Summary:
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   bool leaveMenu = false;
   vector <int> intList;
   vector <string> stringList;

   int intValue = 0;
   string stringValue = "";

   while (leaveMenu == false)
   {
      cout << "Enter int: ";
      cin >> intValue;

      if (cin.fail() == false)
      {
         if (intValue > 0)
            intList.push_back(intValue);
         else
            leaveMenu = true;
      }
      else
      {  
         cin.ignore();
      }
   }

   cout << "Your list is:\n";

   for (int i = 0; i < intList.size(); i++)
   {
      cout << intList[i] << endl;
   }

   // Processing Strings
   leaveMenu = false;
   cin.ignore();
   cout << endl;

   while (leaveMenu == false)
   {
      cout << "Enter string: ";
      getline(cin, stringValue);

      if (cin.fail() == false)
      {
         if (stringValue != "quit")
            stringList.push_back(stringValue);
         else
            leaveMenu = true;
      }
      else
      {
         cin.ignore();
      }
   }

   cout << "Your list is:\n";

   for (int i = 0; i < stringList.size(); i++)
   {
      cout << stringList[i] << endl;
   }
   return 0;
}


