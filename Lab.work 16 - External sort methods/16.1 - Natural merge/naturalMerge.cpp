#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Windows.h"

using namespace std;

struct Hero
{
    string FullName;
    string HeroRole;
    int BirthYear;
};

bool IsOrdered(int first, int second)
{
    return first >= second;
}

vector<Hero> Merge(vector<Hero>& first, vector<Hero>& second)
{
    vector<Hero> buffer;
    int
        firstPonter = 0,
        secondPointer = 0;

    while (firstPonter < first.size())
    {
        if (first[firstPonter].BirthYear < second[secondPointer].BirthYear)
        {
            buffer.push_back(first[firstPonter]);
            firstPonter++;
        }
        else
        {
            buffer.push_back(second[secondPointer]);
            secondPointer++;
        }
    }  

    return buffer;
}

void MergeSort(vector<Hero>& heros)
{
    vector<vector<Hero>> 
        firstQueue,
        secondQueue;
    
    int 
        writingIndex = 0,
        currentRange[] {0, -1};

    do 
    {
        int previous = heros[0].BirthYear - 1;
        for (auto hero : heros)
        {
            int current = hero.BirthYear;
            if (!IsOrdered(current, previous))
            {
                writingIndex = (writingIndex == 0)? 1 : 0;
                currentRange[writingIndex]++;
            }

            if (writingIndex == 0)
                firstQueue[currentRange[0]].push_back(hero);
            else 
                secondQueue[currentRange[1]].push_back(hero);

            previous = hero.BirthYear;
        }

        heros.clear();
        int i = 0;
        for (i; i < secondQueue.size(); i++)
        {
            vector<Hero> buffer = Merge(firstQueue[i], secondQueue[i]);
            heros.insert(heros.end(), buffer.begin(), buffer.end());
        }
        if (firstQueue.size() > secondQueue.size())
            heros.insert(heros.end(), firstQueue[secondQueue.size()].begin(), firstQueue[secondQueue.size()].end());
    }
    while (secondQueue.size() > 0);
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