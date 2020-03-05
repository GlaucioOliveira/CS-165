
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
| \*          | Dereference   | *pTeste |   
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

## Variables

```cpp

```