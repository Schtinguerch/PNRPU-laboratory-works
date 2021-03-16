#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

struct Hero
{
    string FullName;
    string HeroRole;
    int BirthYear;
};

void MergeSort(vector<Hero>& a, int start, int end)
{
    int workLength = end - start;

    if (workLength < 2)
        return;
    if (workLength == 2)
    {
        if (a[start].BirthYear > a[start + 1].BirthYear)
            swap(a[start], a[start + 1]);
    }

    MergeSort(a, start, start + workLength / 2);
    MergeSort(a, start + workLength / 2, end);

    vector<Hero> buffer;
    int bl = start;
    int el = start + workLength / 2;
    int b2 = el;

    while (buffer.size() < workLength)
    {
        if(bl >= el || (b2 < end && a[b2].BirthYear <= a[bl].BirthYear))
        {
            buffer.push_back(a[b2]);
            b2++;
        }
        else 
        {
            buffer.push_back(a[bl]);
            bl++;
        }
    }

    for (int i = start; i < end; i++)
        a[i] = buffer[i - start];
}

void MergeSort(vector<Hero>& heros)
{
    MergeSort(heros, 0, heros.size());
}

void PrintHero(Hero hero, int orderNumber)
{
    cout << "Hero #" << orderNumber + 1 << ";\n";
    cout << " - Full name:  " << hero.FullName << ";\n";
    cout << " - Hero role:  " << hero.HeroRole << ";\n";
    cout << " - Birth year: " << hero.BirthYear << ";\n\n";
}

void PrintHeros(vector<Hero> heros)
{
    cout << "Hero count = " << heros.size() << ";\n\n";

    for (int i = 0; i < heros.size(); i++)
        PrintHero(heros[i], i);
}

vector<Hero> ReadHeroFromFile(string filePath)
{
    vector<Hero> heros;
    ifstream reader(filePath);

    if (reader.fail())
        cout << "error" << endl;

    while (!reader.eof())
    {
        Hero oneHero;
        string birthYear;

        getline(reader, oneHero.FullName);
        getline(reader, oneHero.HeroRole);
        getline(reader, birthYear);
        
        oneHero.BirthYear = stoi(birthYear);
        heros.push_back(oneHero);
    }

    return heros;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Hero> heros = ReadHeroFromFile("..\\Work files\\HeroList.txt");
    PrintHeros(heros);

    MergeSort(heros);
    PrintHeros(heros);

    return 0;
}