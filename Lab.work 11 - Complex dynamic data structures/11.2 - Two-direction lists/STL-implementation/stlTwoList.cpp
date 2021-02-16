#include <iostream>
#include <list>
#include <iterator>

#define LENGTH_ERROR "Error: the list could't be created, incorrect length value."
#define INPUT_MESSAGE "Enter item's count of new list:"
#define NEW_INPUT_MESSAGE "Enter list's index where you'll add new word:"

using namespace std;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

list<char*> NewList(int listLength)
{
    if (listLength <= 0)
    {
        cout << LENGTH_ERROR << endl;
        return {};
    }
    else 
    {
        list<char*> newList;
        for (int i = 0; i < listLength; i++)
            newList.push_back("hello");

        return newList;
    }
}

void PrintList(list<char*>& printList) 
{
    list<char*>::iterator item;
    for (item = printList.begin(); item != printList.end(); item++)
        cout << *item << ' ';

    cout << endl;
}

void AddNewItem(list<char*>& baseList, char* value, int position)
{
    position--;

    list<char*> newList;
    int i, length = baseList.size();
    for (i = 0; i < position; i++)
    {
        newList.push_back(baseList.front());
        baseList.pop_front();
    }

    newList.push_back(value);

    for (i = position; i < length; i++)
    {
        newList.push_back(baseList.front());
        baseList.pop_front();
    }

    baseList = newList;
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int itemCount = ReadNaturalNum();

    list<char*> items = NewList(itemCount);
    PrintList(items);

    cout << NEW_INPUT_MESSAGE << endl;
    int index = ReadNaturalNum();

    AddNewItem(items, "KONICHIWA", index);
    PrintList(items);

    system("pause");
    return 0;
}