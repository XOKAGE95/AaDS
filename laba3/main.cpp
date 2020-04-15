#include <iostream>
#include <exception>
#include<math.h>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

template <typename A>
void Display (A *arr, int n, ostream &file)
{
    file << "Your array: " << endl;
    for (int i = 0; i < n; i++)
        file << setw(7) << left << setprecision(5) <<arr[i];
    file << endl;
}

template<typename A>
void ShellSort(int n, A *arr)
{
    int d, i, j, count = 0;;
    A tmp;
	for (d = n / 2; d > 0; d /= 2)
    {
        count ++;
        cout << "Iteration " << count << " d = " << d << endl;
		for (i = d; i < n; i++)
			for (j = i - d; j >= 0 && arr[j] > arr[j + d]; j -= d)
			{
			    cout << "Swap " << arr[j] << " " << arr[j+d] << endl;
				tmp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = tmp;
			}
        Display(arr, n, cout);
    }

}

template <typename T>
T *RandomArray(int n)
{
    srand( time(NULL) );
    T *arr = new T[n];
    for (int i = 0; i < n; i++)
    arr[i] = T((rand() % 100 )/(float)(rand() % 9 + 1.0));
    return arr;
}

template <typename T>
bool CreateArray(int n)
{
    T *array1 = RandomArray<T>(n);
    Display(array1, n, cout);
    ShellSort(n, array1);
    Display(array1, n, cout);
    for (int i = 0; i < n; i++)
    delete [] array1;
    return true;
}
int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    cout << "Enter array type: ";
    string ArrayType;
    cin >> ArrayType;
    bool condition;
    if (ArrayType == "double")
        condition = CreateArray<double>(n);
    else if(ArrayType == "float")
        condition = CreateArray<float>(n);
    else if(ArrayType == "int")
        condition = CreateArray<int>(n);
    if (condition) return 0;
    else return -1;
}
