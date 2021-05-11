#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <queue>
#include <algorithm>

using namespace std;
const int condInfinity = 10000;

int ReadNumber(int minimum, int maximum)
{
    cout << "Enter number between range [" << minimum << ", " << maximum << "]:\n";
    int x = minimum - 1;

    while ((x < minimum) || (x > maximum))
        cin >> x;

    return x;
}

void SelectionSort(vector<int>* vector)
{
    int j = 0, temp = 0;

	for (int i = 0; i < vector->size(); i++)
	{
        j = i;

        for (int k = i; k < vector->size(); k++)
            if (vector->at(j) < vector->at(k))
                j = k;

        temp = vector->at(i);	
        vector->at(i) = vector->at(j);
        vector->at(j) = temp;
	}
}


template <typename T>
T* FilledArray(int count, T value)
{
    T* array = new T[count];
    for (int i = 0; i < count; i++)
        array[i] = value;

    return array;
}

void PrintRouteLengthArray(int* routeLengths, int vertexCount)
{
    for (int i = 0; i < vertexCount; i++)
    {
        string value = (routeLengths[i] == condInfinity)? "not reachable" : to_string(routeLengths[i]);
        cout << i + 1 << ": " << value << endl;
    }
}

int* FindRootLengthViaDijkstra(vector<vector<int>> adjMatrix, int vertex)
{
    int len = adjMatrix.size();

    int* result = FilledArray(len, condInfinity);
    bool* flag = FilledArray(len, false);

    queue<int> QUEUE;
    int x = vertex - 1;

    result[x] = 0;
    QUEUE.push(x);

    bool routeFound = false;
    while (!routeFound)
    {
        x = QUEUE.front();
        vector<int> vec;

        for (int i = 0; i <len; i++)
            if (adjMatrix[x][i] != 0 && !flag[i])
                vec.push_back(i);

        if (vec.size() == 0)
        {
            flag[x] = true;
            QUEUE.pop();

            if (QUEUE.size() == 0)
                routeFound = true;

            continue;
        }

        SelectionSort(&vec);
        for (int i = 0; i < vec.size(); i++)
        {
            result[vec[i]] = min(result[vec[i]], adjMatrix[x][vec[i]] + result[x]);
            QUEUE.push(vec[i]);
        }

        flag[x] = true;
        QUEUE.pop();

        if (QUEUE.size() == 0)
            routeFound = true;
    }

    return result;
}

int main()
{
    vector<vector<int>> matrix = 
    {
        { 0, 0, 0, 26, 9, 0, 0 },
        { 0, 0, 0, 17, 0, 0, 23 },
        { 0, 0, 0, 0, 13, 5, 0},
        { 26, 17, 0, 0, 0, 42, 0},
        { 9, 0, 13, 0, 0, 0, 30},
        { 0, 0, 5, 42, 0, 0, 19},
        { 0, 23, 0, 0, 30, 19, 0},
    };

    cout << "Choose the starting vertex index:\n";
    int startVertex = ReadNumber(1, matrix.size());

    int* routes = FindRootLengthViaDijkstra(matrix, startVertex);
    PrintRouteLengthArray(routes, matrix.size());
    
    system("pause");
    return 0;
}
