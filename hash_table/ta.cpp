#include <iostream>
#include "ta.h"

using namespace std;

namespace ecm5 {

	unsigned int Ta::hf(int num) const { // хеширование умножением (метод Дональда Кнута)
		int p = 5;
		unsigned int y = num;
		unsigned int k = 2654435769;

		return (y * k) >> (32 - p); // Производим побитовый сдвиг вправо
	}

	void Ta::add(int num) // Добавление элемента в таблицу
	{
		int counter = 1; // объявляем счетчик попыток
		int h = this->hf(num);

		if (this->ta[h] == NULL) // Если место свободно, то сразу заполняем таблицу и завершаем работу функции
		{
			this->ta[h] = num;
			return;
		}

		while (this->ta[h] != NULL && counter < 32) // Если нет, то ищем либо до тех пор, пока не найдем свободное место,
		{											// либо до тех пор, пока не исчерпаем весь размер таблицы
			h = (h + counter) % 32;
			counter++;
		}

		if (this->ta[h] != NULL && counter == 32)
		{
			cout << "No more space in this table.\n";
			return;
		}

		this->ta[h] = num;
	}

	void Ta::search(int num) const // Поиск элемента
	{
		int counter = 1; // объявляем счетчик попыток пробаций
		int h = this->hf(num);

		if (this->ta[h] == num) // Если сразу же находим элемент, то печатаем это на экран и завершаем работу функции
		{
			cout << "Your element is in the " << h << " position. Searching has taken " << counter << " tryings." << endl;
			return;
		}

		while (this->ta[h] != NULL && counter < 32) // Если нет, ищем до тех пор, пока не найдем, либо пока не закончится таблица
		{
			h = (h + counter) % 32;
			counter++;
			if (this->ta[h] == num)
			{
				cout << "Your element is in the " << h << " position. Searching has taken " << counter << " tryings." << endl;
				return;
			}
		}

		if (this->ta[h] == NULL || (this->ta[h] != num && counter == 32))
		{
			cout << "No such element in this table.\n"; // Выводим сообщение об отсутствии
			return;
		}
	}

	void Ta::print() const // Печатаем таблицу на экран
	{
		cout << endl;
		for (int i = 0; i < 32; i++)
		{
			if (this->ta[i] == 0)
			{
				cout << i << ": " << "NULL" << endl;
				continue;
			}
			cout << i << ": " << this->ta[i] << endl;
		}
		cout << endl;
	}

	Ta::Ta() // Инициализируем таблицу NULL'ами
	{
		this->ta = new int[32];
		for (int i = 0; i < 32; i++)
		{
			*(this->ta + i) = NULL;
		}
	}

	Ta::~Ta() // Освобождаем память
	{
		delete[] this->ta;
	}
}

