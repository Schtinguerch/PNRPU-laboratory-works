#include <iostream>

#define LENGTH_ERROR "Error: the list could't be created, incorrect length value."
#define INPUT_MESSAGE "Enter item's count of new list:"
#define NEW_INPUT_MESSAGE "Enter list's index where you'll add new word:"

using namespace std;

struct List2
{
    char* item; 
    List2 *nextItem; 
    List2 *prevItem; 
};

List2 *head;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

void Add(char* value, int position)
{
    List2 *node = new List2; 
    node->item = value;
    if (head == NULL)
    {
        node->nextItem = node;
        node->prevItem = node;
        head = node;
    }
    else
    {
        List2* p = head;
        for(int i = position; i > 1; i--) 
            p = p->nextItem;

        p->prevItem->nextItem = node;
        node->prevItem = p->prevItem;
        node->nextItem = p;
        p->prevItem = node;
    }
}

void InitializeNewList(int length)
{
    if (length <= 0)
        cout << LENGTH_ERROR << endl;

    else
        for (int i = 1; i <= length; i++)
            Add("hello", i);
}

void PrintList()
{
    List2* printList = head;
    do
    {
        cout<< printList->item << ' ';
        printList = printList->nextItem;
    } 
    while(printList != head); 
    
    cout << endl;
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int itemCount = ReadNaturalNum();

    InitializeNewList(itemCount);
    PrintList();

    cout << NEW_INPUT_MESSAGE << endl;
    int index = ReadNaturalNum();

    Add("KONICHIWA", index);
    PrintList();

    system("pause");
    return 0;
}