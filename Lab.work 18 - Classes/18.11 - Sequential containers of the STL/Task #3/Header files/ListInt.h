#pragma once
#include <iostream>
using namespace std;

template <class T>
class ListInt
{
private:
	T* _data;
	int _length;

	void MakeList(int length, T fillValue);

public:
	ListInt();
	ListInt(int length, T fillValue);
	ListInt(const ListInt<T>& copied);
	~ListInt();

	void PrintData();
	void PrintItem(int index);

	void InputData();
	void ReInputItem(int index);

	void FindAverageAndPushFront();
	void FindAndDelete(T key);
	void SubtractByMinValue();

	void DeleteByIndex(int index);

	T& operator [] (int index);
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
	_data = new T[_length];

	for (int i = 0; i < _length; i++)
		_data[i] = fillValue;
}

template<class T>
ListInt<T>::ListInt()
{
	_length = 1;
	_data = new T[_length];
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

template<class T>
void ListInt<T>::PrintData()
{
	cout << "\nCount of items = " << _length << ":\n";
	
	for (int i = 0; i < _length; i++)
		PrintItem(i);
}

template<class T>
void ListInt<T>::PrintItem(int index)
{
	cout << "Item #" << index + 1 << ":\n";
	cout << _data[index] << endl;
}

template<class T>
void ListInt<T>::InputData()
{
	cout << "Enter the count of items: ";
	int count;
	cin >> count;

	_length = count;
	_data = new T[count];

	for (int i = 0; i < count; i++)
		ReInputItem(i);
}

template<class T>
void ListInt<T>::ReInputItem(int index)
{
	cin >> _data[index];
}

template<class T>
void ListInt<T>::FindAverageAndPushFront()
{
	T average = _data[0];
	
	for (int i = 1; i < _length; i++)
		average += _data[i];
	

	average /= _length;

	_length++;
	T* newData = new T[_length];

	newData[0] = average;

	for (int i = 0; i < _length - 1; i++)
		newData[i + 1] = _data[i];

	delete[] _data;
	_data = newData;
}

template<class T>
void ListInt<T>::FindAndDelete(T key)
{
	for (int i = _length - 1; i >= 0; i--)
		if (_data[i] == key)
			DeleteByIndex(i - 1);
}

template<class T>
void ListInt<T>::SubtractByMinValue()
{
	T minValue = _data[0];
	for (int i = 1; i < _length; i++)
		if (_data[i] < minValue)
			minValue = _data[i];

	for (int i = 0; i < _length; i++)
		_data[i] -= minValue;
}

template<class T>
void ListInt<T>::DeleteByIndex(int index)
{
	T* newData = new T[_length - 1];
	int offset = 0;

	for (int i = 0; i < _length; i++)
	{
		if (i == index + 1)
			offset++;
		else
			newData[i - offset] = _data[i];
	}

	_length--;
	_data = newData;
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