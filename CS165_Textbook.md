
# CS165 Textbook (C++) Notes 

Notes from the CS165 Textbook from BYU Idaho


##  Casting Types

Explicit conversion:

```cpp
{
    float value = 3.1415;
    cout << (int)value; //output: 3

    cout << static_cast<int>(value); //same as the cast above; output: 3    
}
```

<br>

## Expressions

| Expression  | Description   | Example | Meaning 
| ----------- | ------------- | ------- | ------- 
| \*          | Dereference   | *pTeste | Retrieve the data from a given address.
| \&          | Address-of    | &valor  | passes the reference in the `stack` of this variable.
| new         | Allocation with new    | &valor  | passes the reference in the `stack` of this variable.
| delete      | Release object    | delete valor  | Since C++ there is no Garbage collector, it's necessary to release used memory in the ´heap´ with this expression.
| sizeof      | Get the Size    | sizeof(int) | 

<br>

## Streams

> Input and Output from Screen

```cpp
#include <iostream> //needed to use cout and cin
#include <string>
using namespace std;

void demo()
{
    string name;
    int age = 0;
    cout << "What is your age? ";

    cin >> age;
    cout << "Thats great!";

    cin.ignore(); //needed to clear the cin buffet

    cout << "What's your name? ";
    getline(cin, name); //to get strings is a little bit different.
}
```

<br>

> Reading and Writing a file

```cpp
#include <fstream>

//Example of reading a file
int getGrade()
{
    ifstream fin("mygrade.txt");
    if(fin.fail()) //validation to see if the file opened correctly
    {
        return -1;
    }

    int grade = 0;

    fin >> grade; //reading the content of the file into a var.

    fin.close();

    return grade;
}

//Example of saving a file
bool saveGrade(int grade)
{
    ofstream fout("mygrade.txt");
    if(fout.fail()) return false;

    fout << grade; //save the 'grade' into the file.

    fout.close();
}

```

<br>

## Pass By Value x Pass By Reference

```cpp
// Pass By Value
void notChange(int number) 
{ 
    number++; 
}
// the number var outside the function will be the same.

// Pass By Reference
void change (int &number)
{
    number++;
}
// the number var outside the function will be changed.
```

## Arrays


> Array at declaration time

```cpp

int grades[2];   // [?, ?] ? = unkow values

int grades2[2] = // [5, 10]
{
    5, 10
};

int grades3[2] = // [5, 0]
{ 
    5
};

int grades4[2] = {}; // [0, 0]

```

<br>

> Multi-dimensional array

```cpp
int grid[4][2];
```

> Pointer arithmetic

An array is a pointer to a block of memory. It will be stored in a sequence. It's possible to iterate through all the elements in a array by incrementing a pointer:

```cpp
int grades[2]
{
    10, 8
};

int *pGrades = grades; //both pGrades and grades point to the first element (10).

for( int i = 0; i < 2; i++)
{
    cout << *pGrades << endl; //display the current data of this address;.
    pGrades++; //advance to the next item in the array.
}

```

<br>

> Hints
- Arrays are always passed by reference in arguments. The address of the array is passed.

## Vectors

The vector behaves the same as an array. The biggest difference is that it can change its size.
```cpp
#include <vector>

void addGrades()
{
    vector <int> grades;

    grades.push_back(10); //add an item onto the end of the vector
    grades.push_back(8);

    cout << gades.size(); //output: 2    
}
```


## Pointers (datatype \*), Addresses (&) and dereference (*)

A pointer is a variable that holds an address. All pointers have a data type.

```cpp
float * grade; //this grade pointer variable 'points' to a float.
```

<br>

The address of any variable can be retrieve with the & operator:
```cpp
int grade = 10;
cout << &grade; //the output will be the address of the 'grade' var.
```

<br>

To retrieve data from a given address, we can use the dereference operator (*).
```cpp
int grade = 10;
int * pGrade; //the location in memory will be stored in this pointer.

pGrade = &grade; //stores in the pGrade the address of the grade var.

cout << *pGrade; //uses the dereference operator (*) to get the data from the address.

```


## Allocating memory (new, delete)

With the `new` and `delete` its possible to allocate and also release dynamic memory during runtime.

```cpp
{
    int gradesSize = 0;
    cout << "Type the amount of grades:";
    cin >> gradesSize;

    try
    {
        int * grades = new int[gradesSize]; //allocate the memory and returns it's position to grades pointer.

        for(int i = 0; i < gradesSize; i++ )
        {
            cin >> grades[i];
        }

        delete [] grades; //release the used memory.
    }
    catch (bad_alloc) //the new throws this exception
    {
        cout << "something went wrong while allocating memory :(";
    }
}

```

## Strings and Chars 

### Tools
> cctype

```cpp
#include <cctype> //this is needed to use those functions below

bool isalpha(char); // is the character an alpha ('a' – 'b' or 'A' – 'Z')? 
bool isdigit(char); // is the character a number ('0' – '9')? 
bool isspace(char); // is the character a space (' ' or '\t' or '\n')? 
bool ispunct(char); // is the character a symbol ( %#$!-_*@.,? )? 
bool isupper(char); // is the character uppercase ('A' – 'Z')? 
bool islower(char); // is the character lowercase ('a' – 'b')?

#include <cctype> //this is needed for those two functions below
int toupper(char); // convert lowercase character to uppercase. Rest unchanged 
int tolower(char); // convert uppercase character to lowercase. Rest unchanged
```

<br>

> c-string

```cpp
#include <cstring> //this is needed to use those functions below

int strlen(const char *); // find the length of a c-string
int strcmp(const char *, const char *); // 0 if the two strings are the same
char *strcpy(char *<dest>, const char *<src>); // copies src onto dest

```

<br>

> c-standard-library

```cpp
#include <cstdlib> //this is needed to use those functions below

double atof(const char *); // parses input for a floating point number and returns it 
int atoi(const char *); // parses input for an integer number and returns it 
int rand(); // generate a random number between 0 and RAND_MAX 
void srand(unsigned int ); // initialize the random number generator rand() 
int system(const char *); // execute a system command as if typed on command prompt 
int abs(int); // returns the absolute value of a number
```


