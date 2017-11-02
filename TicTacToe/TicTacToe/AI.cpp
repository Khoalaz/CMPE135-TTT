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
	dataVec = *stat.NNstat;
	alpha = 0;
	userMoves = "";
	turn = 0;
}

ai::ai(const ai&obj)
{
	this->stat = obj.stat;
	dataVec = *stat.NNstat;
	alpha = 0;
	userMoves = "";
	turn = 0;
}

ai::~ai()
{
	ifile.close();
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
	/*for (vector<AIstat>::const_iterator it = dataVec->begin(); it != dataVec->end(); ++it)
	{
		cout << it->winnerMoves << endl;
		cout << it->loserMoves << endl;
	}*/
}

void ai::pushUserMove(int userPosition)
{
	userMoves.append(to_string(userPosition+1));
	cout << userMoves << endl;
}

/*
	1. userposition slot probability equals to 0
	2. distribute alpha for the other slots equally
	3. search possible patterns from user in history
	4. compute next move
*/
void ai::aiTurn()
{
	modifyData();
	turn++;
}


/*delete irrelavent data*/
void ai::modifyData() 
{
	for (vector<AIstat>::iterator it = dataVec.begin(); it != dataVec.end();)
	{
		if (!it->winnerMoves.find(userMoves) == 0 && !it->loserMoves.find(userMoves) == 0)
		{
			it = dataVec.erase(it);
		}
		else
		{
			cout << "Winner Moves: " << it->winnerMoves << endl;
			cout << it->winnerMoves.find(userMoves) << endl;
			cout << "Loser Moves: " << it->loserMoves << endl;
			cout << it->loserMoves.find(userMoves) << endl;
			++it;
		}
	}

	/*for (vector<AIstat>::iterator it = dataVec.begin(); it != dataVec.end(); it++)
	{
		cout << "Winner Moves: " << it->winnerMoves << endl;
		cout << "Loser Moves: " << it->loserMoves << endl;
	}*/
}  

void ai::incrementTurn()
{
	turn++;
}