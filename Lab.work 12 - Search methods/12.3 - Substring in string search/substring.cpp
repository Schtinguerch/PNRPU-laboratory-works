#include <iostream>
#include "Windows.h"
#include <string>

using namespace std;

string ReadLine()
{
    string line;

    getline(cin, line);
    return line;
}

void FindSubstring(string& baseString, string& substring)
{
    string foundSubstring = "";
    int index = 0;

    for (int i = 0; i < baseString.length(); i++)
    {
        if (baseString[i] == substring[index])
        {
            foundSubstring += baseString[i];
            if (index == substring.length() - 1)
                break;
            
            index++;
        }
        else
        {
            foundSubstring = "";
            index = 0;
        }
    }

    if (foundSubstring == substring)
        cout << "Substring \"" << substring << "\" has been found!" << endl;
    
    else
        cout << "The string doesn't contain \"" << substring << "\"!\n";
    
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Enter the string: ";
    string line = ReadLine();

    cout << "Enter the substring, which is necessary to find: ";
    string substring = ReadLine();

    FindSubstring(line, substring);
    
    system("pause");
    return 0;
}