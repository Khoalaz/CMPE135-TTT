#include"Statistics.h"

statistics::statistics()
{
	try
	{
		ifile.open("gameHistory.txt");
	}
	catch (fstream::failure& e)
	{
		cerr << "Error code:" << e.what() << endl;
	}

	gameStat.p1Win, gameStat.p2Win, gameStat.totalGames = 0;

}

statistics::~statistics()
{
	ifile.close();
	historyData.~vector();
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
	
	for (vector<string>::const_iterator it = historyData.begin(); it != historyData.end(); ++it)
	{
		cout << *it << endl;
	}
}

/*Updates the vector of with new elements*/
void statistics::updateVector()
{
	ifile.clear();
	while (getline(ifile, lineInput))
	{
		updateStat();
		historyData.push_back(lineInput);
	}
}

/*Increases the count values of the statistic data structure*/
void statistics::updateStat()
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