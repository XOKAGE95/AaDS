#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include <iostream>
#include <exception>
#include <math.h>
#include <ctime>
#include <string>

using namespace std;

/*Ñîçäàéòå øàáëîí ôóíêöèè transpose(),
âûïîëíÿþùåé òðàíñïîíèðîâàíèå êâàäðàòíîé ìàòðèöû.
Â êà÷åñòâå ïàðàìåòðîâ øàáëîíà èñïîëüçóéòå òèï ýëåìåíòîâ T
è ðàçìåð ìàòðèöû n.
Ïðîäåìîíñòðèðóéòå ðàáîòó øàáëîíà äëÿ ðàçëè÷íûõ
òèïîâ ýëåìåíòîâ è ðàçìåðîâ ìàòðèö.*/


template <typename T>
T **Transpose(T **arr1, int n)
{
	T **arr2 = new T*[n];
	for (int i = 0; i < n; i++)
		arr2[i] = new T[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr2[i][j] = arr1[j][i];
	return arr2;
}

template <typename T>
void Display(T **arr, int n)
{
	cout << "Your array: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename T>
T **RandomArray(int n)
{
	srand(time(NULL));
	T **arr = new T*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new T[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = T((rand() % 100) / float(rand() % 10+1)) + 1.0;
	return arr;
}

template <typename T>
T **CreateArray(int n)
{
	T **arr = new T*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new T[n]; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Enter a[" << i << "][" << j << "] : ";
			cin >> arr[i][j];
		}
	return arr;
}
int main()
{
	int n = 0;
	cout << "enter n: ";
	cin >> n;
	cout << "Enter type: ";
	string TypeA;
	cin >> TypeA;
	if (TypeA == "double")
	{
		double **array1 = CreateArray<double>(n);
		Display(array1, n);
		Display(Transpose(array1, n), n);
		for (int i = 0; i < n; i++)
			delete[] array1[i];
	}
	else if (TypeA == "int")
	{
		int **array1 = RandomArray<int>(n);
		Display(array1, n);
		Display(Transpose(array1, n), n);
		for (int i = 0; i < n; i++)
			delete[] array1[i];
	}
	else if (TypeA == "char")
	{
		char **array1 = CreateArray<char>(n);
		Display(array1, n);
		Display(Transpose(array1, n), n);
		for (int i = 0; i < n; i++)
			delete[] array1[i];
	}
	else if (TypeA == "float")
	{
		float **array1 = RandomArray<float>(n);
		Display(array1, n);
		Display(Transpose(array1, n), n);
		for (int i = 0; i < n; i++)
			delete[] array1[i];
	}
	else return 0;
	system("pause");
	return 0;
}