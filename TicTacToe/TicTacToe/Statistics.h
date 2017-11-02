#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#include "DataStructures.h"

using namespace std;

class statistics
{
public:
	statistics();
	friend class ai;
	void printHistory() const;

protected:
	void updateStat(string &lineInput);
	void parseStat(string &lineInput);

private:
	vector<AIstat> *NNstat;
	AIstat thisStat;
	stats gameStat;
};