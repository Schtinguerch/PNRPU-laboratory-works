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

int BoyerMooreSearch(string baseString, string substring)
{
    int 
        baseStrLength = baseString.size(), 
        subStrLength = substring.size(),
        firstEntryIndex = -1;
    
    bool isElementFound = false;

    if (CouldConsist(baseString, substring))
    {
        int 
            point, 
            offset[256],
            entryOrderNumber = 0;    
        
        for (int i = 0; i < 256; i++)
            offset[i] = subStrLength;
        
        for (int i = subStrLength - 2; i >= 0; i--)
        {
            int* tablePointer = &offset[(int)((char)(substring[i])) + 64];

            if (*tablePointer == subStrLength)
                *tablePointer = subStrLength - i - 1;
        }
            
        point = subStrLength - 1; 
        while (point < baseStrLength)
        {
            if (substring[subStrLength - 1] != baseString[point])
                point += offset[int((char)baseString[point]) + 64];
            
            else
            {
                for (int i = subStrLength - 1; i >= 0; i--)
                {
                    if (substring[i] != baseString[point - subStrLength + i + 1])
                    {
                        point += offset[int((char)baseString[point]) + 64];
                        break;
                    }

                    else if (i == 0)
                    {
                        if (!isElementFound)
                        {
                            isElementFound = true;
                            firstEntryIndex = point - subStrLength + 1;
                        }

                        entryOrderNumber++;
                        cout << "Entry #" << entryOrderNumber << " is found: index = " << point - subStrLength + 1 << endl;

                        point++;
                    }
                }
            }
        }
    }

    if (!isElementFound)
        cout << "Error: the string does not contain this substring:" << endl;

    return firstEntryIndex;
}

/*
//service methods

void printCharCodes()
{
    char a = ' ';

    while (a != 'x')
    {
        cin >> a;
        cout << (int)a << endl << endl;
    }
}

void printAllSymbols()
{
    for (int i = 0; i < 256; i++)
        cout << (char)i << ' ';
    
    cout << endl;
}
*/
  
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << INPUT_MESSAGE << endl;
    string mainString = ReadLine();

    cout << NEW_INPUT_MESSAGE << endl;
    string substring = ReadLine();

    BoyerMooreSearch(mainString, substring);

    system("pause");
    return 0;
}