#pragma once

const int EventNothing = 0;
const int EventMessage = 100;
const int CommandAdd = 1;
const int CommandDelete = 2;
const int CommandShow = 4;
const int CommandMake = 6;
const int CommandQuit = 101;

struct TEvent
{
    int Type;
    int Command;
    int a;
};