#ifndef BOOKLIST_H
#define BOOKLIST_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include "Book.h"
#include "DynamicArray.h"

using namespace std;

class BookList
{
private:
	Book book;
	DynamicArray<Book> ListOfBook;
	int choice;
	int index;
	bool check;
	string again;
public:
	BookList();
	void addBook();
	void removeBook();
	void Search();
	void showAvailable();
	void borrow();
	void statistics();
	void Sort();
	void showAll();
};

#endif // BOOKLIST_H
