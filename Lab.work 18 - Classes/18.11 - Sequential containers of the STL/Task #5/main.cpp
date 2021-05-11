#include "Money.h"
#include "ListInt.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Input money:\n";
    ListInt<Money> justMoney;

    cin >> justMoney;
    cout << justMoney;

    cout << "Find average money and push front:\n";

    justMoney.FindAverageAndPushFront();
    cout << justMoney;

    cout << "Searching inputted key and delete this:\n";

    cout << "Enter the money, you wanna to delete:\n";
    Money key;
    cin >> key;

    justMoney.FindAndDelete(key);
    cout << justMoney;

    cout << "Subtraction by minimum value\n";
    justMoney.SubtractByMinValue();
    cout << justMoney;

    cout << "\n\n\nInput integer:\n";
    ListInt<int> justInteger;

    cin >> justInteger;
    cout << justInteger;

    cout << "Find average number and push front:\n";

    justInteger.FindAverageAndPushFront();
    cout << justInteger;

    cout << "Searching inputted key and delete this:\n";

    cout << "Enter the money, you wanna to delete:\n";
    int intKey;
    cin >> intKey;

    justInteger.FindAndDelete(intKey);
    cout << justInteger;

    cout << "Subtraction by minimum value\n";

    justInteger.SubtractByMinValue();
    cout << justInteger;

    return 0;
}