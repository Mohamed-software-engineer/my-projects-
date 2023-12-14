#include <iostream>
#include "DynamicArray.h"
#include "Book.h"
#include "BookList.h"
using namespace std;
int main()
{
	BookList obj1;
	int choise;
	bool check = true;
	while (check)
	{
		cout << "------------Welcome in system of library-------------" << endl;
		cout << "Choose." << endl;
		cout << "1- Add." << endl;
		cout << "2- Remove." << endl;
		cout << "3- Show all books." << endl;
		cout << "4- Search." << endl;
		cout << "5- Show available books." << endl;
		cout << "6- Borrow Book." << endl;
		cout << "7- Show statistics of Books." << endl;
		cout << "8- Sort by ....." << endl;
		cout << "9- Clear screen." << endl;
		cout << "0- Exit." << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			obj1.addBook();
			break;
		case 2:
			obj1.removeBook();
			break;
		case 3:
			obj1.showAll();
			break;
        case 4:
            obj1.Search();
            break;
        case 5:
            obj1.showAvailable();
            break;
        case 6:
            obj1.borrow();
            break;
        case 7:
            obj1.statistics();
            break;
        case 8:
            obj1.Sort();
            break;
        case 9:
            system("cls");
            break;
		case 0:
			check = false;
			break;
		default:
			break;
		}
	}
	return 0;
}
