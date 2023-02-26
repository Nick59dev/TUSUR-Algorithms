#include <iostream>
#include <fstream>

int counter = 0;

void makeheap(int *&arr, int n, int i) // преобразуем поддерево в двоичную кучу (i - корневой узел)
{
	int biggest = i; // Наибольший элемент равен корню

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[biggest]) // сравниваем и инкрементируем счетчик сравнений. 
	{
		biggest = l; // Если левый элемент больше корня текущего дерева
		// counter++;
	}
	counter++;

	if (r < n && arr[r] > arr[biggest]) // если правый элемент больше всех
	{
		biggest = r;
		// counter++;
	}
	counter++;

	if (biggest != i)
	{
		int temp = arr[i]; // если самый большой элемент не является корнем, то меняем их местами
		arr[i] = arr[biggest];
		arr[biggest] = temp;

		// counter++;

		makeheap(arr, n, biggest); // рекурсивно преобразуем в кучу остальное
	}
	counter++;
}

void h_sort(int *&arr, int n) // пирамидальная сортировка (heap sort)
{
	for (int i = (n / 2) - 1; i >= 0; i--) // строим кучу
	{
		makeheap(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--) // Извлекаем элементы из кучи
	{
		// перемещаем текущий корень в конец
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		makeheap(arr, i, 0); // вызываем makeheap на уменьшенной куче
	}
}

void print(int *&arr, int n) // вспомогательная функция, печатающая массив
{
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	using namespace std;

	int *nums100 = new int[100];
	int *nums1000 = new int[1000];
	int *nums10000 = new int[10000];

	ifstream f100("numbers100.txt");
	ifstream f1000("numbers1000.txt");
	ifstream f10000("numbers10000.txt");

	ofstream data1000("data1000.txt", ios::out, ios::trunc);
	ofstream data10000("data10000.txt", ios::out, ios::trunc);

	for (int i = 0; i < 100; i++)
	{
		f100 >> nums100[i];
	}

	for (int i = 0; i < 1000; i++)
	{
		f1000 >> nums1000[i];
	}

	for (int i = 0; i < 10000; i++)
	{
		f10000 >> nums10000[i];
	}

	// Печатаем изначальный массив (100 элементов)

	cout << "starting array:";
	print(nums100, 100);

	// сортируем массивы и печатаем счетчик сравнения для каждого из них

	h_sort(nums100, 100);
	cout << "Counter for 100 elements array: " << counter << endl;
	counter = 0;

	h_sort(nums1000, 1000);
	cout << "Counter for 1000 elements array: " << counter << endl;
	counter = 0;

	h_sort(nums10000, 10000);
	cout << "Counter for 10000 elements array: " << counter << endl;

	// Печатаем отсортированный массив (100 элементов)

	cout << endl << "sorted array:";
	print(nums100, 100);

	// записываем отсортированные большие массивы в файлы

	for (int i = 0; i < 1000; i++)
	{
		data1000 << nums1000[i] << " ";
	}

	for (int i = 0; i < 10000; i++)
	{
		data10000 << nums10000[i] << " ";
	}

	delete[] nums100;
	delete[] nums1000;
	delete[] nums10000;

	f100.close();
	f1000.close();
	f10000.close();

	data1000.close();
	data10000.close();

	getchar();
	return 0;
}

