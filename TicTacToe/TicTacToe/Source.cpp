#include "Menu.h"

int main()
{
	const int m1Size = 3;
	const string m1[m1Size] = { "New Game", "Continue Game", "Quit" };
	

	menu mainMenu(m1, m1Size, "Main", "");

	menuPtr(mainMenu);
	mainMenu.~menu();
}