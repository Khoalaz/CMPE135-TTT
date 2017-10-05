#pragma once
#include "Statistics.h"

class ai
{
public:
	ai();
	~ai();
	void updateVector();
	void printHistory() const;
	
	void aiTurn();

protected:
	statistics stat;

private:
	vector<string> *dataVec;
	string lineInput;
	fstream ifile;
};