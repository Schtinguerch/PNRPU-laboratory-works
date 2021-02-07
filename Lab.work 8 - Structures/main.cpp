#include <iostream>
#include <stdio.h>

#define MAX_LENGTH 100
#define MAX_NAME_LENGTH 30
#define ADD_COUNT 3

#define OPEN_FILE_ERROR "Error: the file is not open!!!"
#define WRITE_FILE_ERROR "Error: writing to file is failed!!!"
#define SUCCESS "All file operations was successfully done!!!"

using namespace std;

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
    while (number < 1);
    
    return number;
}

Videotape InputVideotape() 
{
    Videotape input;

    cin.ignore();

    cout << "name: ";
    cin.getline(input.filmName, MAX_NAME_LENGTH, '\n');

    cout << "producer: ";
    cin.getline(input.producer, MAX_NAME_LENGTH, '\n');
    
    cout << "duration: ";
    input.timeDuration = InputNaturalNum();

    cout << "cost: ";
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

        cout << "Input data for " << tapesCount << " new videotapes:" << endl;
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

                cout << "Input data for " << ADD_COUNT << " new videotapes:" << endl;

                file = fopen("Work files\\F.dat", "ab");
                i = 0;
                while ((i < ADD_COUNT) && _IsProcessSuccessful)
                {
                    tapes[tapesCount] = InputVideotape();
                    _IsProcessSuccessful = WriteVideotape(file, &tapes[tapesCount]);

                    tapesCount++;
                    i++;
                }

                cout << (_IsProcessSuccessful) ? SUCCESS : WRITE_FILE_ERROR;
            }
            else
                cout << OPEN_FILE_ERROR << endl;
        }
        else 
            cout << WRITE_FILE_ERROR << endl;
    }
    else 
        cout << OPEN_FILE_ERROR << endl;
    
    system("pause");
    return 0;
}