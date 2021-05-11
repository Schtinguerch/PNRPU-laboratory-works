#pragma once
#include <vector>
#include <iostream>
#include "Money.h"
using namespace std;

vector<Money>::iterator IteratorByIndex(vector<Money>& processingVector, int index);

Money RandomMoney();
void CreateRandomVector(vector<Money>& processingVector, int count);
void PrintVector(vector<Money>& processingVector);

void FindAverageAndPushFront(vector<Money>& processingVector);
void FindAndDelete(vector<Money>& processingVector, Money searchKey);
void SubtractByMinValue(vector<Money>& processingVector);