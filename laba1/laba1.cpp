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
    srand( time(NULL) );
    T **arr = new T*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new T[n];
    for (int i = 0; i < n; i++)
        for (int j =0; j < n; j++)
    arr[i][j] = T((rand() % 100)/(float)(rand() % 100) + 1.0);
    return arr;
}

template <typename T>
bool CreateArray(int n)
{
    T **array1 = RandomArray<T>(n);
    //Display(array1, n);
    //Display(Transpose(array1, n), n);
    for (int i = 0; i < n; i++)
    delete [] array1[i];
}


int main ()
{
    cout << "enter n: ";
    int n;
    cin >> n;
    n = sqrt(n);
    //cout << "Enter type: ";
    string Arraytype;
    //cin >> Arraytype;
    Arraytype = "double";

    if (Arraytype == "double")
        CreateArray<double>(n);
    else if (Arraytype == "int")
       CreateArray <int>(n);
    else if (Arraytype == "float")
        CreateArray<float>(n);
    else if (Arraytype == "char")
        CreateArray<char>(n);
    return 0;
}
