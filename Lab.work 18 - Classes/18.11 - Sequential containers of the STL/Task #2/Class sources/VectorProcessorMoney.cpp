#include "VectorProcessorMoney.h"

Money RandomMoney()
{
    Money newMoney(rand(), rand() % 100);
    return newMoney;
}

vector<Money>::iterator IteratorByIndex(vector<Money>& processingVector, int index)
{
    vector<Money>::iterator iterator = processingVector.begin();
    for (int i = 0; i < index; i++)
        iterator++;

    return iterator;
}

void CreateRandomVector(vector<Money>& processingVector, int count)
{
    for (int i = 0; i < count; i++)
        processingVector.push_back(RandomMoney());
}

void PrintVector(vector<Money>& processingVector)
{
    cout << "\nVector count = " << processingVector.size() << ":\n";
    for (int i = 0; i < processingVector.size(); i++)
        cout << processingVector[i] << "\n";
}

void FindAverageAndPushFront(vector<Money>& processingVector)
{
    Money summ;
    vector<Money> temporary;

    for (int i = 0; i < processingVector.size(); i++)
    {
        summ += processingVector[i];
        temporary.push_back(processingVector[i]);
    }

    Money div(processingVector.size(), 0);
    Money average = Money(summ.Dollars() / processingVector.size(), summ.Cents() / processingVector.size());
    cout << "\nThe average " << average << "\n";

    processingVector.clear();
    processingVector.push_back(average);

    for (int i = 0; i < temporary.size(); i++)
        processingVector.push_back(temporary[i]);
}

void FindAndDelete(vector<Money>& processingVector, Money searchKey)
{
    for (int i = 0; i < processingVector.size(); i++)
        if (processingVector[i] == searchKey)
        {
            cout << "\nThe key has been founded: index = " << i + 1 << ";\n";
            processingVector.erase(IteratorByIndex(processingVector, i));
            break;
        }
}

void SubtractByMinValue(vector<Money>& processingVector)
{
    Money minValue = processingVector[0];
    for (int i = 1; i < processingVector.size(); i++)
        if (processingVector[i] < minValue)
            minValue = processingVector[i];

    cout << "\nMin value = " << minValue << ";\n";

    for (int i = 0; i < processingVector.size(); i++)
        processingVector[i] -= minValue;
}