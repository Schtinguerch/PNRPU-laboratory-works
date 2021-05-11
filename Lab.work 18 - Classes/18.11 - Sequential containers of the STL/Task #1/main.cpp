#include "VectorProcessorFloat.h"

using namespace std;

int main()
{
    vector<float> newVector;

    CreateRandomVector(newVector, 18);
    PrintVector(newVector);

    FindAverageAndPushFront(newVector);
    PrintVector(newVector);

    cout << "\nInput the search key: ";
    float key; cin >> key;

    FindAndDelete(newVector, key);
    PrintVector(newVector);

    SubtractByMinValue(newVector);
    PrintVector(newVector);

    return 0;
}