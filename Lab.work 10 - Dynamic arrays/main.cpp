#include <iostream>
#include <Windows.h>

using namespace std;

int 
    _rowCount, 
    _columnCount;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

int** NewMatrix(int rows, int columns) 
{
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = new int[columns];

        for (int j = 0; j < columns; j++)
            matrix[i][j] = rand();
    }

    _rowCount = rows;
    _columnCount = columns;
    return matrix;
}

void PrintMatrix(int** matrix) 
{
    for (int i = 0; i < _rowCount; i++)
    {
        for (int j = 0; j < _columnCount; j++)
            cout << matrix[i][j] << ' ';

        cout << endl;
    }
}

void AddNewRow(int**& baseMatrix, int rowNumber) 
{
    rowNumber--;
    _rowCount++;
    int** newMatrix = new int*[_rowCount];

    /*
    for (int i = 0; i < _rowCount; i++) 
    {
        newMatrix[i] = new int[_columnCount];
        if (i != rowNumber)
            newMatrix[i] = baseMatrix[i];
        else 
            for (int j = 0; j < _columnCount; j++)
                newMatrix[i][j] = 1;
    } */

    int i = 0;
    while ((i != rowNumber) && (i < _rowCount))
    {
        newMatrix[i] = new int[_columnCount];
        newMatrix[i] = baseMatrix[i];
        i++;
    }

    newMatrix[i] = new int[_columnCount];
    for (int j = 0; j < _columnCount; j++)
        newMatrix[i][j] = 1;
    
    for (i = rowNumber + 1; i < _rowCount; i++) 
    {
        newMatrix[i] = new int[_columnCount];
        newMatrix[i] = baseMatrix[i - 1];
    }

    baseMatrix = newMatrix;
}

void AddNewColumn(int**& baseMatrix, int columnNumber)
{
    columnNumber--;
    _columnCount++;
    int** newMatrix = new int*[_rowCount];

    for (int i = 0; i < _rowCount; i++) 
    {
        newMatrix[i] = new int[_columnCount];
        int j = 0;
        while ((j != columnNumber) && (j < _columnCount))
        {
            newMatrix[i][j] = baseMatrix[i][j];
            j++;
        }

        newMatrix[i][j] = 2;

        for (j = columnNumber + 1; j < _columnCount; j++)
            newMatrix[i][j] = baseMatrix[i][j - 1];
    }

    baseMatrix = newMatrix;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите количество строк и столбцов для формирования матрицы:" << endl;
    int rowCount = ReadNaturalNum(), columnCount = ReadNaturalNum();

    int** matrix = NewMatrix(rowCount, columnCount);
    PrintMatrix(matrix);

    cout << "Введите номер строки, в который нужно добавить новую строку:" << endl;
    int index = ReadNaturalNum();
    AddNewRow(matrix, index);
    PrintMatrix(matrix);

    cout << "Введите номер столбца, в который нужно добавить новый столбец:" << endl;
    index = ReadNaturalNum();
    AddNewColumn(matrix, index);
    PrintMatrix(matrix);

    system("pause");
    return 0;
}