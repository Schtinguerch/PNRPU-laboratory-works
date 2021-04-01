#include "Tree.h"

Tree::Tree()
{
    _data.clear();
}

Tree::Tree(int count)
{
    MakeTree(count);
}

void Tree::PrintAllData()
{
    vector<Person> currentVector;
    for (int i = 0; i < _data.size(); i++)
    {
        currentVector = _data[i];
        for (int j = 0; j < currentVector.size(); j++)
            _data[i][j].PrintData();
    }
}

void Tree::DeleteLastGroup()
{
    _data.pop_back();
}

void Tree::DeleteLastPerson(int groupIndex)
{
    _data[groupIndex].pop_back();
}

void Tree::MakeTree(int count)
{
    Person filler;
    vector<Person> fillVector;
    fillVector.push_back(filler);

    for (int i = 0; i < count; i++)
        _data.push_back(fillVector);
}
