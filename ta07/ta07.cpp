#include <iostream>
using namespace std;

// Core requirements
float getValueFromPointer(float* thePointer)
{
   return *thePointer;
}

float* getMinValue(float* a, float* b)
{
   if (getValueFromPointer(a) < getValueFromPointer(b))
      return a;
   else
      return b;
}

// Stretch goals
void swapElements(float* theArray[], int a, int b);
void sortArray(float* theArray[]);

int main()
{
   //Core Requirement 1
   int arraySize;
   cout << "Enter the array size: ";
   cin >> arraySize;

   //dynamic creation of the float array list;
   float* arrayList = new float[arraySize];

   //prompting the user for each value of the array list;
   for (int i = 0; i < arraySize; i++)
   {
      cout << "Enter a float value: ";
      cin >> arrayList[i];
   }

   //Core Requirement 2
   for (int i = 0; i < arraySize; i++)
   {
      float value = getValueFromPointer(&arrayList[i]);
      cout << "The value of the element " << i << " is: ";
      cout << value << endl;
   }

   // Print the smaller of the first and last elements of the array
   float* pointerToMin = getMinValue(&arrayList[0], &arrayList[arraySize - 1]);
   cout << *pointerToMin;

   /* // Core Requirement 1
   int arraySize;
   cout << "Enter the array size: ";
   cin >> arraySize;

   // Allocate your array(s) here

   // Fill your array with float values
   for(int i = 0; i < arraySize; i++)
   {
          cout << "Enter a float value: ";
          cin >> ????
   }*/

   /* // Core Requirement 2
   for (int i = 0; i < arraySize; i++)
   {
      float value = getValueFromPointer(????);
      cout << "The value of the element " << i << " is: ";
      cout << value << endl;
   }
   */

   /* // Core Requirement 3
   // Print the smaller of the first and last elements of the array
   float *pointerToMin = getMinValue(????, ????);
   cout << ?????
   */

   // Clean up your array(s) here
   delete[] arrayList;

   return 0;
}

