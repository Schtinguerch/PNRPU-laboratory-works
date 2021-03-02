#include <iostream>

#define APP_TITLE "Eight queens puzzle"
#define FIELD_SIZE 8

using namespace std;

int _turns = 0;

enum Queen 
{
    Set, Delete
};

int** NewField()
{
    int** field = new int* [FIELD_SIZE];

    for (int i = 0; i < FIELD_SIZE; i++)
    {
        field[i] = new int [FIELD_SIZE];

        for (int j = 0; j < FIELD_SIZE; j++)
            field[i][j] = 0;
    }

    return field;
}

void PrintField(int** chessField)
{
    string field = "";
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (int j = 0; j < FIELD_SIZE; j++)
            field += (chessField[i][j] == -1)? "Q " : 
                (chessField[i][j] > 0)? "* " : ". ";
        
        field += '\n';
    }

    field += '\n';

    _turns++;
    cout << "turn# " << _turns << endl;
    cout << field;
}

void SetState(int** chessField, Queen queenState, int row, int column)
{
    int 
        offset = 0,
        cellValue = 0;

    switch (queenState)
    {
        case Queen::Set:
            offset = 1;
            cellValue = -1;
            break;

        case Queen::Delete:
            offset = -1;
            cellValue = 0;
            break;
    }

    for (int i = 0; i < FIELD_SIZE; i++)
    {
        chessField[i][column] += offset; 
        chessField[row][i] += offset; 

        int foo = column - row + i;
        if (foo >= 0 && foo < FIELD_SIZE)
            chessField[i][foo] += offset;

        foo = column + row - i;
        if (foo >= 0 && foo < FIELD_SIZE)
            chessField[i][foo] += offset;
    }

    chessField[row][column] = cellValue;
    PrintField(chessField);
}

bool CanSetQueen(int** chessField, int row) 
{ 
    bool result = false; 
    
    for (int column = 0; column < FIELD_SIZE; column++)
        if (chessField[row][column] == 0)
        {
            SetState(chessField, Queen::Set, row, column);
            
            if (row == FIELD_SIZE - 1) 
                result = true;

            else 
            {
                result = CanSetQueen(chessField, row + 1);
                
                if (!result)
                    SetState(chessField, Queen::Delete, row, column);
            }
        }
    
    
    return result;
}

void ShowSolution(int** field)
{
    bool hasSolution = CanSetQueen(field, 0);

    if (hasSolution)
    {
        cout << "Final layout:" << endl;
        PrintField(field);
    }
    else
        cout << "The task has no solutions.";
}

int main()
{
    cout << APP_TITLE << endl;
    int** chessField = NewField();
    
    ShowSolution(chessField);
    delete[] chessField;

    system("pause");
    return 0;
}