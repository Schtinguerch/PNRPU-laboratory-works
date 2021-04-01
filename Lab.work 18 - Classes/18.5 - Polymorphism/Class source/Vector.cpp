#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
	_begin = nullptr;
	_length = 0;
	_currentPosition = 0;
}

Vector::Vector(int length)
{
	_length = length;
	_begin = new Triad* [_length];
	_currentPosition = 0;
}

Vector::Vector(const Vector& copied)
{
	_length = copied._length;
	_currentPosition = copied._currentPosition;

	if (_length != 0)
	{
		_begin = new Triad * [_length];
		for (int i = 0; i < _length; i++)
			_begin[i] = copied._begin[i];
	}
}

Vector::~Vector()
{
	if (_length != 0)
		delete[] _begin;

	_begin = nullptr;
}

void Vector::AddTriad(Triad* triad)
{
	if (_currentPosition < _length)
	{
		_begin[_currentPosition] = triad;
		_currentPosition++;
	}
}

void Vector::Print()
{
	for (int i = 0; i < _currentPosition; i++)
		cout << *(_begin[i]);

	cout << endl;
}
