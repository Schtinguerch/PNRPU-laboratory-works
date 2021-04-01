#pragma once
#include "ListIterator.h"

class ListInt
{
private:
	int* _data;
	int _length;

	ListIterator _begin;
	ListIterator _end;
	ListIterator _current;
	
public:
	ListInt(int length, int fillValue);
	ListInt(const ListInt& copied);
	~ListInt();

	ListIterator Begin() { return _begin; }
	ListIterator End() { return _end; }
	ListIterator SelectedItem() { return _current; }

	int& operator [] (int index);
	ListInt& operator = (const ListInt& assigned);
	ListInt operator + (const ListInt& adder);

	int Length() { return _length; }
	void MoveSelector(int offset);
};