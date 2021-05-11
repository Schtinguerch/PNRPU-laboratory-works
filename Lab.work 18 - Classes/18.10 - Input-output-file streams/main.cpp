#include <iostream>
#include "FileManager.h"

using namespace std;

int main()
{
    FileManager manager("F1.txt");
    Money newMoney(4000, 00);

    cout << "New random money collection:\n";
    manager.MakeRandomMoneyCollection(40);
    manager.PrintCollection();

    cout << "Every money value has been divided by 2:\n";
    manager.DivideByTwoEveryItem();
    manager.PrintCollection();

    cout << "Delete money if the value is more than 4000.00$:\n";
    manager.DeleteIfValueMoreThan(newMoney);
    manager.PrintCollection();

    cout << "Write the last money data into F1.txt:\n";
    manager.WriteToFile();
    return 0;
}