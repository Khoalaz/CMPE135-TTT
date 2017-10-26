#include"Statistics.h"

statistics::statistics()
{
	gameStat.p1Win, gameStat.p2Win, gameStat.totalGames = 0;
	thisStat.winnerMoves, thisStat.loserMoves = "";
	NNstat = new vector<AIstat>;
}

/*Prints every elements in a vector*/
void statistics::printHistory() const
{
	cout << "Player 1 wins: " << gameStat.p1Win;
		if (gameStat.totalGames != 0)
		{
			cout << ", " << roundf(gameStat.p1Win / gameStat.totalGames * 10000) / 100 << "%" << endl;
		}
		else
		{
			cout << endl;
		}
		cout << "Player 2 wins: " << gameStat.p2Win;
		if (gameStat.totalGames != 0)
		{
			cout << ", " << roundf(gameStat.p2Win / gameStat.totalGames * 10000) / 100 << "%" << endl;
		}
		else
		{
			cout << endl;
		}
		cout << "Draws: " << gameStat.totalGames - (gameStat.p1Win + gameStat.p2Win) << endl
			<< "Total Games: " << gameStat.totalGames << endl
			<< "__________________________________________" << endl << endl
			<< "NNStat:" << endl;
		for (vector<AIstat>::const_iterator it = NNstat->begin(); it != NNstat->end(); ++it)
		{
			cout << "Winner moves: " << it->winnerMoves << endl;
			cout << "Loser moves: " << it->loserMoves << endl;
		}
		cout << "__________________________________________" << endl << endl
			<< "AI data used: " << endl;	
}


/*Increases the count values of the statistic data structure*/
void statistics::updateStat(string &lineInput)
{
	switch (lineInput.at(10))
	{
	case '0':
		gameStat.p1Win++;
		break;
	case '1':
		gameStat.p2Win++;
		break;
	}
	gameStat.totalGames++;
	parseStat(lineInput);
}

/*Parses the game history to obtain winner and loser moves*/
void statistics::parseStat(string &lineInput)
{
	if (lineInput.at(10)=='2')
	{
		thisStat.winnerMoves += "DRAW";
		thisStat.loserMoves += "DRAW";
	}
	else if (lineInput.at(9) == lineInput.at(10))
	{
		for (size_t i = 0; i < lineInput.size() - 2; i++)
		{
			if (lineInput.at(i) == '0')
			{
				break;
			}

			if (i % 2 == 0)
			{
				thisStat.winnerMoves += lineInput.at(i);
			}
			else
			{
				thisStat.loserMoves += lineInput.at(i);
			}
		}
	}
	else
	{
		for (size_t i = 0; i < lineInput.size() - 2; i++)
		{
			if (lineInput.at(i) == '0')
			{
				break;
			}

			if (i % 2 == 1)
			{
				thisStat.winnerMoves += lineInput.at(i);
			}
			else
			{
				thisStat.loserMoves += lineInput.at(i);
			}
		}
	}
	NNstat->push_back(thisStat);
	thisStat.winnerMoves.clear();
	thisStat.loserMoves.clear();
}

void statistics::searchData(vector<AIstat> *dataVec)
{
	
}