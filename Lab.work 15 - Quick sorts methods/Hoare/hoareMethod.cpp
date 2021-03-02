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

void Swap(int& first, int& second)
{
    int buffer = first;
    first = second;
    second = buffer;
}

void HoareSort(KeyboardLayout* layouts, int leftBorderIndex, int rightBorderIndex)
{
    int
        leftPoint = leftBorderIndex,
        rightPoint = rightBorderIndex,
        pivot = layouts[(leftPoint + rightPoint) / 2].ReleaseYear;

    if (leftBorderIndex > rightBorderIndex)
        Swap(leftBorderIndex, rightBorderIndex);

    do
    {
        while ((layouts[leftPoint].ReleaseYear < pivot) && (leftPoint < rightBorderIndex))
            leftPoint += 1;
        
        while ((layouts[rightPoint].ReleaseYear > pivot) && (rightPoint > leftBorderIndex))
            rightPoint -= 1;

        if (leftPoint <= rightPoint)
        {
            Swap(layouts[leftPoint], layouts[rightPoint]);

            leftPoint += 1;
            rightPoint -= 1;
        }
    }
    while (leftPoint <= rightPoint);

    if (leftBorderIndex < rightPoint)
        HoareSort(layouts, leftBorderIndex, rightPoint);
    
    if (leftPoint < rightBorderIndex)
        HoareSort(layouts, leftPoint, rightBorderIndex);
}

void HoareSort(KeyboardLayout* layouts)
{
    HoareSort(layouts, 0, _itemCount - 1);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    KeyboardLayout* layouts = InputNewLayouts();
    PrintKeyboardLayouts(layouts);

    HoareSort(layouts);

    cout << "Sorted array:" << endl;
    PrintKeyboardLayouts(layouts);

    system("pause");
    return 0;
}