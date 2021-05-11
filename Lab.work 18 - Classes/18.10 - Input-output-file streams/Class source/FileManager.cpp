#include "FileManager.h"
#include <iostream>
#include <string>

using namespace std;

void FileManager::WriteToFile()
{
    fstream streamWriter(FileName, ios::out | ios::trunc);
    if (!streamWriter)
    {
        cerr << "Error: file opening error;\n";
        return;
    }

    for (int i = 0; i < _moneyCount; i++)
        streamWriter << MoneyCollection[i] << endl;

    streamWriter.close();
}

void FileManager::ReadFromFile()
{

    fstream streamReader(FileName, ios::in);
    if (!streamReader)
    {
        cerr << "Error: file opening error;\n";
        return;
    }

    Money money;
    while (streamReader >> money)
        AddNewMoney(money);
}

void FileManager::DeleteFile()
{
    remove(FileName.c_str());
}

void FileManager::PrintCollection()
{
    for (int i = 0; i < _moneyCount; i++)
    {
        cout << "Money #" << i + 1 << ":\n";
        cout << MoneyCollection[i] << endl;
    }
}

FileManager::FileManager()
{
    FileName = "";
}

FileManager::FileManager(string fileName)
{
    FileName = fileName;
}

void FileManager::AddNewMoney(Money newMoney)
{
    _moneyCount++;
    Money* moreMonies = new Money[_moneyCount];

    for (int i = 0; i < _moneyCount - 1; i++)
        moreMonies[i] = MoneyCollection[i];

    moreMonies[_moneyCount - 1] = newMoney;

    if (_moneyCount > 1)
        delete[] MoneyCollection;
    MoneyCollection = moreMonies;
}

void FileManager::DeleteLastMoney()
{
    if (_moneyCount > 0)
    {
        _moneyCount--;
        Money* lessMonies = new Money[_moneyCount];

        for (int i = 0; i < _moneyCount; i++)
            lessMonies[i] = MoneyCollection[i];

        delete[] MoneyCollection;
        MoneyCollection = lessMonies;
    }

    else
        cout << "Count of money cannot be < 0;\n";
}

void FileManager::DeleteIfValueMoreThan(Money &comparedMoney)
{
    int count = 0;
    for (int i = 0; i < _moneyCount; i++)
        if (MoneyCollection[i] < comparedMoney)
            count++;

    Money* suitMoney = new Money[count];
    int pointer = -1;

    for (int i = 0; i < _moneyCount; i++)
        if (MoneyCollection[i] < comparedMoney)
        {
            pointer++;
            suitMoney[pointer] = MoneyCollection[i];
        }

    _moneyCount = count;
    delete[] MoneyCollection;
    MoneyCollection = suitMoney;
}

void FileManager::DivideByTwoEveryItem()
{
    for (int i = 0; i < _moneyCount; i++)
    {
        long dollars = MoneyCollection[i].Dollars();
        int cents = MoneyCollection[i].Cents();

        MoneyCollection[i].SetDollars(dollars / 2);

        if (dollars % 2 == 0)
            MoneyCollection[i].SetCents(cents / 2);
        else
            MoneyCollection[i].SetCents((cents + 100) / 2);
    }
}

void FileManager::InsertNewMoney(int index, int count)
{
    Money* moreMoney = new Money[_moneyCount + count];
    for (int i = 0; i < index; i++)
        moreMoney[i] = MoneyCollection[i];

    for (int i = 0; i < count ; i++)
        moreMoney[index + i] = Money(111, 11);

    for (int i = index + count; i < _moneyCount + count; i++)
        moreMoney[i] = MoneyCollection[i - count];

    delete[] MoneyCollection;
    MoneyCollection = moreMoney;
}

void FileManager::MakeRandomMoneyCollection(int itemCount)
{
    _moneyCount = itemCount;
    MoneyCollection = new Money[_moneyCount];

    for (int i = 0; i < _moneyCount; i++)
        MoneyCollection[i] = Money(rand(), rand() % 100);
}
