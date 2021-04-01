#include "Student.h"
#include <iostream>

void Student::SetRating(int rating)
{
    if (rating <= 0)
        std::cout << "Error: invalid rating;\n";
    else
        _rating = rating;
}

Student::Student()
{
    _name = "Janina Kowalski";
    _age = 0;
    _rating = 0;
}

Student::Student(string name, int age, int rating)
{
    SetName(name);
    SetAge(age);
    SetRating(rating);
}

void Student::PrintData()
{
    cout << "STUDENT\n";
    cout << "name: " << _name << endl;
    cout << "age:  " << _age << endl;
    cout << "Rating: " << _rating << "\n\n";
}
