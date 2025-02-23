#include <iostream>
#include <string>
using namespace std;
// функция для проверки условия возрастания в первом столбце
bool check1(int** matrix, int n)
{
    for (int i = 1; i < n; ++i)
    {
        if (matrix[i][0] <= matrix[i - 1][0])
        {
            return false;
        }
    }
    return true;
}
// функция для заполнения двумерного массива из строки
bool matr(const string& str, int n, int** matrix)
{
    if (str.length() != n * n)
    {
        return false; // длина строки не соответствует размеру массива
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = str[i * n + j] - '0'; // преобразуем символ в цифру
        }
    }
    return true;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    string str;
    int n;
    cout << "введите N: "; 
    cin >> n;
    cout << "введите строку из N^2 цифр: "; 
    cin >> str;

    // Выделение памяти для двумерного массива
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }
    if (matr(str, n, matrix))
    {
        if (check1(matrix, n))
        {
            cout << "можно составить массив так, чтобы первый столбец был в порядке возрастания" << endl;
        }
        else
        {
            cout << "нельзя составить массив с возрастающим первым столбцом" << endl;
        }
    }
    else
    {
        cout << "некорректная длина строки" << endl;
    }
    cout << "сформированный массив:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // Освобождение выделенной памяти
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

