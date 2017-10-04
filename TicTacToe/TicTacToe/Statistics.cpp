#include"Statistics.h"

statistics::statistics()
{
	gameStat.p1Win, gameStat.p2Win, gameStat.totalGames = 0;
}

/*Prints every elements in a vector*/
void statistics::printHistory() const
{
	cout << "Player 1 wins: " << gameStat.p1Win << ", " << roundf(gameStat.p1Win / gameStat.totalGames * 10000) / 100 << "%" << endl
		<< "Player 2 wins: " << gameStat.p2Win << ", " << roundf(gameStat.p2Win / gameStat.totalGames * 10000) / 100 << "%" << endl
		<< "Draws: " << gameStat.totalGames - (gameStat.p1Win + gameStat.p2Win) << endl
		<< "Total Games: " << gameStat.totalGames << endl
		<< "__________________________________________" << endl << endl
		<< "gameHistory.txt file output: " << endl;	
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
}