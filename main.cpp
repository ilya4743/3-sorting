#include<iostream>
#include<cstdlib>
using namespace std;

void HoaraSort(int* a, int f, int l)
{
	int i = f, j = l;
	int tmp, x = a[(f + l) / 2];
	do
	{
		while (a[i]<x)
			i++;
		while (a[j]>x)
			j--;
		if (i <= j)
			if (i<j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		i++;
		j--;
	} while (i <= j);
	if (i<l)
		HoaraSort(a, i, l);
	if (f<j)
		HoaraSort(a, f, j);
}

void ShellSort(int *a, int n)
{
	int i, j, s;
	int tmp;
	for (s = n / 2; s>0; s /= 2)
		for (i = s; i<n; i++)
			tmp = a[i];
	for (j = i; i >= s; j -= s)
	{
		if (tmp<a[j - s])
			a[j] = a[j - s];
		else
			break;
	}
	a[j] = tmp;
}

void BubbleSort(int *a, int n)
{
	for (int i = 0; i <n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	}
}

void PrintArray(int *a, int n)
{
	cout << "Отсортированный массив: ";
	for (int i = 0; i<n; i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	const int n = 10;
	int a[n], q = 0;
	cout << "Исходный массив: ";
	for (int i = 0; i<n; i++)
	{
		a[i] = rand();
		cout << a[i] << " ";
	}
	cout << endl << endl << "Меню программы:" << endl;
	cout << "Нажмите 1, чтобы провести сортировку Хоара" << endl;
	cout << "Нажмите 2, чтобы провести сортировку Шелла" << endl;
	cout << "Нажмите 3, чтобы провести сортировку методом пузырька" << endl;
	cout << "Нажмите 4, чтобы вывести отсортированный массив" << endl;
	cout << "Нажмите 5, чтобы завершить выполнение программы" << endl;
	while (q != 5)
	{
		cout << endl << "Введите значение для перехода по меню: ";
		cin >> q;
		if (q == 1)
		{
			HoaraSort(a, 0, n - 1);
			cout << "Сортировка Хоара произведена" << endl;
		}
		if (q == 2)
		{
			ShellSort(a, n);
			cout << "Сортировка Шелла произведена" << endl;
		}
		if (q == 3)
		{
			BubbleSort(a, n);
			cout << "Сортировка методом пузырька произведена" << endl;
		}
		if (q == 4) PrintArray(a, n);
	}
	return 0;
}