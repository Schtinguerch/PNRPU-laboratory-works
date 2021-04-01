#include "..\Header files\ListInt.h"
#include <iostream>
using namespace std;

template<class T>
ListInt<T>::ListInt(int length, T fillValue)
{
	_length = length;
	_data = new T[_length];

	for (int i = 0; i < _length; i++)
		_data[i] = fillValue;
}

template<class T>
ListInt<T>::ListInt(const ListInt<T>& copied)
{
	_length = copied._length;
	_data = new T[_length];

	for (int i = 0; i < _length; i++)
		_data[i] = copied._data[i];
}

template<class T>
ListInt<T>::~ListInt()
{
	delete[] _data;
	_data = nullptr;
}

template <class T>
T& ListInt<T>::operator[](int index)
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

		return _data[0];
	}
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