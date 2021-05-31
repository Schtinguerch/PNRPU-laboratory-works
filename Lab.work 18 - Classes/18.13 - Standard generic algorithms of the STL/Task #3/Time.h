#pragma once
#include <iostream>

using namespace std;

class Time
{
private:
    int 
        _minutes, 
        _seconds;

public:

    Time()
    {
        _minutes=0;
        _seconds=0;
    };

    Time(int m, int s)
    {
        _minutes = m;
        _seconds = s;
    }

    Time(const Time&t)
    {
        _minutes = t._minutes;
        _seconds = t._seconds;
    }

    ~Time(){};

    int GetMin() { return _minutes; }
    int GetSec() { return _seconds; }

    void SetMin(int m) { _minutes = m; }
    void SetSet(int s) { _seconds = s; }

    Time&operator=(const Time&);

    Time& operator++();
    Time operator++(int);

    Time operator+(const Time&);
    bool operator==(const Time&);

    Time operator/(const int t);
    Time operator/(const Time&);

    bool operator<(const Time&);
    bool operator>(const Time&);

    friend istream& operator>>(istream&in, Time&t);
    friend ostream& operator<<(ostream&out, const Time&t);
};

