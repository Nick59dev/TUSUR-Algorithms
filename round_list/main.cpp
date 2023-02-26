#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <malloc.h>
#include "List.h"
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
using namespace myList;

int main()
{
	srand(time(NULL));

	List a;
	int i = 10;
	int tmp;

	
	ifstream f("numbers.txt", ios::in);

	short int choice;
	cout << "Enter a number of the way of the tree \n1: from the keyboard\n2: random\n3: from the file\n[1/2/3]: ";
	cin >> choice;

	try {
		switch (choice) {
		case 1:
			while (i) {
				cout << "enter " << i << " number: ";
				cin >> tmp;
				a.push(tmp);
				i -= 1;
			}
			break;

		case 2:
			while (i) {
				tmp = rand() % 100;
				a.push(tmp);
				i -= 1;
			}
			break;

		case 3:
			while (!(f.eof())) {
				f >> tmp;
				a.push(tmp);
			}
			break;

		default:
			throw (string)"Entered an unexpected value.";
			break;
		}
	}
	catch (const string& str) {
		cout << str << endl;
		return 0;
	}
	
	a.print();

	a.cycle_adding(100, 3, 3);

	a.print();

	a.delete_list();

	system("pause");
	return 0;
}

