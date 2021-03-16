#include "Money.h"
#include <string>
#include <iostream>
using namespace std;

void Money::SetDollars(long dollars)
{
    if (dollars < 0)
        cout << "Error: dollars less than 0;\n";
    else
        _dollars = dollars;
}

void Money::SetCents(int cents)
{
    if (cents < 0 || cents > 100)
        cout << "Error: cents less than 0 or bigger than 100;\n";
    else
        _cents = cents;
}

void Money::PrintMoney()
{
    string centStr = (_cents < 10) ? '0' + to_string(_cents) : to_string(_cents);

    cout << "Money value = " << _dollars << '.' << centStr << "$;\n";
}

Money& Money::operator++()
{
    _cents++;
    if (_cents == 100)
    {
        _cents = 0;
        _dollars++;
    }
    return *this;
}

Money Money::operator++(int)
{
    Money temp(_dollars, _cents);
    ++(*this);
    return temp;
}

Money::Money()
{
    _dollars = 0;
    _cents = 0;
}

Money::Money(long dollars, int cents)
{
    SetDollars(dollars);
    SetCents(cents);
}

Money::Money(Money& parentMoney)
{
    _dollars = parentMoney._dollars;
    _cents = parentMoney._cents;
}

Money::~Money() {}

bool operator>(Money& first, Money& second)
{
    if (first.Dollars() == second.Dollars())
        return first.Cents() > second.Cents();
    else
        return first.Dollars() > second.Dollars();
}

bool operator<(Money& first, Money& second)
{
    if (first.Dollars() == second.Dollars())
        return first.Cents() < second.Cents();
    else
        return first.Dollars() < second.Dollars();
}
