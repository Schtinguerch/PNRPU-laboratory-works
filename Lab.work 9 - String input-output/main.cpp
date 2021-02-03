#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsWordLetter(char x)
{
    x = tolower(x);
    bool is_letter = ((x >= 'a') && (x <= 'z')) || ((x >= 'а') && (x <= 'я'));

    return is_letter;
}

int WordLength(string word)
{

}

int ShortWordLength(string expression) 
{

}

int main()
{
    int shortestWordIndex, 
        shortestWordLength = INT_MAX,
        workIndex = 0;

    ifstream inputFile("Work files\\F1.txt");
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
        }

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

        cout << "String row №" << shortestWordIndex << "has the shortest word!!!";
    }
    else 
    {
        cout << "Error: the file is not open!!!" << endl << endl
            << "Please, check does Work files\\F1.txt exist"
            << "and check the file status (is the file read only or protected)";
    }

    return 0;
}