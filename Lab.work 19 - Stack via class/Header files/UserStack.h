
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Stack
{
private:
    T *stackPtr;                      
    int size;
    int top;                          

public:
    Stack(int);
    Stack(const Stack<T> &);          
    ~Stack();                         

     void Push(const T & );     
     T Pop();                   
     void printStack();         
     const T &Peek(int ) const; 
     int Size() const;  
     T *getPtr() const;         
     int getTop() const;
};

template <typename T>
Stack<T>::Stack(int maxSize) :
        size(maxSize) 
{
    stackPtr = new T[size]; 
    top = 0; 
}


template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
        size(otherStack.Size()) 
{
    stackPtr = new T[size]; 
    top = otherStack.getTop();

    for(int i = 0; i < top; i++)
        stackPtr[i] = otherStack.getPtr()[i];
}


template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr;
}


template <typename T>
void Stack<T>::Push(const T &value)
{
    if (top < size)
        stackPtr[top++] = value;
    else
    {
        T* newStackPtr = new T[size + 1];
        for (int i = 0; i < size; i++)
            newStackPtr[i] = stackPtr[i];

        size += 1;

        stackPtr = newStackPtr;
        stackPtr[top++] = value;
    }
}


template <typename T>
T Stack<T>::Pop()
{
    if (top > 0)
    {
        stackPtr[--top];
    }

    else
        throw "Trying to pop the empty stack";
}


template <class T>
const T &Stack<T>::Peek(int nom) const
{
    
    assert(nom <= top);

    if (nom <= top)
        return stackPtr[top - nom];
    else
        throw "The incorrect index: out of area";
}


template <typename T>
 void Stack<T>::printStack()
{
    for (int i = top - 1; i >= 0; i--)
        cout << "#" << setw(3) << top - i << ": " << setw(4) << stackPtr[i] << ";\n";
}


template <typename T>
 int Stack<T>::Size() const
{
    return size;
}

template <typename T>
 T *Stack<T>::getPtr() const
{
    return stackPtr;
}


template <typename T>
 int Stack<T>::getTop() const
{
    return top;
}