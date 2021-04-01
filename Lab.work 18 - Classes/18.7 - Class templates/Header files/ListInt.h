#pragma once
#include <iostream>
using namespace std;

template <class T>
class ListInt
{
private:
	T* _data;
	int _length;

public:
	ListInt(int length, T fillValue);
	ListInt(const ListInt<T>& copied);
	~ListInt();

	T& operator [] (int index);
	ListInt& operator = (const ListInt<T>& assigned);
	ListInt operator + (const ListInt<T>& adder);

	int Length() { return _length; }
};