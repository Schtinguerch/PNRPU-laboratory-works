#include "Person.h"
#include <iostream>
#include <string>

void Person::SetAge(int age)
{
    if (age < 0)
        std::cout << "Error: invaid age;\n";
    else
        _age = age;
}

void Person::SetName(std::string name)
{
    if (name.length() < 2)
        std::cout << "Error: invalid name;\n";
    else
        _name = name;
}

Person::Person()
{
    _name = "Janina Kowalski";
    _age = 0;
}

Person::Person(string name, int age)
{
    SetName(name);
    SetAge(age);
}

void Person::PrintData()
{
    cout << "PERSON\n";
    cout << "name: " << _name << endl;
    cout << "age:  " << _age << "\n\n";
}
