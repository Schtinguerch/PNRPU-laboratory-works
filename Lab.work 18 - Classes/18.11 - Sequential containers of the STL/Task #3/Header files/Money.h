#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Money
{
private:
    long _dollars;
    int _cents;

public:
    int Dollars() { return _dollars; }
    void SetDollars(long dollars);

    int Cents() { return _cents; }
    void SetCents(int cents);

    void PrintMoney();

    friend bool operator > (Money& first, Money& second);
    friend bool operator < (Money& first, Money& second);
    friend bool operator == (Money& first, Money& second);

    friend istream& operator >> (istream& in, Money& money);
    friend ostream& operator << (ostream& out, Money& money);

    friend fstream& operator >> (fstream& fin, Money& money);
    friend fstream& operator << (fstream& fout, Money& money);

    Money& operator++ ();
    Money operator++ (int);

    Money& operator = (const Money& value);
    Money& operator += (Money& adder);
    Money& operator -= (Money& subtractor);
    Money& operator / (Money& divider);
    Money& operator /= (int divider);

    Money();
    Money(long dollars, int cents);
    Money(const Money& parentMoney);

    ~Money();
};