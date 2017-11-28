#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "dataStructure.h"

using namespace std;

class historyStatistics
{
public:
	historyStatistics();
	void updateData();
	void printData() const;
	void parseData(string &dataInput);

private:
	ifstream ifile;
	vector<string> rawData;
	vector<moveStruct> moveData;
	moveStruct currentMove;
	gameStatStruct gameStat;
	string dataInput;
};