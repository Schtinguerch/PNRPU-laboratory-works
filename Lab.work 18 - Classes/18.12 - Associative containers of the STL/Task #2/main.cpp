#include <iostream>
#include <map>
#include "Money.h"

using namespace std;

typedef map<int, Money> d_map;
typedef d_map::iterator it;

d_map make_map(int count)
{
    d_map new_map;

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the number: ";
        Money number; cin >> number;

        new_map.insert(make_pair(i, number));
    }

    return new_map;
}

void print(d_map map)
{
    for (int i = 0; i < map.size(); i++)
        cout << i << ": " << map[i] << ";\n";
}

Money average_arithmetic(d_map map)
{
    Money summa(0, 0);
    for (int i = 0; i < map.size(); i++)
        summa += map[i];

    summa /= Money(map.size(), 0);
    return summa;
}

int main()
{
    cout << "Enter the count of items:\n";
    int n; cin >> n;

    d_map map = make_map(n);
    print(map);

    Money average = average_arithmetic(map);
    cout << "Average arithmetic = " << average << ";\n";

    map.insert(make_pair(map.size(), average));
    print(map);

    return 0;
}