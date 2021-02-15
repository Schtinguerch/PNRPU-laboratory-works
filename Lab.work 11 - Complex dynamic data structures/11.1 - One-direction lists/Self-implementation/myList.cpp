#include <iostream>
#define LENGTH_ERROR "Error: the list could't be created, incorrect length value."
#define INPUT_MESSAGE "Enter item's count of new list:"

using namespace std;

struct List 
{
    int item;
    List* nextItem;
};

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

List* NewRandomList(int listLength)
{
    if (listLength <= 0)
    {
        cout << LENGTH_ERROR << endl;
        return 0;
    }
    else 
    {
        List
            *firstItem, 
            *workList;
        
        workList = new List;
        workList->item = rand();
        firstItem = workList;

        for (int i = 1; i < listLength; i++)
        {
            List* h = new List;
            workList->nextItem = h;
            delete h;

            workList = workList->nextItem;
            workList->item = rand();
            workList->nextItem = NULL;
        }

        return firstItem;
    }
}

void PrintList(List* list)
{
    List* workItem = list;
    while (workItem != NULL)
    {
        cout << workItem->item << ' ';
        workItem = workItem->nextItem;
    }
    cout << endl;
}

void DeleteFirstOddItem(List* list)
{
    List* p = list;
    
    while (p->nextItem != NULL) 
    {
        if (p->nextItem->item % 2 == 0)
        {
            List* q = p->nextItem;
            p->nextItem = p->nextItem->nextItem;
            delete q;
            break;
        }
        else
            p = p->nextItem;
    }
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int itemsCount = ReadNaturalNum();

    List* items = NewRandomList(itemsCount);
    PrintList(items);

    DeleteFirstOddItem(items);
    PrintList(items);

    system("pause");
    return 0;
}