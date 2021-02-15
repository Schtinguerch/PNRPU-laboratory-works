#include <iostream>
#include <list>
#include <iterator>

#define LENGTH_ERROR "Error: the list could't be created, incorrect length value."
#define INPUT_MESSAGE "Enter item's count of new list:"

using namespace std;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

list<int> NewRandomList(int listLength)
{
    if (listLength <= 0)
    {
        cout << LENGTH_ERROR << endl;
        return {};
    }
    else 
    {
        list<int> newList;
        for (int i = 0; i < listLength; i++)
            newList.push_back(rand());

        return newList;
    }
}

void PrintList(list<int>& printList) 
{
    list<int>::iterator item;
    for (item = printList.begin(); item != printList.end(); item++)
        cout << *item << ' ';

    cout << endl;
}

void DeleteFirstOddItem(list<int>& deleteList) 
{
    list<int>::iterator item;
    for (item = deleteList.begin(); item != deleteList.end(); item++)
        if (*item % 2 == 0)
        {
            deleteList.erase(item);
            break;
        }
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int itemsCount = ReadNaturalNum();

    list<int> items = NewRandomList(itemsCount);
    PrintList(items);

    DeleteFirstOddItem(items);
    PrintList(items);

    system("pause");
    return 0;
}