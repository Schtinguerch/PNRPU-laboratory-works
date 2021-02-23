#include <iostream>
#include <string>
#include "Windows.h"

#define INPUT_MESSAGE "Enter the string, which will be used for searching:"
#define NEW_INPUT_MESSAGE "Enter the substring, which is necessary to find:"

using namespace std;

string ReadLine()
{
    string line;
    getline(cin, line);
    return line;
}

int KnuthMorrisPrattSearch (string baseString, string substring)
{
    int 
        baseStrLength = baseString.size(), 
        subStrLength = substring.size(),
        firstEntryIndex = -1,
        entryOrderNumber = 0;
    
    bool isElementFound = false;

    int* pi = new int[subStrLength];

    pi[0] = 0;
    for (int i = 1, j = 0; i < subStrLength; i++)
    {
        while(j > 0 && substring[j] != substring[i])
            j = pi[j-1];
        if(substring[j] == substring[i])
            j++;

        pi[i] = j;
    }

    for (int i = 0, j = 0; i < baseStrLength; i++)
    {
        while (j > 0 && substring[j] != baseString[i])
            j = pi[j - 1];

        if (substring[j] == baseString[i])
            j++;

        if (j == subStrLength)
        {
            if (!isElementFound)
            {
                isElementFound = true;
                firstEntryIndex = i - j + 1;
            }

            entryOrderNumber++;
            cout << "Entry #" << entryOrderNumber << " is found: index = " << i - j + 1 << endl;
        }
    }

    if (!isElementFound)
        cout << "Error: the string does not contain this substring:" << endl;

    delete[] pi;
    return firstEntryIndex;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << INPUT_MESSAGE << endl;
    string mainString = ReadLine();

    cout << NEW_INPUT_MESSAGE << endl;
    string substring = ReadLine();

    KnuthMorrisPrattSearch(mainString, substring);

    system("pause");
    return 0;
}