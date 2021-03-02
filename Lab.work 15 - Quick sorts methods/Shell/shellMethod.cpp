#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

struct KeyboardLayout
{
    string Name;
    string Author;
    string Language;
    int ReleaseYear;
};

int _itemCount = 0;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

KeyboardLayout* InputNewLayouts()
{
    cout << "Input the count of new keyboard layouts:" << endl;

    _itemCount = ReadNaturalNum();
    KeyboardLayout* layouts = new KeyboardLayout[_itemCount];

    for (int i = 0; i < _itemCount; i++)
    {

        cout << endl << "Layout's name:         ";
        cin.ignore();
        getline(cin, layouts[i].Name);

        cout  << "Layout's author:       ";
        getline(cin, layouts[i].Author);

        cout << "Layout's language:     ";
        getline(cin, layouts[i].Language);

        cout << "Layout's release year: ";
        layouts[i].ReleaseYear = ReadNaturalNum();
    }

    cout << endl;
    return layouts;
}

void PrintKeyboardLayouts(KeyboardLayout* layouts)
{
    for (int i = 0; i < _itemCount; i++)
    {
        cout << "Keyboad layout #" << i + 1 << ":\n";
        cout << "Name:      \"" << layouts[i].Name << "\";\n";
        cout << "Author:    \"" << layouts[i].Author << "\";\n";
        cout << "Language:  \"" << layouts[i].Language << "\";\n";
        cout << "Rel. Year: \"" << layouts[i].ReleaseYear << "\";\n\n";
    }
}

void Swap(KeyboardLayout& first, KeyboardLayout& second)
{
    KeyboardLayout buffer = first;
    first = second;
    second = buffer;
}

void ShellSort(KeyboardLayout* layouts)
{
    int offset = _itemCount;
    while (offset > 0)
    {
        offset /= 2;
        for (int i = 0; i < _itemCount - offset - 1; i++)
            if (layouts[i].ReleaseYear > layouts[i + offset + 1].ReleaseYear)
                Swap(layouts[i], layouts[i + offset + 1]);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    KeyboardLayout* layouts = InputNewLayouts();
    PrintKeyboardLayouts(layouts);

    ShellSort(layouts);

    cout << "Sorted array:" << endl;
    PrintKeyboardLayouts(layouts);

    system("pause");
    return 0;
}