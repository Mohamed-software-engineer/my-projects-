#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string.h>

using namespace std;

class Book
{
private:
	string Author;
	string title;
	string genre;
	string ISBN;
	bool status;
public:
	Book();
	string getAuthor();
	string getTitle();
	string getGenre();
	string getISBN();
	bool getStatus();
	void setStatus(bool);
	bool operator == (const Book& obj);
	friend ostream& operator << (ostream& out, const Book& obj);
	friend istream& operator >> (istream& in, Book& obj);
};
#endif // BOOK_H
