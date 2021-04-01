#include "ListInt.h"
#include "SizeExeption.h"
#include "NotEqualLengthExeption.h"
#include "IndexAccessExeption.h"
#include <iostream>
using namespace std;

const int MAX_LENGTH = 30;

ListInt::ListInt(int length, int fillValue)
{
    if ((length > MAX_LENGTH) || (length <= 0))
        throw SizeExeption();

    _length = length;
    _data = new int[_length];

    for (int i = 0; i < _length; i++)
        _data[i] = fillValue;
}

ListInt::ListInt(const ListInt& copied)
{
    _length = copied._length;
    _data = new int[_length];

    for (int i = 0; i < _length; i++)
        _data[i] = copied._data[i];
}

ListInt::~ListInt()
{
    delete[] _data;
    _data = nullptr;
}

int& ListInt::operator[](int index)
{
    if ((index < 0) || (index >= _length))
        throw IndexAccessExeption();

    return _data[index];
}

ListInt& ListInt::operator=(const ListInt& assigned)
{
    _length = assigned._length;

    delete[] _data;
    _data = new int[_length];

    for (int i = 0; i < _length; i++)
        _data[i] = assigned._data[i];

    return *this;
}

ListInt ListInt::operator+(const ListInt& adder)
{
    if (_length != adder._length)
        throw NotEqualLengthExeption();

    ListInt temporarilyList(_length, 0);
    for (int i = 0; i < _length; i++)
        temporarilyList[i] = _data[i] + adder._data[i];

    return temporarilyList;
}