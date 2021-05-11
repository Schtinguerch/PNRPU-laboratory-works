#include <queue>
#include <math.h>
#include <iostream>
using namespace std;

float RandomFloat(float minValue, float maxValue)
{
    return minValue + static_cast <float> (rand()) /
                      (static_cast <float>(RAND_MAX / (maxValue-minValue)));
}


void CreateRandomQueue(queue<float>& procQueue, int count)
{
    for (int i = 0; i < count; i++)
        procQueue.push(RandomFloat(0, 1000));
}

void PrintQueue(queue<float> printQueue)
{
    int count = printQueue.size();
    cout << "\nCount of the queue = " << count << ":\n\n";

    for (int i = 0; i < count; i++)
    {
        cout << "- #" << i + 1 << " = " << printQueue.front() << ";\n";
        printQueue.pop();
    }

    cout << endl;
}

void FindAverageAndPushFront(queue<float>& procQueue)
{
    float summ = 0;
    int count = procQueue.size();

    queue<float> buffer;

    for (int i = 0; i < count; i++)
    {
        summ += procQueue.front();
        buffer.push(procQueue.front());

        procQueue.pop();
    }

    float average = summ / count;
    cout << "Average value = " << average << endl;

    procQueue.push(average);

    for (int i = 0; i < count; i++)
    {
        procQueue.push(buffer.front());
        buffer.pop();
    }
}

bool IsFloatEqual(float first, float second)
{
    return (abs(first - second) < 0.001);
}

void FindAndDelete(queue<float>& procQueue, float key)
{
    queue<float> buffer;
    int count = procQueue.size();

    for (int i = 0; i < count; i++)
    {
        if (!IsFloatEqual(procQueue.front(), key))
            buffer.push(procQueue.front());
        else
            cout << "Item found: index = " << i + 1 << ";\n";

        procQueue.pop();
    }

    procQueue = buffer;
}

void SubtractMinValue(queue<float>& procQueue)
{
    queue<float> buffer = procQueue;
    float minValue = buffer.front();
    int count = procQueue.size();

    for (int i = 0; i < count; i++)
    {
        if (buffer.front() < minValue)
            minValue = buffer.front();

        buffer.pop();
    }

    for (int i = 0; i < count; i ++)
    {
        buffer.push(procQueue.front() - minValue);
        procQueue.pop();
    }

    procQueue = buffer;
}


int main()
{
    queue<float> floatQueue;

    CreateRandomQueue(floatQueue, 18);
    PrintQueue(floatQueue);

    FindAverageAndPushFront(floatQueue);
    PrintQueue(floatQueue);

    float key;
    cout << "Enter the number, which you wanna to delete:";
    cin >> key;

    FindAndDelete(floatQueue, key);
    PrintQueue(floatQueue);

    SubtractMinValue(floatQueue);
    PrintQueue(floatQueue);

    return 0;
}