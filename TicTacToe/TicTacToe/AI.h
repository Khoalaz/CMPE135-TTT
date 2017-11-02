#pragma once
#include "Statistics.h"
#include <algorithm>

class ai
{
public:
	ai();
	ai(const ai&obj);
	~ai();
	void updateVector();
	void printHistory() const;
	void pushUserMove(int userPosition);
	void aiTurn();
	void incrementTurn();

protected:
	statistics stat;
	void modifyData();

private:
	int turn; //keeps track of what turn it is
	double probability[9]; //probability of selecting a position
	double alpha;
	vector<AIstat> dataVec;
	string userMoves;
	string lineInput;
	fstream ifile;
};