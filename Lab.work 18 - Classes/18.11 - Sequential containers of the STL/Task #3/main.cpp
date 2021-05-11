#include "ListInt.h"
#include "Money.h"

using namespace std;

int main()
{
	cout << "Input new money:\n";
	
	ListInt<Money> justMoney;
	cin >> justMoney;
	cout << justMoney;

	cout << "Searching average money and push front:\n";

	justMoney.FindAverageAndPushFront();
	cout << justMoney;

	Money notSuitMoney;
	cout << "\nWhich money does not suit you?\n";
	cin >> notSuitMoney;
	
	justMoney.FindAndDelete(notSuitMoney);
	cout << justMoney;

	cout << "Subtracting the money:\n";

	justMoney.SubtractByMinValue();
	cout << justMoney;


	cout << "Input new float number:\n";
	
	ListInt<double> justNumber;
	cin >> justNumber;
	cout << justNumber;

	cout << "Searching average money and push front:\n";
	
	justNumber.FindAverageAndPushFront();
	cout << justNumber;

	cout << "\nWhich number do you wanna to delete?\n";
	double key;
	cin >> key;

	justNumber.FindAndDelete(key);
	cout << justNumber;

	cout << "Subtracting the nubmer:\n";

	justNumber.SubtractByMinValue();
	cout << justNumber;
	
	return 0;
}