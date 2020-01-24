/**********************************************************************
 * File: ta03.cpp
 * Author: Carlos Santos, Matt Hummer, Gláucio Oliveira
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

#define MAX_LINES 10

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
	int booknumber;
	string book;
	int chapter;
	int startverse;
	int endverse;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display( Scripture& scripture)
{
	//if the startverse is higher then the endverse
	//and if the endverse is valid ( > 0)
	//invert the numbers.
	if (scripture.endverse > 0 && 
		scripture.startverse > scripture.endverse)
	{
		int endverse = scripture.endverse;

		scripture.endverse = scripture.startverse;
		scripture.startverse = endverse;
	}

	if (scripture.booknumber > 0)
	{
		cout << scripture.booknumber << " ";
	}

	cout << scripture.book << " ";
	cout << scripture.chapter;

	//if a valid startverse was passed, display it
	if (scripture.startverse > 0)
	{
		cout << ":" << scripture.startverse;
		
		//if there is a endverse valid, display it.
		if (scripture.endverse > 0)
		{
			cout << "-" << scripture.endverse;
		}
	}

	cout << endl;
}

string promptFileName()
{
	string output;
	cout << "Please type the file name: ";
	getline(cin, output);

	return output;
}

void readFile(string fileName, string lines[], int& lineNumbers)
{
	ifstream fileReader;

	fileReader.open(fileName);

	if (fileReader.fail())
	{
		throw string("Error while reading the file :(");
	}

	string line;

	while (getline(fileReader, line))
	{
		lines[lineNumbers] = line;
		lineNumbers++;
	}

	fileReader.close();
}

/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
	Scripture scriptures[MAX_LINES];
	string lines[MAX_LINES];
	string fileName = "ta03f.txt"; // promptFileName();
	int lineNumbers = 0;

	try
	{
		readFile(fileName, lines, lineNumbers);
	}
	catch (string out)
	{
		cout << "ERROR: " << out;
	}

	for (int i = 0; i < lineNumbers; i++)
	{
		Scripture scripture;

		stringstream ss(lines[i]);

		ss >> scripture.booknumber;
		if (ss.fail())
		{
			scripture.booknumber = 0;
			ss.clear(); //keep the same position;
		}

		ss >> scripture.book;
		ss >> scripture.chapter;
		ss >> scripture.startverse;
		ss >> scripture.endverse;

		if (ss.fail()) scripture.endverse = 0;

		scriptures[i] = scripture;

		display(scriptures[i]);
	}

	return 0;
}


