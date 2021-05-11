#pragma once
#include <vector>
#include <iostream>
using namespace std;

vector<float>::iterator IteratorByIndex(vector<float>& processingVector, int index);

float RandomFloat(float minValue, float maxValue);
void CreateRandomVector(vector<float>& processingVector, int count);
void PrintVector(vector<float>& processingVector);

void FindAverageAndPushFront(vector<float>& processingVector);
void FindAndDelete(vector<float>& processingVector, float searchKey);
void SubtractByMinValue(vector<float>& processingVector);