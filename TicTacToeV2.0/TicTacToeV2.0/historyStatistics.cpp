#include "historyStatistics.h"

historyStatistics::historyStatistics()
{
	try
	{
		ifile.open("gameHistory.txt");
	}
	catch (fstream::failure& e)
	{
		cerr << "Error code:" << e.what() << endl;
	}
	gameStat.p1Win = 0;
	gameStat.p2Win = 0;
	gameStat.totalGames = 0;
	currentMove.winnerMoves = "";
	currentMove.loserMoves = "";
}

void historyStatistics::updateData()
{
	ifile.clear();
	while (getline(ifile, dataInput))
	{
		rawData.push_back(dataInput);
		switch (dataInput.at(10))
		{
		case '0':
			gameStat.p1Win++;
			break;
		case '1':
			gameStat.p2Win++;
			break;
		}
		gameStat.totalGames++;
		parseData(dataInput);
	}
}

void historyStatistics::parseData(string& dataInput)
{
	if (dataInput.at(10) == '2')
	{
		currentMove.winnerMoves += "DRAW";
		currentMove.loserMoves += "DRAW";
	}
	else if (dataInput.at(9) == dataInput.at(10))
	{
		for (size_t i = 0; i < dataInput.size() - 2; i++)
		{
			if (dataInput.at(i) == '0')
			{
				break;
			}

			if (i % 2 == 0)
			{
				currentMove.winnerMoves += dataInput.at(i);
			}
			else
			{
				currentMove.loserMoves += dataInput.at(i);
			}
		}
	}
	else
	{
		for (size_t i = 0; i < dataInput.size() - 2; i++)
		{
			if (dataInput.at(i) == '0')
			{
				break;
			}

			if (i % 2 == 1)
			{
				currentMove.winnerMoves += dataInput.at(i);
			}
			else
			{
				currentMove.loserMoves += dataInput.at(i);
			}
		}
	}
	moveData.push_back(currentMove);
	currentMove.winnerMoves.clear();
	currentMove.loserMoves.clear();
}

void historyStatistics::printData() const
{
	system("cls");
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
		<< "Move History Data:" << endl;
	for (vector<moveStruct>::const_iterator it = moveData.begin(); it != moveData.end(); ++it)
	{
		cout << "Winner moves: " << it->winnerMoves << endl
			<< "Loser moves: " << it->loserMoves << endl;
	}
	cout << "__________________________________________" << endl << endl
		<< "Raw Data: " << endl;
	unsigned int gameCounter = 1;
	for (vector<string>::const_iterator it = rawData.begin(); it != rawData.end(); ++it)
	{
		cout << "Game " << gameCounter << ": " << *it << endl;
		gameCounter++;
	}
}