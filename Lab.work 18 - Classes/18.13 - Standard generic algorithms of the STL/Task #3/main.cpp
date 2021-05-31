#include "Time.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

Time s;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

bool timeGreater(Time t)
{
    return t > s;
}

bool timeLess(Time t1,Time t2)
{
    return t1 > t2;
}

bool IsEqualToS(Time t)
{
    return t == s;
}

void PrintVector(vector<Time> v)
{
    for (int i=0;i<v.size();i++)
        cout << v[i] <<endl;

    cout<<endl;
}

Time AverageTime(vector<Time> v)
{
    Time s = v[0];
    for(int i=1;i<v.size();i++)
        s = s + v[i];

    return s / v.size();
}

void DeleteTime(Time& t)
{
    t = t / s;
}

void NewLotOfTime(Time*& A, int length)
{
    Time el;
    Time h(666,0);

    cin>> A[0];
    for (int i = 1; i < length; i++)
    {
        cin >> el;
        if (el > A[i-1])
            A[i] = el;

        else
        {
            int j = i - 1;
            while (el < A[j])
            {
                A[j + 1] = A[j];
                A[j] = h;
                j--;
            }
            A[j + 1] = el;
        }
    }
}

vector<Time> ConvertLotToVectorType(Time*& mas, int n)
{
    vector<Time> v;
    for (int i=0; i<n; i++)
        v.push_back(mas[i]);

    return v;
}

int main()
{
    cout<<"Input the count of items:\n";
    int n = ReadNaturalNum();

    vector<Time> v;
    Time*mas= new Time[n];

    cout<<"Input your lot:\n";
    NewLotOfTime(mas, n);

    cout<<'\n';
    v = ConvertLotToVectorType(mas, n);
    PrintVector(v);

    vector<Time>::iterator i;
    i=max_element(v.begin(), v.end());

    cout<<"Max value = "<< *(i) << endl;
    Time m = *(i);

    s = AverageTime(v);
    cout<<"Average value = " << s << endl;
    replace_if(v.begin(), v.end(), timeGreater, m);

    cout<<"Replacing..." << endl;
    PrintVector(v);

    cout<<"Reducing sort:\n";
    sort(v.begin(), v.end(), timeLess);
    PrintVector(v);

    cout<<"Increasing sort:\n";
    sort(v.begin(), v.end());
    PrintVector(v);

    cout<<"Search by key: "<<endl; cin >> s;
    i = find_if(v.begin(), v.end(), IsEqualToS);

    if(i != v.end())
        cout<<*(i)<<endl;
    else
        cout<<"The list has not the element."<<endl;

    cout<<"Deleting the minimal element...\n";
    i = min_element(v.begin(), v.end());

    s = *i;
    i = remove_if(v.begin(), v.end(), IsEqualToS);

    v.erase(i, v.end());
    PrintVector(v);

    cout << "Elements division" << endl;
    i = max_element(v.begin(), v.end());
    s =* i;

    for_each(v.begin(), v.end(), DeleteTime);
    PrintVector(v);
}