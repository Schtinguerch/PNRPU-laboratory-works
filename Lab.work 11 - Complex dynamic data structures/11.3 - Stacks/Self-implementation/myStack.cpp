#include <iostream>
#define LENGTH_ERROR "Error: the stack could't be created, incorrect length value."
#define INPUT_MESSAGE "Enter item's count of new stack:"

using namespace std;

struct Stack 
{ 
	int item; 
	Stack *nextItem;
};

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

void Push(Stack **topStack, int D) 
{ 
	Stack *q; 
	q = new Stack();
	q->item = D; 
	if (topStack == NULL)  
		*topStack = q; 
	
	else 
	{
		q->nextItem = *topStack; 
		*topStack = q; 
	}
}

void DeleteFirstOdd(Stack **stack) 
{
	Stack *q = *stack; 
	Stack *prev = NULL;
	while (q != NULL) 
    {
		if (q->item % 2 == 0) 
        {
			if (q == *stack) 
            {
				*stack = q->nextItem;
				free(q);
				q->item = NULL;
				q->nextItem = NULL;
			}

			else
			{
				prev->nextItem = q->nextItem;
				free(q);
				q->item = NULL;
				q->nextItem = NULL;
			}
            break;		
        }
		prev = q; 
		q = q->nextItem;
	}
}

void PrintStack(Stack *top) 
{ 		
	Stack *q = top; 
	while (q) 
    { 
		cout << q->item << '\t';
		q = q->nextItem;
	}

    cout << endl;
}

void InitiateNewRandomStack(Stack** stack ,int stackLength)
{
    for (int i = 0; i < stackLength; i++)
        Push(stack, rand());
}

int main() {
	Stack *stack = NULL;
	
    cout << INPUT_MESSAGE << endl;
    int length = ReadNaturalNum();
    InitiateNewRandomStack(&stack, length);

	PrintStack(stack);

	DeleteFirstOdd(&stack);
	PrintStack(stack);

	system("pause");
    return 0;
}