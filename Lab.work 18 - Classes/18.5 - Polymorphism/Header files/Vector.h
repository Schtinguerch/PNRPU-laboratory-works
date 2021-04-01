#pragma once
#include "Triad.h"

class Vector
{
private:
	Triad** _begin;
	int _length;
	int _currentPosition;

public:
	Vector();
	Vector(int length);
	Vector(const Vector& copied);
	~Vector();

	void AddTriad(Triad* triad);
	void Print();
};

