#include <iostream>
#include <stack>
#define INPUT_MESSAGE "Enter item's count of new stack:"

using namespace std;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

stack<int> NewRandomStack(int stackLength)
{
    stack<int> newStack;
    for (int i = 0; i < stackLength; i++)
        newStack.push(rand());

    return newStack;
}

void PrintStack(stack<int> stack)
{
    int length = stack.size();
    for (int i = 0; i < length; i++)
    {
        cout << stack.top() << ' ';
        stack.pop();
    }

    cout << endl;
}

void DeleteFirstOdd(stack<int>& baseStack)
{
    bool deletedOdd = false;
    int length = baseStack.size();

    stack<int> newStack;
    for (int i = 0; i < length; i++)
    {
        if ((baseStack.top() % 2 == 0) && !deletedOdd)
            deletedOdd = true;
        else 
            newStack.push(baseStack.top());

        baseStack.pop();
    }

    if (deletedOdd)
        length--;

    for (int i = 0; i < length; i++)
    {
        baseStack.push(newStack.top());
        newStack.pop();
    }
}

int main()
{
    cout << INPUT_MESSAGE << endl;
    int length = ReadNaturalNum();

    stack<int> stack = NewRandomStack(length);
    PrintStack(stack);

    DeleteFirstOdd(stack);
    PrintStack(stack);

    system("pause");
    return 0;
}