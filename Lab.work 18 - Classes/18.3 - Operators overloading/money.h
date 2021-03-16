#pragma once
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
    Money& operator++ ();
    Money operator++ (int);
    
    Money();
    Money(long dollars, int cents);
    Money(Money& parentMoney);

    ~Money();
};