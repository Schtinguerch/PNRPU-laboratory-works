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

bool CouldConsist(string baseString, string substring)
{
    int 
        baseStrLength = baseString.size(), 
        subStrLength = substring.size();

    return baseStrLength != 0 && subStrLength != 0 && baseStrLength >= subStrLength;
}

int MaxEqualityLength(string stringPart)
{
    int
        pi = 0,
        equalityLength = 0,
        strLength = stringPart.size();

    string
        prefix = "",
        suffix = "";

    for (int i = 0; i < strLength - 1; i++)
    {
        pi++;

        prefix += stringPart[i];
        suffix = stringPart[strLength - i - 1] + suffix;

        if (prefix == suffix)
            equalityLength = pi;
    }

    return equalityLength;
}

int* OffsetPi(string substring)
{
    int subStrLength = substring.size(),
        *pi = new int[subStrLength];

    string workPart = "";
    for (int i = 0; i < subStrLength; i++)
    {
        workPart += substring[i];
        pi[i] = MaxEqualityLength(workPart);
    }

    return pi;
}

int KnuthMorrisPrattSearch(string baseString, string substring)
{
t    int 
        baseStrLength = baseString.size(), 
        subStrLength = substring.size(),
        firstEntryIndex = -1,
        entryOrderNumber = 0;
    
    bool isElementFound = false;

    if (CouldConsist(baseString, substring))
    {
        int* pi = OffsetPi(substring);

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

        delete[] pi;
    }
    

    if (!isElementFound)
        cout << "Error: the string does not contain this substring:" << endl;

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
