#include "Money.h"
#include <string>
using namespace std;

void Money::SetDollars(long dollars)
{
    if (dollars < 0)
    {
        cout << "Error: dollars less than 0;\n";
        _dollars = 0;
    }

    else
        _dollars = dollars;
}

void Money::SetCents(int cents)
{
    if (cents < 0 || cents >= 100)
    {
        cout << "Error: cents less than 0 or bigger than 100;\n";
        _cents = 0;
    }

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

Money::Money(const Money& parentMoney)
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

istream& operator>>(istream& in, Money& money)
{
    long dollars;
    int cents;

    cout << "dollars: ";
    cin >> dollars;

    cout << "cents";
    cin >> cents;

    money.SetDollars(dollars);
    money.SetCents(cents);
    return in;
}

ostream& operator<<(ostream& out, Money& money)
{
    money.PrintMoney();
    return out;
}

fstream& operator>>(fstream& fin, Money& money)
{
    long dollars;
    int cents;
    fin >> dollars >> cents;

    money.SetDollars(dollars);
    money.SetCents(cents);
    return fin;
}

fstream& operator<<(fstream& fout, Money& money)
{
    fout << money.Dollars() << endl << money.Cents() << endl;
    return fout;
}

bool operator==(Money& first, Money& second)
{
    return (first.Dollars() == second.Dollars()) && (first.Cents() == second.Cents());
}

Money& Money::operator+=(Money& adder)
{
    int addedCents = _cents + adder._cents;
    if (addedCents >= 100)
    {
        _dollars++;
        addedCents -= 100;
    }

    _dollars += adder._dollars;
    _cents = addedCents;

    return *this;
}

Money& Money::operator-=(Money& subtractor)
{
    this->SetCents(_cents - subtractor.Cents());
    this->SetDollars(_dollars - subtractor.Dollars());

    return *this;
}

Money& Money::operator=(const Money& value)
{
    this->SetDollars(value._dollars);
    this->SetCents(value._cents);

    return *this;
}

Money &Money::operator/=(const Money &divider)
{
    int dollars = this->_dollars;
    int cents = this->_cents;

    if (dollars / divider._dollars != 0)
        cents += 100;

    this->SetDollars(dollars / divider._dollars);
    this->SetCents(cents / divider._dollars);

    return *this;
}
