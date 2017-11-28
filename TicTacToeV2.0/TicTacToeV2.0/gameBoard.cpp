#include "gameBoard.h"

gameBoard::gameBoard()
{
	srand((unsigned int)time(NULL)); //randomly selects who goes first
	if (rand() % 2 == 0)
	{
		player = 'O'; //player1=O ,  player2=X
	}
	else
	{
		history[9] = 1;
		player = 'X';
	}

	for (size_t size=0; size < 9; size++)
	{
		boardAr[size] = ' ';
	}
	historyPtr = history;
	userPosition = 0;
	KB_code = 0;
	turnCounter = 0;
	ofile.open("gameHistory.txt", fstream::app);
}

/*Prints the board*/
void gameBoard::userController()
{
	printBoard();
	while (KB_code != KB_ESCAPE)
	{
		/*mode 0: allows both players to move, mode 1
		mode 1: only player 1 can  move
		mode 2: no player can move*/
		if (_kbhit())
		{
			KB_code = _getch();
			switch (KB_code)
			{
			case KB_RIGHT:
				if (userPosition != 2 && userPosition != 5 && userPosition != 8)
				{
					userPosition++;
				}
				printBoard();
				break;
			case KB_LEFT:
				if (userPosition != 0 && userPosition != 3 && userPosition != 6)
				{
					userPosition--;
				}
				printBoard();
				break;
			case KB_UP:
				if (userPosition != 0 && userPosition != 1 && userPosition != 2)
				{
					userPosition -= 3;
				}
				printBoard();
				break;
			case KB_DOWN:
				if (userPosition != 6 && userPosition != 7 && userPosition != 8)
				{
					userPosition += 3;
				}
				printBoard();
				break;
			case '\r':
				if (boardAr[userPosition] == ' ')
				{
					pushHistory();
					boardAr[userPosition] = player;
					if (winCondition() || isFull())
					{
						printBoard();
						gameOver();
						cout << "Press [Enter] to return to menu..." << endl;
						cin.ignore();
						return;
					}
					else
					{
						if (player == 'O')
						{
							turnCounter++;
							player = 'X';
						}
						else
						{
							player = 'O';
						}
						printBoard();
					}
				}
				break;
			}
		}
	}
}

void gameBoard::printBoard()const
{
	system("cls");

	if (player == 'O')
	{
		cout << "Player One's Turn" << endl;
	}
	else
	{
		cout << "Player Two's Turn" << endl;
	}

	for (int i = 0; i < 9; i++)
	{
		cout << " ";
		if (i == userPosition) //highlight the cursor
		{
			SetConsoleTextAttribute(mConsole, 128);
			cout << boardAr[i];
			SetConsoleTextAttribute(mConsole, 7);
		}
		else
		{
			cout << boardAr[i];
		}

		if (i != 2 && i != 5 && i != 8)
		{
			cout << " |";
		}
		if (i == 2 || i == 5)
		{
			cout << endl << "-----------" << endl;
		}
	}
	cout << endl;
}

/*Returns true if an entity has won*/
bool gameBoard::winCondition() const
{
	switch (userPosition)
	{
	case 0:
		if ((boardAr[1] == player && boardAr[2] == player) || (boardAr[3] == player && boardAr[6] == player) || (boardAr[4] == player && boardAr[8] == player))
		{
			return true;
		}
		break;
	case 1:
		if ((boardAr[0] == player && boardAr[2] == player) || (boardAr[4] == player && boardAr[7] == player))
		{
			return true;
		}
		break;
	case 2:
		if ((boardAr[1] == player && boardAr[0] == player) || (boardAr[5] == player && boardAr[8] == player) || (boardAr[4] == player && boardAr[6] == player))
		{
			return true;
		}
		break;
	case 3:
		if ((boardAr[4] == player && boardAr[5] == player) || (boardAr[0] == player && boardAr[6] == player))
		{
			return true;
		}
		break;
	case 4:
		if ((boardAr[3] == player && boardAr[5] == player) || (boardAr[1] == player && boardAr[7] == player) || (boardAr[0] == player && boardAr[8] == player) || (boardAr[2] == player && boardAr[6] == player))
		{
			return true;
		}
		break;
	case 5:
		if ((boardAr[2] == player && boardAr[8] == player) || (boardAr[3] == player && boardAr[4] == player))
		{
			return true;
		}
		break;
	case 6:
		if ((boardAr[0] == player && boardAr[3] == player) || (boardAr[7] == player && boardAr[8] == player) || (boardAr[4] == player && boardAr[2] == player))
		{
			return true;
		}
		break;
	case 7:
		if ((boardAr[1] == player && boardAr[4] == player) || (boardAr[6] == player && boardAr[8] == player))
		{
			return true;
		}
		break;
	case 8:
		if ((boardAr[6] == player && boardAr[7] == player) || (boardAr[2] == player && boardAr[5] == player) || (boardAr[0] == player && boardAr[4] == player))
		{
			return true;
		}
		break;
	default:
		return false;
	}
	return false;
}

bool gameBoard::isFull() const
{
	for (int i = 0; i < 9; i++)
	{
		if (boardAr[i] == ' ')
		{
			return false;
		}
	}
	return true;
}

/*Determines who the winner is or if it is a draw*/
void gameBoard::gameOver()
{
	if (winCondition())
	{
		if (player == 'O')
		{
			cout << "Player One wins!" << endl;
		}
		else
		{
			cout << "Player Two wins!" << endl;
			history[10] = 1;
		}
		this->historyStream();
	}
	else if (isFull() && !winCondition())
	{
		cout << "Draw!" << endl;
		history[10] = 2;
		this->historyStream();
	}
}

void gameBoard::pushHistory()
{
	*historyPtr = userPosition + 1;
	*historyPtr++;
}

void gameBoard::historyStream()
{
	for (int i = 0; i < 11; i++)
	{
		ofile << history[i];
	}
	ofile << endl;
}

