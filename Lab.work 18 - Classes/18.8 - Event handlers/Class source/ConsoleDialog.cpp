#include "ConsoleDialog.h"
#include <iostream>

using namespace std;

ConsoleDialog::ConsoleDialog(void) : Tree()
{
    _endState = 0;
}

ConsoleDialog::~ConsoleDialog() {}

void ConsoleDialog::GetEvent(TEvent &event)
{
    string charData = "+-?/qam";
    cout << "Command>>";

    string command;
    cin >> command;

    char commandName = command[0];

    if (charData.find(commandName) >= 0)
    {
        event.Type = EventMessage;
        switch (commandName)
        {
            case 'm':
                event.Command = CommandMake;
                break;

            case '+':
                event.Command = CommandAdd;
                break;

            case '-':
                event.Command = CommandDelete;
                break;

            case '?':
                event.Command = CommandShow;
                break;

            case 'q':
                event.Command = CommandQuit;
                break;
        }

        if (command.length() > 1)
        {
            string parameter = command.substr(1, command.length() - 1);
            event.a = atoi(parameter.c_str());
        }
    }

    else
        event.Type = EventNothing;
}

int ConsoleDialog::Execute()
{
    TEvent event;
    do {
        _endState = 0;
        GetEvent(event);
        HandleEvent(event);
    }
    while (!ValidValue());

    return _endState;
}

int ConsoleDialog::ValidValue()
{
    if (_endState == 0)
        return 0;
    else
        return 1;
}

void ConsoleDialog::ClearEvent(TEvent &event)
{
    event.Type = EventNothing;
}

void ConsoleDialog::EndExecuting()
{
    _endState = 1;
}

void ConsoleDialog::HandleEvent(TEvent &event)
{
    if (event.Type == EventMessage)
    {
        switch (event.Command)
        {
            case CommandQuit:
                EndExecuting();
                ClearEvent(event);
                break;

            case CommandMake:
                MakeTree(event.a);
                ClearEvent(event);
                break;

            case CommandDelete:
                DeleteLastPerson(0);
                ClearEvent(event);
                break;

            case CommandShow:
                PrintAllData();
                ClearEvent(event);
                break;

            case CommandAdd:
                string name;
                int age;
                cin >> name >> age;

                Person newPerson(name, age);
                AddNewPerson(newPerson, 0);

                ClearEvent(event);
                break;
        }
    }
}
