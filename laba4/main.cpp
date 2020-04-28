#include <iostream>
#include <exception>
#include<math.h>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

template <typename T>
void Display (T *arr, int n, ostream &file);

template<typename T>
void ShellSort(int n, T *arr);

template <typename T>
T *RandomArray(int n);

template <typename T>
bool CreateArray(int n);

template <typename T>
T LinearSearch(int n, T *Arr, T unknown);

template <typename T>
T InterpolationSearch(int n, T *arr, T unknown);

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    cout << "Enter array type: ";
    string ArrayType;
    cin >> ArrayType;
    bool condition = false;
    if (ArrayType == "double")
        condition = CreateArray<double>(n);
    else if(ArrayType == "float")
        condition = CreateArray<float>(n);
    else if(ArrayType == "int")
        condition = CreateArray<int>(n);
    if (condition) return 0;
    else return -1;
}

template <typename T>
void Display (T *arr, int n, ostream &file)
{
    file << "Your array: " << endl;
    for (int i = 0; i < n; i++)
        file << setw(10) << left << setprecision(5) <<arr[i];
    file << endl;
}

template<typename T>
void ShellSort(int n, T *arr)
{
    int d, i, j;
    T tmp;
	for (d = n / 2; d > 0; d /= 2)
    {
		for (i = d; i < n; i++)
			for (j = i - d; j >= 0 && arr[j] > arr[j + d]; j -= d)
			{
				tmp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = tmp;
			}
    }

}

template <typename T>
T *RandomArray(int n)
{
    srand( time(NULL) );
    T *arr = new T[n];
    for (int i = 0; i < n; i++)
    arr[i] = T((rand() % 10000)/(float)(rand() % 9 + 1.0));
    return arr;
}

template <typename T>
bool CreateArray(int n)
{
    T *array1 = RandomArray<T>(n);
    //Display(array1, n, cout);
    ShellSort(n, array1);
    //Display(array1, n, cout);
    cout << "x[1000000] = " << array1[1000000] << endl;
    cout << "Enter unknown number: ";
    T unknown;
    cin >> unknown;
    clock_t start = clock();
    int number;
    number = LinearSearch<T>(n, array1, unknown);
    if (number != -1)
        cout << "Your number is: " << number + 1 << " Linear search"<< endl;
    else
        cout << "This number didn't find\n";
    cout << "runtime = " << (clock() - start) << " ms" << endl;
    srand(time(0));
    start = clock();
    number = InterpolationSearch<T>(n, array1, unknown);
    if (number != -1)
        cout << "Your number is: " << number + 1 << " Interpolation search"<< endl;
    else
        cout << "This number didn't find\n";
    cout << "runtime = " << (clock() - start) << " ms" << endl;
    for (int i = 0; i < n; i++)
    delete [] array1;
    return true;
}

template <typename T>
T LinearSearch(int n, T *arr, T unknown)
{
    for (int i = 0; i < n; i++)
        if(arr[i] == unknown)
            return i;
    return -1;
}

template <typename T>
T InterpolationSearch(int n, T *arr, T unknown)
{
    int mid, low = 0, high = n - 1;
    if (arr[low] == unknown)
        return low;
    if (arr[high] == unknown)
        return high;
    while (arr[low] <= unknown && arr[high] >= unknown)
    {
        if(arr[high] == arr[low])
            break;
        mid = low + ((unknown - arr[low]) * (high - low))/(arr[high] - arr[low]);
        if (arr[mid] < unknown)
            low = mid + 1;
        else if (arr[mid] > unknown)
            high = mid - 1;
        else return mid;
    }
    return -1;
}
