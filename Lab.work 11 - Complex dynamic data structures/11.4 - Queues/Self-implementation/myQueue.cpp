#include <iostream>
#define LENGTH_ERROR "Error: the queue could't be created, incorrect length value."
#define INPUT_MESSAGE "Enter item's count of new queue:"
#define NEW_INPUT_MESSAGE "Enter queue's index where you'll add new word:"

using namespace std;

struct Queue
{
    char* item;
    Queue* nextItem;
};

int _queueLength = 0;

void Push(Queue*& lastItem, char* word)
{
    Queue* workQueue = new Queue;
    workQueue->item = word;
    workQueue->nextItem = lastItem;
    lastItem = workQueue;
}

void Pop(Queue*& firstItem, Queue*& lastItem)
{
    Queue* workQueue = lastItem;
    int length = 0;
    while (workQueue != NULL) 
    {
        length++;
        workQueue = workQueue->nextItem;
    }

    if (length == 1)
    {
        char* t = lastItem->item;
        delete workQueue;

        firstItem = NULL;
        lastItem = NULL;
    }
    else
    {
        while (workQueue->nextItem->nextItem != NULL)
            workQueue = workQueue->nextItem;
        
        Queue* tempQueue = workQueue;
        workQueue = workQueue->nextItem;
        tempQueue->nextItem = NULL;
        firstItem = tempQueue;

        delete workQueue;
    }
}

Queue* NewQueue(int queueLength, Queue*& firstItem, Queue*& lastItem)
{
    if (queueLength <= 0)
    {
        cout << LENGTH_ERROR << endl;
        return NULL;
    }
    else 
    {
        Queue* p = new Queue;
        p->item = "hello";
        p->nextItem = NULL;
        firstItem = p;
        lastItem = p;

        for (int i = 1; i < queueLength; i++)
        {
            Queue* h = new Queue;
            h->item = "hello";
            h->nextItem = p;

            lastItem = h;
            p = lastItem;
        }
    }

    return firstItem;
}

void PrintQueue(Queue* lastItem)
{
    Queue* workQueue = lastItem;
    while (workQueue != NULL)
    {
        cout << workQueue->item << "     ";
        workQueue = workQueue->nextItem;
    }
    cout << endl;
}

void AddNewItem(Queue*& firstItem, Queue*& lastItem, int index)
{
    index--;
    Queue* newQueue = new Queue;
    newQueue->item = "";
    newQueue->nextItem = NULL;
    int pos = -1;
    for (int i = 0; i < index; i++)
    {
        Push(newQueue, firstItem->item);
        pos++;
    }

    Push(newQueue, "KONICHIWA");

    for (int i = pos + 1; i < _queueLength; i++)
    {
        Push(newQueue, firstItem->item);
    }

    lastItem = newQueue;
}

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int length = ReadNaturalNum();
    _queueLength = length;

    Queue* firstItem, *lastItem;
    NewQueue(length, firstItem, lastItem);
    PrintQueue(lastItem);

    cout << NEW_INPUT_MESSAGE << endl;
    int index = ReadNaturalNum();

    AddNewItem(firstItem, lastItem, _queueLength - index + 2);
    PrintQueue(lastItem);

    system("pause");
    return 0;
}