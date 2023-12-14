#include "Book.h"
Book::Book()
{
	Author = " ";
	genre = " ";
	title = " ";
	ISBN = " ";
	status = false;
}
string Book::getAuthor()
{
	return Author;
}
string Book::getGenre()
{
	return genre;
}
string Book::getTitle()
{
	return title;
}
string Book::getISBN()
{
	return ISBN;
}
bool Book::getStatus()
{
	return status;
}
// Change status
void Book::setStatus(bool stat)
{
    status = stat;
}
// operator overloading to == operator
bool Book::operator==(const Book& obj)
{
		return (title == obj.title && Author == obj.Author && genre == obj.genre && ISBN == obj.ISBN && status == obj.status);
}
// operator overloading to cin
istream& operator >> (istream& in, Book& obj)
{
	string check;
	cout << "Title :";
	in >> obj.title;
	cout << "Author :";
	in >> obj.Author;
	cout << "Genre :";
	in >> obj.genre;
	cout << "ISBN :";
	in >> obj.ISBN;
	cout << "Is book available ?(Yes / No)";
	in >> check;
	if (check == "Yes" || check == "yes")
	{
		obj.status = true;
	}
	else
		obj.status = false;
	return in;
}
// operator overloading to cout
ostream& operator << (ostream& out, const Book& obj)
{
	out << "Title : " << obj.title << endl;
	out << "Author : " << obj.Author << endl;
	out << "Genre : " << obj.genre << endl;
	out << "ISBN : " << obj.ISBN << endl;
	if (obj.status)
		out << "The book is available ." << endl;
	else
		out << "The book is borrowed ." << endl;
	return out;
}
