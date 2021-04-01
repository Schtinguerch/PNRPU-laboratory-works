#include <iostream>
#include <string>
#include "../Header files/Triad.h"

void Triad::SetTriad(int first, int second, int third)
{
	_first = first;
	_second = second;
	_third = third;
}

void Triad::SetFirst(int first)
{
	_first = first;
}

void Triad::SetSecond(int second)
{
	_second = second;
}

void Triad::SetThird(int third)
{
	_third = third;
}

void Triad::IncFirst()
{
	_first++;
}

void Triad::IncSecond()
{
	_second++;
}

void Triad::IncThird()
{
	_third++;
}

Triad& Triad::operator=(Triad& triad)
{
	_first = triad._first;
	_second = triad._second;
	_third = triad._third;

	return *this;
}

std::istream& operator>>(std::istream& input, Triad& triad)
{
	int
		first,
		second,
		third;

	std::cout << "Enter the first number:  ";
	input >> first;
	
	std::cout << "Enter the second number: ";
	input >> second;

	std::cout << "Enter the third number:  ";
	input >> third;

	triad.SetTriad(first, second, third);

	return input;
}

std::ostream& operator<<(std::ostream& output, Triad& triad)
{
	output << "First =  " << triad.First() << std::endl;
	output << "Second = " << triad.Second() << std::endl;
	output << "Third =  " << triad.Third() << std::endl << std::endl;

	return output;
}

Triad::Triad()
{
	_first = 0;
	_second = 0;
	_third = 0;
}

Triad::Triad(int first, int second, int third)
{
	SetTriad(first, second, third);
}

Triad::Triad(Triad& copied)
{
	_first = copied._first;
	_second = copied._second;
	_third = copied._third;
}