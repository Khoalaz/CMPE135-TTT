#include "Functions.h"

HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void menuPtr(menu &m)
{
	ifstream ifile;
	string lineInput = "";
	const int m2Size = 4;
	const string m2[m2Size] = { "Player vs. Player", "Player vs. Bot", "Bot vs. Bot", "Back" };
	menu modeMenu(m2, m2Size, "Mode", "Main");

	int KB_code = 0;
	printMenu(m);
	while (1)
	{
		if (_kbhit())
		{
			KB_code = _getch();
			switch (KB_code)
			{
			case KB_UP:
				if (m.ptrPos != 0)
				{
					m.ptrPos--;
				}
				printMenu(m);
				break;
			case KB_DOWN:
				if (m.ptrPos != m.size - 1)
				{
					m.ptrPos++;
				}
				printMenu(m);
				break;
			case '\r':
				if (m.thisMenu == "Main")
				{
					switch (m.ptrPos)
					{
					case 0:
						modeMenu.ptrPos = 0;
						menuPtr(modeMenu);
						printMenu(m);
						break;
					case 1:
						try
						{
							ifile.open("gameHistory.txt");
						}
						catch (ifstream::failure& e)
						{
							cerr << "Fail to read to file" << endl;
						}

						ifile.clear();
						ifile.seekg(0);
						system("cls");
						while (getline(ifile, lineInput))
						{
							cout << lineInput << endl;
						}
						cout << "Press [Enter] to head back to main menu...";
						cin.ignore();
						printMenu(m);
						break;
					default:
						ifile.close();
						m.~menu();
						modeMenu.~menu();
						delete m.game;
						exit(EXIT_SUCCESS);
						break;
					}
				}
				else if (m.thisMenu == "Mode")
				{
					/*initiate the board if the selection is not 'exit'*/
					if (m.ptrPos != m.size)
					{
						m.game = new board;
						m.game->setMode(m.ptrPos);
						m.game->userController();
						cout << "Press [Enter] to continue...";
						cin.ignore();
						goto escape;
					}
				}
				break;
			default:
				break;
			}
		}
	}
escape:; //exits the loop
}

void printMenu(menu &m)
{
	system("cls");
	for (int i = 0; i < m.size; i++)
	{
		cout << i + 1 << ". ";
		if (m.ptrPos == i)
		{
			SetConsoleTextAttribute(mConsole, 128);
			cout << m.menuAr[i];
			SetConsoleTextAttribute(mConsole, 7);
		}
		else
		{
			cout << m.menuAr[i];
		}
		cout << endl;
	}
}
