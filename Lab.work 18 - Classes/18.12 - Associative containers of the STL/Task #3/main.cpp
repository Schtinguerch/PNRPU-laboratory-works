#include "Money.h"
#include "UserMap.h"

using namespace std;

int ReadNaturalNum()
{
    int x = -1;
    while (x <= 0)
        cin >> x;
    return x;
}

int main()
{
    cout << "----Float----\n";

    cout << "Input count of numbers:\n";
    int count = ReadNaturalNum();

    UserMap<float> floatMap(count);
    floatMap.PrintMap();

    float average = floatMap.Average();
    cout << "average = " << average << ";\n";

    floatMap.Add(count, average);
    floatMap.PrintMap();

    cout << "----Money----\n";
    cout << "Input count of numbers:\n";
    int moneyCount = ReadNaturalNum();

    UserMap<Money> MoneyMap(moneyCount);
    MoneyMap.PrintMap();

    Money maverage = MoneyMap.Average();
    cout << "average = " << maverage << ";\n";

    MoneyMap.Add(moneyCount, maverage);
    MoneyMap.PrintMap();

    return 0;
}