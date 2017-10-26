#include "AI.h"

ai::ai()
{
	try
	{
		ifile.open("gameHistory.txt");
	}
	catch (fstream::failure& e)
	{
		cerr << "Error code:" << e.what() << endl;
	}
	this->updateVector();
	dataVec = new vector<AIstat>;
}

ai::ai(const ai&obj)
{
	this->stat = obj.stat;
}

ai::~ai()
{
	ifile.close();
	delete dataVec;
}

/*Updates the vector of with new elements*/
void ai::updateVector()
{
	ifile.clear();
	while (getline(ifile, lineInput))
	{
		stat.updateStat(lineInput);
	}
}

/*Print the array*/
void ai::printHistory() const
{
	stat.printHistory();
	for (vector<AIstat>::const_iterator it = dataVec->begin(); it != dataVec->end(); ++it)
	{
		cout << it->winnerMoves << endl;
		cout << it->loserMoves << endl;
	}
}


void ai::aiTurn(int userPosition)
{
	searchData(userPosition);
	cout << "AI turn" << endl;
}

/*returns the amount of matches*/
int ai::searchData(int &userPosition) 
{
	for (vector<AIstat>::iterator it = stat.NNstat->begin(); it != stat.NNstat->end(); it++)
	{

	}
	return 0;
}