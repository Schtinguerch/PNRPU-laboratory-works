#include <string>
using namespace std;

class Person {
protected:
    int _age;
    std::string _name;

public:
    int Age() { return _age; }
    std::string Name() { return _name; }

    void SetAge(int age);
    void SetName(string name);
    virtual void PrintData();

    Person();
    Person(string name, int age);
};