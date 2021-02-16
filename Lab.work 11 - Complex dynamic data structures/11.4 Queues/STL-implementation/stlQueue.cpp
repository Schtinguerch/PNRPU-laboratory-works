#include <iostream>
#include <queue>
#define INPUT_MESSAGE "Enter item's count of new queue:"
#define NEW_INPUT_MESSAGE "Enter queue's index where you'll add new word:"

using namespace std;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

queue<char*> NewQueue(int queueLength)
{
    queue<char*> newQueue;
    
    for (int i = 0; i < queueLength; i++)
        newQueue.push("hello");

    return newQueue;
}

void PrintQueue(queue<char*> queue) 
{
    while (!queue.empty()) 
    {
        cout << queue.front() << ' ';
        queue.pop();
    }
    cout << endl;
}

void AddNewItem(queue<char*>& baseQueue, int index)
{
    queue<char*> newQueue;

    int i = 0;
    while (!baseQueue.empty())
    {
        i++;
        if (i != index)
        {
            newQueue.push(baseQueue.front());
            baseQueue.pop();
        }
        else
        {
            newQueue.push("KONICHIWA");
        }
    }

    baseQueue = newQueue;
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int itemCount = ReadNaturalNum();

    queue<char*> queue = NewQueue(itemCount);
    PrintQueue(queue);

    cout << NEW_INPUT_MESSAGE << endl;
    int index = ReadNaturalNum();

    AddNewItem(queue, index);
    PrintQueue(queue);

    system("pause");
    return 0;
}