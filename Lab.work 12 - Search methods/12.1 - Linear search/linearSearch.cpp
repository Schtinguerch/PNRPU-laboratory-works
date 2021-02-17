#include <iostream>
#include <string>
#include "Windows.h"
#define INPUT_COUNT_MESSAGE "Enter count of items:"
#define INPUT_KEY_MESSAGE "Enter a key to found the items:"

using namespace std;

int _personsCount;

struct Person
{
    string fullName;
    int passportNumber;
    string phoneNumber;
};

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

Person* InputNewPersons(int personCount)
{
    cin.ignore();

    Person* persons = new Person[personCount];
    for (int i = 0; i < personCount; i++)
    {
        cout << "Full name:       ";
        getline(cin, persons[i].fullName);

        cout << "Passport number: ";
        cin >> persons[i].passportNumber;
        
        cout << "Phone number:    ";
        cin.ignore();
        getline(cin, persons[i].phoneNumber);
    }

    cout << endl;
    return persons;
}

void PrintPerson(Person person, int index)
{
    cout << endl << "Person #" << index + 1 << ":\n";
    cout << " - Full name:       " << person.fullName << endl;
    cout << " - Passport number: " << person.passportNumber << endl;
    cout << " - Phone number:    " << person.phoneNumber << endl << endl;
}

void PrintPersons(Person* persons)
{
    for (int i = 0; i < _personsCount; i++)
        PrintPerson(persons[i], i);
}

void FindPeople(Person* persons, int searchKey)
{
    bool itemFound = false;

    for (int i = 0; i < _personsCount; i++)
        if (persons[i].passportNumber == searchKey)
        {
            itemFound = true;
            cout << "Item \"" << searchKey << "\" found: "
                 << "index = " << i + 1 << ";\n";
            
            PrintPerson(persons[i], i);
        }
    

    if (!itemFound)
        cout << "The list has no items with the key;" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << INPUT_COUNT_MESSAGE << endl;
    _personsCount = ReadNaturalNum();

    Person* persons = InputNewPersons(_personsCount);
    PrintPersons(persons);

    cout << INPUT_KEY_MESSAGE << endl;
    int key = ReadNaturalNum();

    FindPeople(persons, key);

    system("pause");
    return 0;
}