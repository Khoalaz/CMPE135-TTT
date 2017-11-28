#include "mainMenu.h"

mainMenu::mainMenu()
{
	menu.push_back("New Game");
	menu.push_back("View History");
	menu.push_back("Quit");
}

void mainMenu::userController()
{
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
				if (ptrPos == menu.size() - 1)
				{
					return;
				}

				switch (ptrPos)
				{
				case 0:
					gMenu.userController();
					printMenu();
					break;
				case 1:
					statistics.updateData();
					statistics.printData();
					cout << "Press [Enter] to return to Main Menu..." << endl;
					cin.ignore();
					printMenu();
					break;
				}

				break;
			}
		}
	}
}
