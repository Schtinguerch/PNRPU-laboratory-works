#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>
#include <Windows.h>

#define EMPTY "{empty}"

using namespace std;

struct Person
{
    string FullName;
    string PassportNumber;
    string PhoneNumber;
};

enum InputType
{
    File,
    Keyboard
};

class PersonCluster
{
private:
    int _count = 0;
    int _collisions = 0;
    int _hashCount = 0;

    list<Person> _persons;
    Person* _hashTable;

    void PrintPerson(Person person, int index)
    {
        if (person.FullName != EMPTY) 
        {
            cout << "Person #" << index + 1 << ":\n";
            cout << " - Full name:       " << person.FullName << ";\n";
            cout << " - Passport number: " << person.PassportNumber << ";\n";
            cout << " - Phone number:    " << person.PhoneNumber << ";\n";
            cout << endl;
        }
    }

    void PrintByIndex(int index)
    {
        list<Person>::iterator pointer = _persons.begin();
        advance(pointer, index);

        cout << "Person #" << index + 1 << ":\n";
        cout << " - Full name:       " << pointer->FullName << ";\n";
        cout << " - Passport number: " << pointer->PassportNumber << ";\n";
        cout << " - Phone number:    " << pointer->PhoneNumber << ";\n";

        cout << endl;
    }

    int HashValue(string word)
    {
        int value = 0;
        for (int i = 0; i < word.size(); i++)
            value += ((int)word[i] + 64) * (i + 1);
        
        return value % 2047;
    }

public:
    int Collisions()
    {
        return _collisions;
    }

    int Count()
    {
        return _count;
    }

    void Clear()
    {
        _count = 0;
        _hashCount = 0;
        _persons.clear();
        delete[] _hashTable;
    }

    void Search(string key)
    {
        int index = HashValue(key);
        bool isElementFound = false;

        while (index < _hashCount && !isElementFound)
        {
            if (_hashTable[index].PassportNumber == key) 
            {
                isElementFound = true;
                PrintPerson(_hashTable[index], index);
            }
            else if (_hashTable[index].PassportNumber == EMPTY)
                index = _hashCount;
            else
                index++;
        }

        if (!isElementFound)
            cout << "Error: the list does not contain element with the key." << endl;
    }

    void AddPersons(int personsCount)
    {
        Person person;

        for (int i = 0; i < personsCount; i++)
        {
            cout << " - Full name:     ";
            getline(cin, person.FullName);

            cout << " - Passport name: ";
            getline(cin, person.PassportNumber);

            cout << " - Phone number:  ";
            getline(cin, person.PhoneNumber);

            _persons.push_back(person);
            _count++;
        }
    }

    void AddPersons(string filePath)
    {
        Person person;
        ifstream reader(filePath);

        while (!reader.eof())
        {
            getline(reader, person.FullName);
            getline(reader, person.PassportNumber);
            getline(reader, person.PhoneNumber);

            _persons.push_back(person);
            _count++;
        }
    }

    void Initialize(int personsCount)
    {
        Clear();
        AddPersons(personsCount);
    }

    void CreateHashTable()
    {
        _hashCount = _count;
        _hashTable = new Person[_hashCount];
        _collisions = 0;

        for (int i = 0; i < _hashCount; i++)
            _hashTable[i] = Person {EMPTY, EMPTY, EMPTY};

        for (list<Person>::iterator i = _persons.begin(); i != _persons.end(); i++)
        {
            int index = HashValue(i->PassportNumber);
            while (index >= _hashCount || _hashTable[index].PassportNumber != EMPTY)
            {
                Person* newHashTable = new Person[_hashCount * 2];
                for (int i = 0; i < _hashCount; i++)
                    newHashTable[i] = _hashTable[i];
                
                for (int i = _hashCount; i < _hashCount * 2; i++)
                    newHashTable[i] = Person {EMPTY, EMPTY, EMPTY};

                delete[] _hashTable;
                _hashTable = newHashTable;
                _hashCount *= 2;
            }

            if (_hashTable[index].PassportNumber != EMPTY)
            {
                _collisions++;
                while (_hashTable[index].PassportNumber != EMPTY)
                    index++;
            }

            _hashTable[index] = *i;
        }        
            
        
    }

    void PrintHashTable()
    {
        for (int i = 0; i < _hashCount; i++)
            PrintPerson(_hashTable[i], i);
    }

    void PrintEveryone()
    {
        for (int i = 0; i < _count; i++)
            PrintByIndex(i);
    }

    ~PersonCluster()
    {
        delete[] _hashTable;
    }
};

PersonCluster _cluster;

string ReadLine()
{
    string x;
    getline(cin, x);
    return x;
}

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

bool AcceptCommand() 
{
    cout << ">> ";
    string command = ReadLine();

    if (command == "0" || command == "quit" || command == "exit")
        return false;
    else 
    {
        if (command == "clear")
            _cluster.Clear();

        else if (command == "input")
        {
            cout << "Choose the type in entering the data:"
                << endl << " - file;" << endl << " - keyboard;"
                << endl << endl << "type> ";

            string type = ReadLine();

            if (type == "file")
            {
                cout << "Enter the path to the file: ";
                string path = ReadLine();
                _cluster.AddPersons(path);
            }

            else if (type == "keyboard")
            {
                cout << "Enter the count of persons: ";
                int count = ReadNaturalNum();
                cin.ignore();
                _cluster.AddPersons(count);
            }

            else
                cout << "Error: the argument does not exist!" << endl;
        }

        else if (command == "print")
        {
            cout << endl << "Persons count = " << _cluster.Count() << ":\n\n";
            _cluster.PrintEveryone();
        }

        else if (command == "hash")
        {
            _cluster.CreateHashTable();
            cout << "The hash table has been created! Collisions: " << _cluster.Collisions() << endl;
        }

        else if (command == "printHash")
        {
            _cluster.PrintHashTable();
        }

        else if (command == "search")
        {
            cout << "Enter the seach key: ";
            string key = ReadLine();
            _cluster.Search(key);
        }

        else if (command == "help")
        {
            cout << "Command list:" << endl;
            cout << " - clear -> clears person list" << endl;
            cout << " - input -> to enter the data into person list" << endl;
            cout << "   types of input:" << endl;
            cout << "    * keyboard -> input by typing on the keyboard" << endl;
            cout << "    * file -> getting data from file (type the file path)" << endl;
            cout << " - print -> prints to console the person list" << endl;
            cout << " - hash -> hashes up the person list" << endl;
            cout << " - printHash -> prints the hash-table" << endl;
            cout << " - search -> making search from key by the hash-table" << endl;
            cout << " - 0, quit, exit -> finish the program executing" << endl;
        }

        else 
            cout << "Error: the command does not exist!!!" << endl;

        cout << endl;
        return true;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (AcceptCommand());

    system("pause");
    return 0;
}