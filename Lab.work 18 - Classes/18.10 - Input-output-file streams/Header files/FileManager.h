#pragma once
#include "Money.h"
#include <vector>
using namespace std;

class FileManager
{
    Money* MoneyCollection;
    int _moneyCount = 0;

public:

    string FileName;

    FileManager();
    FileManager(string fileName);

    void MakeRandomMoneyCollection(int itemCount);

    void AddNewMoney(Money newMoney);
    void DeleteLastMoney();

    void DeleteIfValueMoreThan(Money& comparedMoney);
    void DivideByTwoEveryItem();
    void InsertNewMoney(int index, int count);

    void WriteToFile();
    void ReadFromFile();
    void DeleteFile();
    void PrintCollection();
};
