#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class statistics
{
public:
	statistics();
	~statistics();
	void printHistory() const;
	void updateVector();
	

protected:
	vector<string> historyData;
	void updateStat();
	struct stat
	{
		double p1Win, p2Win, totalGames;
	};

private:
	stat gameStat;
	string lineInput;
	fstream ifile;
};