#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <codecvt>

using namespace std;

bool IsWordLetter(char x)
{
    return (toupper(x) != tolower(x)) || ((int)x == -1);
}

int ShortWordLength(string expression) 
{
    int 
        wordLength = 0, 
        shortWordLength = INT_MAX;

    for (int i = 0; i < expression.length(); i++)
    {
        if (IsWordLetter(expression[i])) 
            wordLength++;
        else 
        {
            if ((wordLength < shortWordLength) && (wordLength != 0))
                shortWordLength = wordLength;

            wordLength = 0;
        }
    }

    return shortWordLength;
}

int main()
{
  //  SetConsoleCP(1251);
   // SetConsoleOutputCP(1251);

    system("chcp 1251>null");

    int shortestWordIndex, 
        shortestWordLength = INT_MAX,
        workIndex = 0;

	std::ifstream inputFile("Work files\\F1.txt");
    ofstream outputFile("Work files\\F2.txt");

    if (inputFile.is_open()) 
    {
        while (!inputFile.eof())
        {
            workIndex++;

            string row;
            getline(inputFile, row);

            int minLength = ShortWordLength(row);
            if (minLength < shortestWordLength)
            {
                shortestWordIndex = workIndex;
                shortestWordLength = minLength;
            } 

            cout << "row #" << workIndex << ": \"" << row << "\": " << minLength << endl;
        }

        //go to very beginning
        workIndex = 0;
        inputFile.seekg(ios_base::beg);

        while (!inputFile.eof())
        {
            workIndex++;

            string row;
            getline(inputFile, row);

            if (workIndex != shortestWordIndex)
                outputFile << row << endl;
        }

        cout << "String row #" << shortestWordIndex << " has the shortest word!!!";
    }
    else 
    {
        cout << "Error: the file is not open!!!" << endl << endl
            << "Please, check does Work files\\F1.txt exist"
            << "and check the file status (is the file read only or protected)";
    }

    system("pause");
    return 0;
}