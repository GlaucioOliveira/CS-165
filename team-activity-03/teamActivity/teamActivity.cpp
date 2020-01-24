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
	string book;
	int chapter;
	int startverse;
	int endverse;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture& scripture)
{
	cout << scripture.book << " ";
	cout << scripture.chapter << ":";
	cout << scripture.startverse;

	if (scripture.endverse > 0)
	{
		cout << "-" << scripture.endverse;
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
	string fileName = "ta03c.txt"; // promptFileName();
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


