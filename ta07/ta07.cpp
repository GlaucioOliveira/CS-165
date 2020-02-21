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
void swapElements(float* theArray[], int a, int b)
{
   float* swap = theArray[a];

   theArray[a] = theArray[b];
   theArray[b] = swap;
}

void sortArray(float* theArray[], int length)
{
   bool sorted = false;
   while (!sorted) {
   sorted = true;
      for (int i = 0; i < length - 1; i++)
      {
         if (getValueFromPointer(theArray[i]) >= getValueFromPointer(theArray[i + 1]))
         {
            swapElements(theArray, i, i + 1);
            sorted = false;
         }
      }
   }
}


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

   // Stretch Challenges
   //1

   // Ex: create an array of pointers to ints:
   //int arraySize = 10;
   float** myArray = new float* [arraySize];

   for (int i = 0; i < arraySize; i++)
   {
      myArray[i] = &arrayList[i];
   }

   cout << endl;

   for (int i = 0; i < arraySize; i++)
   {
      cout << getValueFromPointer(myArray[i]) << endl;
   }

   swapElements(myArray, 0, arraySize - 1);

   cout << endl;

   for (int i = 0; i < arraySize; i++)
   {
      cout << getValueFromPointer(myArray[i]) << endl;
   }

   sortArray(myArray,arraySize);

   cout << endl;

   for (int i = 0; i < arraySize; i++)
   {
      cout << getValueFromPointer(myArray[i]) << endl;
   }

   // Store the address of an int
   //int someInt = 5;
   //int* addressOfSomeInt = &someInt;

   //myArray[0] = addressOfSomeInt;

   // Shortcut
   //int anotherInt = 11;
   //myArray[1] = &anotherInt;



   // Clean up your array(s) here
   delete[] arrayList;
   delete[] myArray;
   return 0;
}

