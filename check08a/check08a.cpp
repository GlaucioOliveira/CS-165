/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother {Burton, Falin, Ercanbrack}, CS165
* Author:
*    your name
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
public:
   void promptBookInfo() {

      cout << "Title: ";
      getline(cin, title);

      cout << "Author: ";
      getline(cin, author);

      cout << "Publication Year: ";
      cin >> publicationYear;

      cin.ignore();
   };

   void displayBookInfo() {
      cout << endl << title << " (" << publicationYear << ") by " << author << endl;
   };

private:
   string title;
   string author;
   int publicationYear;
};


// TODO: Define your TextBook class here
class TextBook : public Book
{
public:
   void promptSubject()
   {
      cout  << "Subject: ";
      getline(cin, subject);
   };

   void displaySubject()
   {
      cout << "Subject: " << subject;
   };

private:
   string subject;
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
public:
   void promptIllustrator()
   {
      cout  << "Illustrator: ";
      getline(cin, illustrator);
   };

   void displayIllustrator()
   {
      cout << "Illustrated by " << illustrator;
   };


private:
   string illustrator;
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;
   book.promptBookInfo();
   book.displayBookInfo();

   cout << endl;

   // Declare a TextBook object here and call its methods
   TextBook textBook;
   textBook.promptBookInfo();
   textBook.promptSubject();
   textBook.displayBookInfo();
   textBook.displaySubject();

   cout << endl;

   // Declare a PictureBook object here and call its methods
   PictureBook pictureBook;
   pictureBook.promptBookInfo();
   pictureBook.promptIllustrator();
   pictureBook.displayBookInfo();
   pictureBook.displayIllustrator();

   return 0;
}


