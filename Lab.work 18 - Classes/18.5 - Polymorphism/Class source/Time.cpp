#include "Time.h"
#include <iostream>
#include "Time.h"

void Time::SetFirst(int first)
{
	_first = first % 24;
}

void Time::SetSecond(int second)
{
	if (second >= 0)
	{
		if (second >= 60)
		{
			SetFirst(_first + second / 60);
			_second = second % 60;
		}

		else
			_second = second;
	}

	else
		cout << "Error: invalid value = " << second << "!\n";
}

void Time::SetThird(int third)
{
	if (third >= 0)
	{
		if (third >= 60)
		{
			SetSecond(_second + third / 60);
			_third = third % 60;
		}

		else
			_third = third;
	}

	else
		cout << "Error: invalid value = " << third << "!\n";
}

void Time::SetTriad(int first, int second, int third)
{
	SetFirst(first);
	SetSecond(second);
	SetThird(third);
}

void Time::IncFirst()
{
	SetFirst(_first + 1);
}

void Time::IncSecond()
{
	SetSecond(_second + 1);
}

void Time::IncThird()
{
	SetThird(_third + 1);
}

Time::Time()
{
	_first = 0;
	_second = 0;
	_third = 0;
}

Time::Time(int first, int second, int third)
{
	SetTriad(first, second, third);
}

Time::Time(Time& copied)
{
	_first = copied._first;
	_second = copied._second;
	_third = copied._third;
}

istream& operator>>(istream& input, Time& time)
{
	int
		first,
		second,
		third;

	std::cout << "Enter hours:   ";
	input >> first;

	std::cout << "Enter minutes: ";
	input >> second;

	std::cout << "Enter seconds: ";
	input >> third;

	time.SetTriad(first, second, third);

	return input;
}

ostream& operator<<(ostream& output, Time& time)
{
	output << "Time = " << time.Hour() << ':' << time.Minute() << ':' << time.Second() << ' ';
	return output;
}
