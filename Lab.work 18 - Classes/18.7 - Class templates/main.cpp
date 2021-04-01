#include <iostream>
#include "Header files\ListInt.h"
using namespace std;

template <class T>
void PrintList(ListInt<T>& list) 
{
    for (int i = 0; i < list.Length(); i++)
        cout << list[i] << ' ';

    cout << endl;
}

int main()
{
	ListInt<float> flList(10, 5.12);
    ListInt<int> inList(23, 2);
    ListInt<float> fl2List(10, 4.8);

    PrintList(flList);
    PrintList(inList);
    PrintList(fl2List);

    ListInt<float> summList = flList + fl2List;
    PrintList(summList);
	
	return 0;
}