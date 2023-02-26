#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count1; // переменная, обозначающая количество ребер графа
int count2; // переменная, означающая количесто вершин
vector<int> *v; // ребра изначальной структуры данных
bool *newV; // временная переменная для обозначения уже пройденных вершин
std::pair<int, int> *t; // ребра получившегося дерева

int countT = 0;

void read_from_txt() // функция считывания информации о нашей структуре данных из файла
{
    ifstream f("gnums.txt", ios::in);
    int tmp1, tmp2;

    f >> count2;
    f >> count1;

    v = new vector<int>[count1 + 1];
    t = new std::pair<int, int>[count1 + 1];
    newV = new bool[count2];

    for (int i = 0; i < count1; i++)
    {
        f >> tmp1;
        f >> tmp2;

        v[tmp1 - 1].push_back(tmp2 - 1);
        v[tmp2 - 1].push_back(tmp1 - 1);
    }

    f.close();
}

void print() // вспомогательная функция, печатающая нашу структуру данных на экран
{
    cout << "Yor data structure:"
         << endl;
    for (int i = 0; i < count1 + 1; i++)
    {
        for (std::vector<int>::iterator j = v[i].begin(); j != v[i].end(); j++)
        {
            cout << *j + 1 << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void maketrue() // инициализируем проверочный массив значениями true
{
    for(int i = 0; i < count2; i++)
    { newV[i] = true; }
}

void searchG(int temp) // функция поиска стягивающего дерева
{
    newV[temp] = false; // делаем текущую вершину неактивной
    for(std::vector<int>::iterator j = v[temp].begin(); j != v[temp].end(); j++)
    {
        if(newV[*j])
        {
            if(countT <= count2)
            {
                t[countT].first = temp; // добавляем вершину в набор ветвей
                t[countT].second = *j;
                countT++;
            }
            searchG(*j); // рекурсивно вызываем нашу функцию от следующей вершины
        }
    }
}

void printT() // функция печати на экран получившегося дерева
{
    cout << "Your tree seems like this:"
         << endl;
    for(int i = 0; i < countT; i++)
    {
        cout << t[i].first + 1 << " " << t[i].second + 1 << endl;
    }
    cout << endl;
}

int main()
{
    maketrue();

    read_from_txt();
    print();

    searchG(8);
    cout << endl;

    maketrue();

    printT();

    delete[] t;
    delete[] v; // освобождаем память от нашей структуры данных
    delete[] newV;

    return 0;
}

