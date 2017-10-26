#pragma once
#include "Statistics.h"

class ai
{
public:
	ai();
	ai(const ai&obj);
	~ai();
	void updateVector();
	void printHistory() const;
	
	void aiTurn(int userPosition);

protected:
	int searchData(int &userPosition);
	statistics stat;

private:
	int turn; //keeps track of what turn it is
	double probability[9]; //probability of selecting a position
	vector<AIstat> *dataVec;
	string lineInput;
	fstream ifile;
};