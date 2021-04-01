#include <vector>
#include "Student.h"

class Tree
{
private:
    vector<vector<Person>> _data;

protected:
    void MakeTree(int count);

public:
    int Count() { return _data.size(); }

    Tree();
    Tree(int count);

    void AddNewGroup(vector<Person> personGroup) { _data.push_back(personGroup); }
    void AddNewPerson(Person person, int groupIndex) { _data[groupIndex].push_back(person); }

    void DeleteLastGroup();
    void DeleteLastPerson(int groupIndex);

    void PrintAllData();
};