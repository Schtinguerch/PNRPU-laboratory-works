#include <iostream>
#include <windows.h>
#include <string>
#include "Header files\ListInt.h"
using namespace std;

void PrintList(ListInt& list)
{
	for (int i = 0; i < list.Length(); i++)
		cout << list[i] << ' ';

	cout << endl;
}

int main()
{
    ListInt list(24, 2);
	PrintList(list);
	
	ListInt copied(list);
	PrintList(copied);

	list[5] = 45;
	list[21] = 38;
	PrintList(list);

	ListInt added = list + copied;
	PrintList(added);

	list[23] = 99;
	PrintList(list);
	
	cout << *(list.End()) << endl;
	list.MoveSelector(21);
	cout << *(list.SelectedItem()) << endl;
}