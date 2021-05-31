#include "Time.h"
#include <iostream>

using namespace std;

Time&Time::operator=(const Time&t)
{
    if(&t == this)
        return *this;

    _minutes = t._minutes;
    _seconds = t._seconds;
    return *this;
}

Time&Time::operator++()
{
    int temp=_minutes * 60 + _seconds;
    temp++;

    _minutes = temp / 60;
    _seconds = temp % 60;
    return *this;
}

Time Time::operator ++(int)
{
    int temp = _minutes * 60 + _seconds;
    temp++;
    Time t(_minutes, _seconds);

    _minutes = temp / 60;
    _seconds = temp % 60;
    return t;
}

Time Time::operator+(const Time&t)
{
    int temp1= _minutes * 60 + _seconds;
    int temp2 = t._minutes * 60 + t._seconds;

    Time p;
    p._minutes = (temp1 + temp2) / 60;
    p._seconds = (temp1 + temp2) % 60;
    return p;
}

Time Time::operator/(const int t)
{
    int temps = _seconds;
    int tempm = _minutes;

    Time p;
    p._minutes = tempm/t;
    p._seconds = temps/t;
    return p;
}

Time Time::operator / (const Time&t)
{
    int temps = _seconds;
    int tempm = _minutes;

    Time p;
    if (t._minutes != 0)
        p._minutes = tempm / t._minutes;
    else
        p._minutes = tempm;

    if (t._seconds != 0)
        p._seconds = temps / t._seconds;
    else
        p._seconds = temps;

    return p;
}

bool Time::operator<(const Time&t)
{
    if (_minutes==t._minutes)
    {
        if (_seconds <t._seconds)
            return true;
        else
            return false;
    }
    else
    {
        if (_minutes < t._minutes)
            return true;
        else
            return false;
    }
}

//перегрузка операции больше
bool Time::operator>(const Time&t)
{
    if (_minutes ==t._minutes)
    {
        if (_seconds > t._seconds)
            return true;
        else
            return false;
    }
    else
    {
        if (_minutes > t._minutes)
            return true;
        else
            return false;
    }
}


//перегрузка операции сравнения
bool Time::operator==(const Time&t)
{
    if (t._seconds== _seconds && t._minutes== _minutes)
        return true;
    else
        return false;
}

//перегрузка глобальной функции-операции ввода
istream&operator>>(istream&in, Time&t)
{
    cout << "Minutes: ";
    in >> t._minutes;

    cout << "Seconds: ";
    in >> t._seconds;

    return in;
}

//перегрузка глобальной функции-операции вывода
ostream&operator<<(ostream&out, const Time&t)
{
    return (out << t._minutes << " : " << t._seconds);
}


