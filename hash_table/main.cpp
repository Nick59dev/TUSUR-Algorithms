#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "ta.h"
#include <fstream>

int main()
{
	using namespace std;
	using namespace ecm5;

	Ta a;
	int temp;
	fstream f("numbers.txt", ios::in);

	while (!(f.eof()))
	{
		int tmp;
		f >> tmp;
		a.add(tmp);
	}

	a.print();

	cout << "Enter a number you want to find: ";
	cin >> temp;

	a.search(temp);

	system("pause");
	return 0;
}

