#include "BookList.h"
//Default constructor
BookList::BookList()
{
	ListOfBook.giveInitialize(2); //give initialize value to dynamic array
	choice = 0;
	index = 0;
	check = true;
	again = " ";
}
// Add a new Book
void BookList::addBook()
{
    check = true;
	while (check)
	{
		cout << "Where do you want to add?" << endl;
		cout << "1- Add in end of catalog." << endl;
		cout << "2- Add in front of catalog." << endl;
		cout << "3- Add in specific space." << endl;
		cout << "0- Return to the main menu." << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "----------Enter details of your book.-----------" << endl;
			cin >> book;
			ListOfBook.insertEnd(book);
			break;
		case 2:
			cout << "----------Enter details of your book.-----------" << endl;
			cin >> book;
			ListOfBook.insertFront(book);
			break;
		case 3:
			cout << "What is the place you want? " << endl;
			cout << "Choose your index." << endl;
			cin >> index;
			cout << "----------Enter details of your book.-----------" << endl;
			cin >> book;
			ListOfBook.insertAt(book, index);
			break;
		case 0:
			return;
		default:
			cout << "Oooops !!!" << endl;
			cout << "Try valid choice. " << endl;
			continue;
		}
		cout << "Add again?(yes / no)" << endl;
		cin >> again;
		system("cls");
		if (again == "yes" || again == "Yes")
		{
			continue;
		}
		else
			return;
	}
}
// remove a book
void BookList::removeBook()
{
    string input;
    check = true;
	while (check)
	{
		cout << "Where are you from want to remove?" << endl;
		cout << "1- Remove End." << endl;
		cout << "2- Remove Front." << endl;
		cout << "3- Remove By Index." << endl;
		cout << "4- Remove By Value." << endl;
		cout << "0- Return to main menu." << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			ListOfBook.removeEnd();
			cout << "Remove successfully...." << endl;
			break;
		case 2:
			ListOfBook.removeFront();
			cout << "Remove successfully...." << endl;
			break;
		case 3:
			cout << "Enter your Index : ";
			cin >> index;
			ListOfBook.removeAtIndex(index);
			cout << "Remove successfully...." << endl;
			break;
		case 4:
			cout << "Enter title of Book : ";
			cin >> input;
			for (size_t i = 0; i < ListOfBook.getSize(); i++)
            {
                 if (ListOfBook[i].getTitle() == input)
                {
                    ListOfBook.removeAtValue(ListOfBook[i]);
                    cout << "Remove successfully...." << endl;
                }
            }
			break;
        case 0:
            return;
		default:
		    cout << "Ooops !!!" << endl;
		    cout << "Try valid choice ." << endl;
			break;
		}
		cout << "Remove again?(yes / no)" << endl;
		cin >> again;
		system("cls");
		if (again == "yes" || again == "Yes")
		{
		    check = true;
			continue;
		}
		else
			return;
	}
}
void BookList::Search()
{
    check = true;
    string title;
    string author;
    string isbn;
    string genre;
    while(check)
    {
        cout << "How you want search?" << endl;
        cout << "1- Title." << endl;
        cout << "2- Author." << endl;
        cout << "3- ISBN." << endl;
        cout << "4- Genre." << endl;
        cout << "0- Return to main menu." << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter title of book : ";
            cin >> title;
            system("cls");
            for(size_t i = 0; i < ListOfBook.getSize(); i++)
            {
                if (ListOfBook[i].getTitle() == title)
                {
                    if (ListOfBook.search(ListOfBook[i]))
                    {
                        cout << ListOfBook[i];
                    }
                    else
                        cout << "Book not found....." << endl;
                    check = true;
                }
            }
            if (!check)
                cout << "Book not found...." << endl;
            break;
        case 2:
            cout << "Enter Author of book : ";
            cin >> author;
            system("cls");
             for(size_t i = 0; i < ListOfBook.getSize(); i++)
            {
                if (ListOfBook[i].getAuthor() == author)
                {
                    if (ListOfBook.search(ListOfBook[i]))
                    {
                        cout << ListOfBook[i];
                    }
                    else
                        cout << "Book not found....." << endl;
                    check = true;
                }
            }
            if (!check)
                cout << "Book not found...." << endl;
            break;
        case 3:
            cout << "Enter ISBN of book : ";
            cin >> isbn;
            system("cls");
             for(size_t i = 0; i < ListOfBook.getSize(); i++)
            {
                if (ListOfBook[i].getISBN() == isbn)
                {
                    if (ListOfBook.search(ListOfBook[i]))
                    {
                        cout << ListOfBook[i];
                    }
                    else
                        cout << "Book not found....." << endl;
                    check = true;
                }
            }
            if (!check)
                cout << "Book not found...." << endl;
            break;
        case 4:
            cout << "Enter genre of book : ";
            cin >> genre;
            system("cls");
             for(size_t i = 0; i < ListOfBook.getSize(); i++)
            {
                if (ListOfBook[i].getGenre() == genre)
                {
                    if (ListOfBook.search(ListOfBook[i]))
                    {
                        cout << ListOfBook[i];
                    }
                    else
                        cout << "Book not found....." << endl;
                    check = true;
                }
            }
            if (!check)
                cout << "Book not found...." << endl;
            break;
        case 0:
            return;
        default:
            system("cls");
            cout << "Ooops.....!!" << endl;
            cout << "Enter valid choice......" << endl;
            cout << "Let's try again...." << endl;
            Sleep(1000);
            continue;
        }
        cout << "Search again?(yes / no)" << endl;
		cin >> again;
		if (again == "yes" || again == "Yes")
		{
			continue;
		}
		else
			return;
	}
}
void BookList::showAvailable()
{
    system("cls");
    cout << "------------Available Books--------------" << endl;
    for (size_t i = 0; i < ListOfBook.getSize(); i++)
    {
        if (ListOfBook[i].getStatus())
        {
            cout << ListOfBook[i] << endl;
            cout << "-------------------------------" << endl;
        }
    }
}
void BookList::borrow()
{
    string borrowing;
    string answer;
    cout << "Enter title of book : ";
    cin >> borrowing;
    for (size_t i = 0; i < ListOfBook.getSize(); i++)
    {
        if (ListOfBook[i].getTitle() == borrowing)
        {
            cout << ListOfBook[i];
            cout << "====================" << endl;
            cout << "This Book ?(yes / no)" << endl;
            cin >> answer;
            if (answer == "yes" || answer == "Yes")
            {
                    if (ListOfBook[i].getStatus())
                    {
                        cout << "OK , This book is available." << endl;
                        cout << "Borrowing successfully ........." << endl;
                        ListOfBook[i].setStatus(false);
                    }
                    else
                        cout << "Sorry , but this book is already borrowed ..." << endl;
            }
            else
                cout << "You can try again ......" << endl;
            break;
        }
    }
}
void BookList::statistics()
{
    int counter = 0;
    cout << "1- Number of all books." << endl;
    cout << "2- Number of all available books." << endl;
    cout << "3- Number of all borrowed books." << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
        cout << "Number of all books : " << ListOfBook.getSize() << endl;
        break;
    case 2:
        for (size_t i = 0; i < ListOfBook.getSize(); i++)
        {
            if (ListOfBook[i].getStatus())
            {
                counter++;
            }
        }
        cout << "Number of all available books : " << counter << endl;
        break;
    case 3:
        counter = 0;
         for (size_t i = 0; i < ListOfBook.getSize(); i++)
        {
            if (!(ListOfBook[i].getStatus()))
            {
                counter++;
            }
        }
        cout << "Number of all borrowed books : " << counter << endl;
        break;
    default:
        cout << "Enter valid choice ..." << endl;
        break;
    }
}
void BookList::Sort()
{
    cout << "1- Sort by Title." << endl;
    cout << "2- Sort by Author." << endl;
    cout << "3- Sort by Genre." << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
        for (size_t i = 0; i < ListOfBook.getSize() - 1; i++)
        {
            for (size_t j = i + 1; j < ListOfBook.getSize(); j++)
            {
                if (ListOfBook[i].getTitle() > ListOfBook[j].getTitle())
                {
                    swap(ListOfBook[j], ListOfBook[i]);
                }
            }
        }
        break;
    case 2:
        for (size_t i = 0; i < ListOfBook.getSize() - 1; i++)
        {
            for (size_t j = i + 1; j < ListOfBook.getSize(); j++)
            {
                if (ListOfBook[i].getAuthor() > ListOfBook[j].getAuthor())
                {
                    swap(ListOfBook[j], ListOfBook[i]);
                }
            }
        }
         break;
    case 3:
        for (size_t i = 0; i < ListOfBook.getSize() - 1; i++)
        {
            for (size_t j = i + 1; j < ListOfBook.getSize(); j++)
            {
                if (ListOfBook[i].getGenre() > ListOfBook[j].getGenre())
                {
                   swap(ListOfBook[j], ListOfBook[i]);
                }
            }
        }         break;
    default:
        cout << "Enter valid choice ........" << endl;
        break;
    }

}
void BookList::showAll()
{
    system("cls");
    cout << "------------Book Catalog----------------" << endl;
     if (ListOfBook.getSize() == 0)
     {
               cout << "we have no books to show." << endl;
     }
    else
    {
        for (size_t i = 0; i < ListOfBook.getSize(); i++)
        {
            cout << ListOfBook[i] << endl;
            cout << "------------------------------" << endl;
        }
    }
}
