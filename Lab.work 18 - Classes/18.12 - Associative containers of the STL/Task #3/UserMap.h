#pragma once
#include <iostream>
#include <map>

using namespace std;

template <class T>
class UserMap
{
private:
    map<int, T> m_map;
    int m_length;

public:
    UserMap();
    explicit UserMap(int length);
    ~UserMap();

    void PrintMap();

    void Add(int index, T item);
    T Average();
};

template <class T>
UserMap<T>::UserMap() { m_length = 0; }

template<class T>
UserMap<T>::UserMap(int length)
{
    for (int i = 0; i < length; i++)
    {
        T item;
        cin >> item;

        m_map[i] = item;
    }

    m_length = length;
}

template <class T>
void UserMap<T>::PrintMap()
{
    for (int i = 0; i < m_length; i++)
        cout << i << ": " << m_map[i] << ";\n";
}

template <class T>
void UserMap<T>::Add(int index, T item)
{
    m_map.insert(make_pair(index, item));
    m_length++;
}

template <class T>
T UserMap<T>::Average()
{
    T summa = m_map[0];
    summa -= m_map[0];

    for (int i = 0; i < m_length; i++)
        summa += m_map[i];

    summa /= m_length;
    return summa;
}

template<class T>
UserMap<T>::~UserMap()
{

}
