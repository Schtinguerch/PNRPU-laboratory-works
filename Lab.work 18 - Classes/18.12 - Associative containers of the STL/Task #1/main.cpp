#include <iostream>
#include <map>

using namespace std;

typedef map<int, float> d_map;
typedef d_map::iterator it;

d_map make_map(int count)
{
    d_map new_map;

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the number: ";
        float number; cin >> number;

        new_map.insert(make_pair(i, number));
    }

    return new_map;
}

void print(d_map map)
{
    for (int i = 0; i < map.size(); i++)
        cout << i << ": " << map[i] << ";\n";
}

float average_arithmetic(d_map map)
{
    int summa = 0;
    for (int i = 0; i < map.size(); i++)
        summa += map[i];

    return summa / map.size();
}

int main()
{
    cout << "Enter the count of items:\n";
    int n; cin >> n;

    d_map map = make_map(n);
    print(map);

    float average = average_arithmetic(map);
    cout << "Average arithmetic = " << average << ";\n";

    map.insert(make_pair(map.size(), average));
    print(map);
    return 0;
}