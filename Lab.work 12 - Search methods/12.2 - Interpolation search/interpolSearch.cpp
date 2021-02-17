#include <iostream>
#include <algorithm>
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

void SelectionSort(Person*& persons)
{
    int j = 0;
    Person temp;

	for (int i = 0; i < _personsCount; i++)
	{
        j = i;

        for (int k = i; k < _personsCount; k++)
            if (persons[j].passportNumber > persons[k].passportNumber)
                j = k;

        temp = persons[i];
        persons[i] = persons[j];
        persons[j] = temp;
	}
}

bool PrintCompare(Person* persons, int index, int compareValue)
{
    if (persons[index].passportNumber == compareValue)
    {
        cout << "Item \"" << compareValue << "\" found: "
            << "index = " << index + 1 << ";\n";
    
        PrintPerson(persons[index], index);

        return true;
    }
    else
        return false;
}

void InterpolFindPeople(Person* persons, int searchKey)
{
    bool itemFound = false;
    int 
        middle,
        left = 0,
        right = _personsCount,
        startIndex = -1;

    while ((persons[left].passportNumber <= searchKey) && (persons[right].passportNumber >= searchKey))
    {
        middle = left + (searchKey - persons[left].passportNumber) * (right - left) / (persons[right].passportNumber - persons[left].passportNumber);
        if (persons[middle].passportNumber < searchKey)
            left = middle + 1;
        else if (persons[middle].passportNumber > searchKey)
            right = middle - 1;
        else 
        {
            startIndex = middle;
            itemFound = true;
            break;
        }
    }

    if (!itemFound)
        cout << "The list has no items with the key;" << endl;
    else 
    {
        for (int i = startIndex; i < _personsCount; i++)
        {
            if (!PrintCompare(persons, i, searchKey))
                break;
        }

        for (int i = startIndex - 1; i >= 0; i--)
        {
            if (!PrintCompare(persons, i, searchKey))
                break;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << INPUT_COUNT_MESSAGE << endl;
    _personsCount = ReadNaturalNum();

    Person* persons = InputNewPersons(_personsCount);
    PrintPersons(persons);

    SelectionSort(persons);

    cout << "Sorted list:" << endl;
    PrintPersons(persons);

    cout << INPUT_KEY_MESSAGE << endl;
    int key = ReadNaturalNum();

    InterpolFindPeople(persons, key);

    system("pause");
    return 0;
}