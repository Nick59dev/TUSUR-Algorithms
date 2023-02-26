#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Tree.h"

using namespace std;
using namespace myTree;

int main() {

	short int i = 10;
	int tmp;
	Tree a;
	srand((unsigned int)time(NULL));
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
				a.add(tmp);
				i -= 1;
			}
			break;

		case 2:
			while (i) {
				tmp = rand() % 100;
				a.add(tmp);
				i -= 1;
			}
			break;

		case 3:
			while (!(f.eof())) {
				f >> tmp;
				a.add(tmp);
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
	cout << “Enter the value to count: “;
	cin >> tmp;
	cout << "count function: " << a.count(tmp) << endl;

	cout << "Length: " << a.getLength() << endl;

	cout << endl;

	a.print2();
	
	f.close();
	a.delete_tree();

	system("pause");
	return 0;
}

