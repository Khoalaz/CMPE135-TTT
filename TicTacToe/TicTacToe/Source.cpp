#include "Menu.h"
#include "Functions.h"

int main()
{
	const int m1Size = 3;
	const string m1[m1Size] = { "New Game", "Check History", "Quit"};
	
	menu mainMenu(m1, m1Size, "Main", "");

	menuPtr(mainMenu);
	mainMenu.~menu();
}