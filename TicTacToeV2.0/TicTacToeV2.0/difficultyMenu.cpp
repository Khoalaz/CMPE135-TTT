#include "difficultyMenu.h"

difficultyMenu::difficultyMenu()
{
	menu.push_back("Beginner");
	menu.push_back("Intermediate");
	menu.push_back("Expert");
	menu.push_back("Grand Master");
	menu.push_back("Back");

	difficulty = -1;
}

void difficultyMenu::userController()
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
				if (ptrPos != menu.size() - 1)
				{
					difficulty = ptrPos;
				}
				return;
				break;
			}
		}
	}
}