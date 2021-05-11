#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <class T>
class ListInt
{
private:
    queue<T> _data;
    int _length;

    void MakeList(int length, T fillValue);

public:
    ListInt();
    ListInt(int length, T fillValue);
    ListInt(const ListInt<T>& copied);
    ~ListInt();

    void PrintData();
    void InputData();

    void FindAverageAndPushFront();
    void FindAndDelete(T key);
    void SubtractByMinValue();

    ListInt& operator = (const ListInt<T>& assigned);
    ListInt operator + (const ListInt<T>& adder);

    template <class T>
    friend istream& operator >> (istream& in, ListInt& list);

    template <class T>
    friend ostream& operator << (ostream& out, ListInt& list);

    int Length() { return _length; }
};

template<class T>
void ListInt<T>::MakeList(int length, T fillValue)
{
    _length = length;

    for (int i = 0; i < _length; i++)
        _data.push(fillValue);
}

template<class T>
ListInt<T>::ListInt()
{
    _length = 0;
}

template<class T>
ListInt<T>::ListInt(int length, T fillValue)
{
    MakeList(length, fillValue);
}

template<class T>
ListInt<T>::ListInt(const ListInt<T>& copied)
{
    _length = copied._length;
    _data = copied._data;
}

template<class T>
ListInt<T>::~ListInt()
{

}

template<class T>
void ListInt<T>::PrintData()
{
    cout << "\nCount of items = " << _length << ":\n";

    queue<T> copiedQueue = _data;
    for (int i = 0; i < _length; i++)
    {
        cout << copiedQueue.front() << endl;
        copiedQueue.pop();
    }
}

template<class T>
void ListInt<T>::InputData()
{
    cout << "Enter the count of items: ";
    int count;
    cin >> count;

    _length = count;

    for (int i = 0; i < count; i++)
    {
        T newItem;
        cin >> newItem;
        _data.push(newItem);
    }
}

template<class T>
void ListInt<T>::FindAverageAndPushFront()
{
    T summ = _data.front();
    summ -= _data.front();

    int count = _data.size();

    queue<T> buffer;

    for (int i = 0; i < count; i++)
    {
        summ += _data.front();
        buffer.push(_data.front());

        _data.pop();
    }

    T average = summ / count;
    cout << "Average value = " << average << endl;

    _data.push(average);

    for (int i = 0; i < count; i++)
    {
        _data.push(buffer.front());
        buffer.pop();
    }

    _length++;
}

template<class T>
void ListInt<T>::FindAndDelete(T key)
{
    queue<T> buffer;
    int count = _data.size();

    for (int i = 0; i < count; i++)
    {
        if (_data.front() != key)
            buffer.push(_data.front());
        else
            cout << "Item found: index = " << i + 1 << ";\n";

        _data.pop();
    }

    _data = buffer;
    _length = buffer.size();
}

template<class T>
void ListInt<T>::SubtractByMinValue()
{
    queue<T> buffer = _data;
    T minValue = buffer.front();
    int count = _data.size();

    for (int i = 0; i < count; i++)
    {
        if (buffer.front() < minValue)
            minValue = buffer.front();

        buffer.pop();
    }

    for (int i = 0; i < count; i ++)
    {
        buffer.push(_data.front() - minValue);
        _data.pop();
    }

    _data = buffer;
}

template <class T>
ListInt<T>& ListInt<T>::operator=(const ListInt<T>& assigned)
{
    _length = assigned._length;

    delete[] _data;
    _data = new T[_length];

    for (int i = 0; i < _length; i++)
        _data[i] = assigned._data[i];

    return *this;
}

template <class T>
ListInt<T> ListInt<T>::operator+(const ListInt<T>& adder)
{
    try
    {
        if (_length != adder._length)
            throw - 1;

        ListInt<T> temporarilyList(_length, 0);
        for (int i = 0; i < _length; i++)
            temporarilyList[i] = _data[i] + adder._data[i];

        return temporarilyList;
    }

    catch (int code)
    {
        if (code == -1)
            cerr << "Error: list length are not the same;\n";

        return *this;
    }
}

template <class T>
istream& operator>>(istream& in, ListInt<T>& list)
{
    list.InputData();
    return in;
}

template <class T>
ostream& operator<<(ostream& out, ListInt<T>& list)
{
    list.PrintData();
    return out;
}