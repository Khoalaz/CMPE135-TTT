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
	friend class ai;
	void printHistory() const;

protected:
	void updateStat(string &lineInput);
	struct stat
	{
		float p1Win, p2Win, totalGames;
	};

private:
	stat gameStat;
};