#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

const int MAX_LENGTH = 100;
const int MAX_NAME_LENGTH = 20;
const int ADD_COUNT = 3;
const string OpenFileErrorMessage = "Error: the file is not open!!!";
const string SecondOpenFileErronMessage = "Error: the file (second opening) is not open!!!";
const string WriteFileErrorMessage = "Error: writing to file is failed!!!";
const string SecondWriteFileErrorMessage = "Error: writing (second) to file is failed!!!";

bool _IsProcessSuccessful = true;

struct Videotape
{
    char filmName[MAX_NAME_LENGTH];
    char producer[MAX_NAME_LENGTH];
    int timeDuration;
    int cost;
};

int InputNaturalNum() 
{
    int number;

    do
        cin >> number;
    while ((number < 1) || (number > 100));
    
    return number;
}

Videotape InputVideotape() 
{
    Videotape input;

    cin.ignore();

    cout << "name:";
    cin.getline(input.filmName, MAX_NAME_LENGTH, '\n');

    cout << "producer:";
    cin.getline(input.producer, MAX_NAME_LENGTH, '\n');
    
    cout << "duration:";
    input.timeDuration = InputNaturalNum();

    cout << "cost:";
    input.cost = InputNaturalNum();

    cout << endl;
    return input;
}

bool WriteVideotape(FILE* fileStream, Videotape* tape) 
{
    if (fileStream != NULL) 
    {
        fwrite(tape, sizeof(Videotape), 1, fileStream);
        return (ferror == NULL)? false : true;
    }
    else
        return false;
}

bool ReadVideotape(FILE* fileStream, Videotape* tape)
{
    if ((fileStream != NULL) && !feof(fileStream)) 
    {
        fread(tape, sizeof(Videotape), 1, fileStream);
        return true;
    }
    else 
        return false;
}

void PrintVideotapes(Videotape* tapes, int tapesCount) 
{
    for (int i = 0; i < tapesCount; i++) 
    {
        cout << "Videotype #" << i + 1 << ": " << endl;
        cout << " film's name      - " << (tapes + i)->filmName << endl;
        cout << " film's producer  - " << (tapes + i)->producer << endl;
        cout << " film's duration  - " << (tapes + i)->timeDuration << " minutes" << endl;
        cout << " videotape's cost - " << (tapes + i)->cost << " dollars" << endl << endl;
    }
}

void DeleteVideotape(Videotape* tapes, int deleteIndex, int& tapesCount) 
{
    for (int i = deleteIndex; i < tapesCount - 1; i++)
        *(tapes + i) = *(tapes + i + 1);

    *(tapes + tapesCount - 1) = Videotape { "", "", 0, 0 };
    tapesCount--;
}

int main() 
{
    FILE* file = fopen("Work files\\F.dat", "wb");
    if (file != NULL) 
    {
        Videotape tapes[MAX_LENGTH];

        cout << "Input count of videotapes (1 to 100):" << endl;
        int tapesCount = InputNaturalNum();

        int i = 0;
        while ((i < tapesCount) && _IsProcessSuccessful) 
        {
            Videotape workVideotape = InputVideotape();
            _IsProcessSuccessful = WriteVideotape(file, &workVideotape);
            i++;
        }

        fclose(file);
        if (_IsProcessSuccessful)
        {
            file = fopen("Work files\\F.dat", "rb");
            i = 0;
            while ((i < tapesCount) && _IsProcessSuccessful)
            {
                _IsProcessSuccessful = ReadVideotape(file, &tapes[i]);
                i++;
            }


            fclose(file);
            if (_IsProcessSuccessful) 
            {
                PrintVideotapes(tapes, tapesCount);

                cout << "Input the cost of videotape, which will not be exceeded:" << endl;
                int maxCost = InputNaturalNum();

                for (int i = tapesCount - 1; i >= 0; i--) 
                {
                    if (tapes[i].cost > maxCost)
                        DeleteVideotape(tapes, i, tapesCount);
                }

                cout << "Left videotapes:" << endl;
                PrintVideotapes(tapes, tapesCount);

                cout << "Input data for " << ADD_COUNT << " new videotapes:" << endl
                    << " - film's name" << endl
                    << " - film's producer " << endl
                    << " - film's duration (minutes)" << endl
                    << " - videotape's cost (USD)" << endl;

                file = fopen("Work files\\F.dat", "ab");
                for (int i = 0; i < ADD_COUNT; i++) 
                {
                    tapes[tapesCount] = InputVideotape();
                    _IsProcessSuccessful = WriteVideotape(file, &tapes[tapesCount]);

                    tapesCount++;
                }

                if (_IsProcessSuccessful)
                    cout << "All file operations was succeessfully done!!!" << endl;
                else 
                    cout << SecondWriteFileErrorMessage << endl;
            }


            else
                cout << SecondOpenFileErronMessage << endl;
        }
        else 
            cout << WriteFileErrorMessage << endl;
    }
    else 
    {
        fclose(file);
        cout << OpenFileErrorMessage << endl;
    }


    return 0;
}