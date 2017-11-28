#include "gameMenu.h"

gameMenu::gameMenu()
{
	menu.push_back("Player vs. Player");
	menu.push_back("Player vs. Bot");
	menu.push_back("Bot vs. Bot");
	menu.push_back("Back");
}

void gameMenu::userController()
{
	ptrPos = 0;
	printMenu();
	while (1)
	{
		if (_kbhit())
		{
			KB_code = _getch();
			switch (KB_code)
			{
			case KB_UP:
				if (ptrPos != 0)
				{
					ptrPos--;
				}
				printMenu();
				break;
			case KB_DOWN:
				if (ptrPos != menu.size() - 1)
				{
					ptrPos++;
				}
				printMenu();
				break;
			case '\r':
				if (ptrPos == menu.size()-1)
				{
					return;
				}

				switch (ptrPos)
				{
				case 0:
					game = new gameBoard;
					game->userController();
					delete game;
					printMenu();
					break;
				case 1:
					dMenu.userController();
					printMenu();
					break;
				case 2:
					dMenu.userController();
					dMenu.userController();
					printMenu();
					break;
				}

				break;
			}
		}
	}
}
