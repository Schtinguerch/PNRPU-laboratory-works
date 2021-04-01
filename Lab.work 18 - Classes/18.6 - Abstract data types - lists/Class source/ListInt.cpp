#include "..\Header files\ListInt.h"
#include "..\Header files\ListIterator.h"
#include <iostream>

using namespace std;

ListInt::ListInt(int length, int fillValue)
{
	_length = length;
	_data = new int[_length];

	_begin._pointedElement = &_data[0];
	_end._pointedElement = &_data[_length - 1];
	_current = _begin;
	
	for (int i = 0; i < _length; i++)
		_data[i] = fillValue;
}

ListInt::ListInt(const ListInt& copied)
{
	_length = copied._length;
	_data = new int[_length];

	_begin = copied._begin;
	_current = copied._current;
	_end = copied._end;

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

	try
	{
		if (index < 0)
			throw - 1;
		if (index >= _length)
			throw 1;

		return _data[index];
	}

	catch (int code)
	{
		switch (code)
		{
		case -1:
			cerr << "Error: index is out of range => less than 0;\n";
			break;

		case 1:
			cerr << "Error: index is out of range => more than length;\n";
			break;
		}
	}
}

ListInt& ListInt::operator=(const ListInt& assigned)
{
	_length = assigned._length;

	delete[] _data;
	_data = new int[_length];

	_begin = assigned._begin;
	_current = assigned._current;
	_end = assigned._end;
	
	for (int i = 0; i < _length; i++)
		_data[i] = assigned._data[i];
	
	return *this;
}

ListInt ListInt::operator+(const ListInt& adder)
{
	try
	{
		if (_length != adder._length)
			throw - 1;

		ListInt temporarilyList(_length, 0);
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

void ListInt::MoveSelector(int offset)
{
	if (offset < 0)
		_current -= -offset;
	else
		_current += offset;
}
