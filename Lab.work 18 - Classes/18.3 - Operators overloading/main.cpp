#include <iostream>
#include <windows.h>
#include <string>
#include "Money.h"

using namespace std;

Money _first, _second;

int InputNaturalNum()
{
    int number;
    do cin >> number; while (number < 1);
    return number;
}

string ReadLine() 
{
    string s;
    getline(cin, s);
    return s;
}

Money ReadMoneyData()
{
    cout << "dollars> ";
    int dollars = InputNaturalNum();

    cout << "cents>   ";
    int cents;
    do
        cents = InputNaturalNum();
    while (cents >= 100);

    Money money(dollars, cents);
    return money;
}

void PrintMoney()
{
    cout << "First: ";
    _first.PrintMoney();

    cout << "Second: ";
    _second.PrintMoney();
}

void PrintComparison()
{
    PrintMoney();

    if (_first > _second)
        cout << endl << "First has more money than second;" << endl;
    else if (_first < _second)
        cout << endl << "Second has more money than first" << endl;
    else
        cout << "They has the same money" << endl;
}

bool AcceptCommand()
{
    cout << ">> ";
    string command = ReadLine();

    if (command == "0")
        return false;
    else
    {
        if (command == "read")
        {
            cout << "Enter the first item value:" << endl;
            _first = ReadMoneyData();

            cout << "Enter the second item value:" << endl;
            _second = ReadMoneyData();
        }

        else if (command == "compare")
        {
            PrintComparison();
        }

        else if (command == "print")
        {
            PrintMoney();
        }

        else if (command == "increment")
        {
            _first.PrintMoney();
            cout << "type> ";

            string subcommand = ReadLine();
            if (subcommand == "prefix")
            {
                ++_first;
                _first.PrintMoney();
            }
            else
            {
                _first++;
                _first.PrintMoney();
            }
        }

        else if (command == "clear")
        {
            _first = Money();
            _second = Money();
        }

        cout << endl;
        return true;
    }

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (AcceptCommand());
    
    return 0;
}