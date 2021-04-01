#pragma once
#include "Triad.h"
#include <iostream>

using namespace std;

class Time : public Triad
{
public:
	int Hour() { return _first; }
	int Minute() { return _second; }
	int Second() { return _third; }

	void SetFirst(int first);
	void SetSecond(int second);
	void SetThird(int third);
	void SetTriad(int first, int second, int third);

	void IncFirst();
	void IncSecond();
	void IncThird();

	friend istream& operator>>(istream& input, Time& time);
	friend ostream& operator<<(ostream& output, Time& time);

	Time();
	Time(int first, int second, int third);
	Time(Time& copied);
};