#pragma once
#include <iostream>

using namespace std;

class Triad
{
protected:
	int _first;
	int _second;
	int _third;

public:
	int First() { return _first; }
	int Second() { return _second; }
	int Third() { return _third; }

	virtual void SetTriad(int first, int second, int third);
	virtual void SetFirst(int first);
	virtual void SetSecond(int second);
	virtual void SetThird(int third);

	virtual void IncFirst();
	virtual void IncSecond();
	virtual void IncThird();

	Triad& operator=(Triad& triad);
	friend istream& operator>>(istream& input, Triad& triad);
	friend ostream& operator<<(ostream& output, Triad& triad);

	Triad();
	Triad(int first, int second, int third);
	Triad(Triad& copied);
};