#include <iostream>
#include <exception>
#include<math.h>
#include <ctime>

using namespace std;

/*Создайте шаблон функции transpose(),
выполняющей транспонирование квадратной матрицы.
В качестве параметров шаблона используйте тип элементов T
и размер матрицы n.
Продемонстрируйте работу шаблона для различных
типов элементов и размеров матриц.*/


template <typename T>
T **Transpose(T **arr1, int n)
{
    n = sqrt(n);
    T **arr2 = new T*[n];
    for (int i = 0; i < n; i++)
        arr2[i] = new T[n];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j++)
            arr2[i][j] = arr1[j][i];
    return arr2;
}

template <typename T>
void Display (T **arr, int n)
{
    cout << "Your array: " << endl;
    for (int i = 0; i < sqrt(n); i++)
    {
        for (int j = 0; j < sqrt(n); j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

template <typename T>
T **RandomArray(int n)
{
    n = sqrt(n);
    srand( time(NULL) );
    T **arr = new T*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new T[n];
    for (int i = 0; i < n; i++)
        for (int j =0; j < n; j++)
    arr[i][j] = T(rand() % 100);
    return arr;
}

int main ()
{
    int n = 25;
    cout << "enter n: ";
    cin >> n;
    float **array1 = RandomArray<float>(n);
    Display(array1, n);
    Display(Transpose(array1, n), n);
    n = sqrt(n);
    for (int i = 0; i < n; i++)
    delete [] array1[i];
    return 0;
}
