// LAB-7.1(2).cpp
// Сушинський Ігор
// Лабораторна робота №7.1.
// Впорядкування рядків / стовпчиків матриці.
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Random(int** x, const int rowCount, const int colCount, const int Min, const int Max); // Прототип ф-ї
void Print(int** x, const int rowCount, const int colCount); // Прототип ф-ї
void Sort(int** x, const int rowCount, const int colCount); // Прототип ф-ї
void Replace(int** x, const int row1, const int row2, const int colCount); // Прототип ф-ї

int main()
{
	srand((unsigned)time(NULL));

	int Min = -12;
	int Max = 23;

	int rowCount = 7;
	int colCount = 6;

	int** x = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		x[i] = new int[colCount];

	Random(x, rowCount, colCount, Min, Max);
	Print(x, rowCount, colCount);
	Sort(x, rowCount, colCount);
	Print(x, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] x[i];
	delete[] x;

	return 0;
}

void Random(int** x, const int rowCount, const int colCount, const int Min, const int Max) // Генератор рандомних чисел
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			x[i][j] = Min + rand() % (Max - Min + 1);
}

void Print(int** x, const int rowCount, const int colCount) // Форматне виведення
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << x[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** x, const int rowCount, const int colCount) // Сортування методом обміну("бульбашки")
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((x[i1][0] > x[i1 + 1][0])
				||
				( x[i1][0] == x[i1 + 1][0] && x[i1][1] > x[i1 + 1][1])
				||
				( x[i1][0] == x[i1 + 1][0] &&
					x[i1][1] == x[i1 + 1][1] &&
					x[i1][3] < x[i1 + 1][3]))
				Replace(x, i1, i1 + 1, colCount);
}

void Replace(int** x, const int row1, const int row2, const int colCount) // Ф-я заміни рядків місцями
{
	int tmp;

	for (int j = 0; j < colCount; j++)
	{
		tmp = x[row1][j];
		x[row1][j] = x[row2][j];
		x[row2][j] = tmp;
	}
}