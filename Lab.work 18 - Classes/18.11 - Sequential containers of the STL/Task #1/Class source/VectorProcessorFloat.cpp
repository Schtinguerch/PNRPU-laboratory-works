#include "VectorProcessorFloat.h"
#include <math.h>

vector<float>::iterator IteratorByIndex(vector<float>& processingVector, int index)
{
    vector<float>::iterator iterator = processingVector.begin();
    for (int i = 0; i < index; i++)
        iterator++;

    return iterator;
}

float RandomFloat(float minValue, float maxValue)
{
    return minValue + static_cast <float> (rand()) /
                      (static_cast <float>(RAND_MAX / (maxValue-minValue)));
}

void CreateRandomVector(vector<float>& processingVector, int count)
{
    for (int i = 0; i < count; i++)
        processingVector.push_back(RandomFloat(0, 100));
}

void PrintVector(vector<float>& processingVector)
{
    cout << "\nVector count = " << processingVector.size() << ":\n";
    for (int i = 0; i < processingVector.size(); i++)
        cout << "#" << i + 1 << ": " << processingVector[i] << ";\n";
}

void FindAverageAndPushFront(vector<float>& processingVector)
{
    float summ = 0;
    vector<float> temporary;
    temporary.push_back(0);

    for (int i = 0; i < processingVector.size(); i++)
    {
        summ += processingVector[i];
        temporary.push_back(processingVector[i]);
    }

    float average = summ / processingVector.size();
    cout << "\nThe average = " << average << ";\n";

    temporary[0] = average;
    processingVector = temporary;
}

void FindAndDelete(vector<float>& processingVector, float searchKey)
{
    for (int i = 0; i < processingVector.size(); i++)
        if (abs(processingVector[i] - searchKey) <= 0.001)
        {
            cout << "\nThe key has been founded: index = " << i + 1 << ";\n";
            processingVector.erase(IteratorByIndex(processingVector, i));
            break;
        }
}

void SubtractByMinValue(vector<float>& processingVector)
{
    float minValue = processingVector[0];
    for (int i = 1; i < processingVector.size(); i++)
        if (processingVector[i] < minValue)
            minValue = processingVector[i];

    cout << "\nMin value = " << minValue << ";\n";

    for (int i = 0; i < processingVector.size(); i++)
        processingVector[i] -= minValue;
}