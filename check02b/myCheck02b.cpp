/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Walker, CS165
* Author:
*    Glaucio Oliveira
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// Definition of a Complex struct
struct Complex
{
   double real;
   double imaginary;
};

// TODO: Add your prompt function here
void promptComplexNumber(Complex & c)
{   
   cout << "Real: ";
   cin >> c.real;

   cout << "Imaginary: ";
   cin >> c.imaginary;
}

/**********************************************************************
 * Function: display
 * Purpose: Display a complex number in the screen
 ***********************************************************************/
void display(const Complex& c)
{
      cout << "The sum is: " << c.real << " + " << c.imaginary << "i";
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   // TODO: Fill in the body of the add function
   Complex sum;

   sum.real = x.real + y.real;
   sum.imaginary = x.imaginary+y.imaginary;

   return sum;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex c1;
   Complex c2;

   // Call your prompt function twice to fill in c1, and c2 
   promptComplexNumber(c1);  
   promptComplexNumber(c2);

   // Call the addComplex function, putting the result in sum;
   Complex sum = addComplex(c1, c2);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}


