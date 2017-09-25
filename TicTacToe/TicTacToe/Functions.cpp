#include "Functions.h"

HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void menuPtr(menu &m)
{
	const int m2Size = 4;
	const string m2[m2Size] = { "Player vs. Player", "Player vs. Bot", "Bot vs. Bot", "Back" };
	menu modeMenu(m2, m2Size, "Mode", "Main");

	/*WORK ON GETTING TO THE SECOND MENU*/

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
						break;
					default:
						m.~menu();
						modeMenu.~menu();
						delete m.game;
						exit(EXIT_SUCCESS);
						break;
					}
				}
				else if (m.thisMenu == "Mode")
				{
					switch (m.ptrPos)
					{
					case 0:
						m.game = new board;
						m.game->userController();
						cout << "Press [Enter] to continue...";
						cin.ignore();
						goto escape;
						break;
					default:
						goto escape;
						break;
					}
				}
				break;
			default:
				break;
			}
		}
	}
escape:;
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
