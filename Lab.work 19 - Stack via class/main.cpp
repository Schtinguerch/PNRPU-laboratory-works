#include "Money.h"
#include "UserStack.h"
#include <iostream>

#define INPUT_MESSAGE "Enter item's count of new stack:"
using namespace std;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

Stack<int> NewRandomStack(int stackLength)
{
    Stack<int> newStack(stackLength);
    for (int i = 0; i < stackLength; i++)
        newStack.Push(rand());

    return newStack;
}

void DeleteFirstOdd(Stack<int>& baseStack)
{
    bool deletedOdd = false;
    int length = baseStack.Size();

    int firstNum = baseStack.Peek(baseStack.getTop());

    Stack<int> newStack(length - 1);
    for (int i = 0; i < length; i++)
    {
        if ((baseStack.getPtr()[baseStack.getTop()] % 2 == 0) && !deletedOdd)
            deletedOdd = true;
        else
        {
            newStack.Push(baseStack.getPtr()[baseStack.getTop()]);
        }

        baseStack.Pop();
    }

    if (deletedOdd)
        length--;

    baseStack.Push(firstNum);
    newStack.Pop();

    for (int i = 1; i < length; i++)
    {
        baseStack.Push(newStack.getPtr()[newStack.getTop()]);
        newStack.Pop();
    }
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int length = ReadNaturalNum();

    Stack<int> newStack = NewRandomStack(length);
    newStack.printStack();

    DeleteFirstOdd(newStack);

    cout << "\n\n";
    newStack.printStack();

    return 0;
}