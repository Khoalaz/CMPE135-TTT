#pragma once
#include "Statistics.h"

class ai
{
public:
	ai();
	~ai();
	void updateVector();
	void printHistory() const;

protected:
	statistics stat;

private:
	vector<string> *dataVec;
	string lineInput;
	fstream ifile;
};