#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
private:
    int _rating;

public:
    int Rating() { return _rating; }
    void SetRating(int rating);

    void PrintData();

    Student();
    Student(string name, int age, int rating);
};
