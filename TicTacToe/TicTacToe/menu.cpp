#include "Menu.h"

menu::menu(const string *m, const int size, const string thisMenu, const string previousMenu)
{
	this->size = size;
	menuAr = new string[size];
	for (int i = 0; i < size; i++)
	{
		menuAr[i] = m[i];
	}
	ptrPos = 0;
	this->thisMenu = thisMenu;
	this->previousMenu = previousMenu;
}

menu::~menu()
{
	delete[] menuAr;
	delete game;
}


