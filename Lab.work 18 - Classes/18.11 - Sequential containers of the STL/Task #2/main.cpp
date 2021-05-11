#include "VectorProcessorMoney.h"
#include "Money.h"
#include <vector>

using namespace std;

int main()
{
    vector<Money> newVector;

    cout << "Printing new vector:" << endl;

    CreateRandomVector(newVector, 18);
    PrintVector(newVector);

    cout << "Adding new vector:" << endl;

    FindAverageAndPushFront(newVector);
    PrintVector(newVector);

    cout << "\nInput the search key:\n";
    Money key; cin >> key;

    FindAndDelete(newVector, key);
    PrintVector(newVector);

    cout << "Subtracting money by min value";
	
    SubtractByMinValue(newVector);
    PrintVector(newVector);

    return 0;
}