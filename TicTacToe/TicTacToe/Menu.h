#pragma once
#include "Board.h"

using namespace std;

class menu
{
public:
	menu(const string *m, const int size, const string thisMenu, const string previousMenu);
	~menu();
	friend void printMenu(menu &m);
	friend void menuPtr(menu &m);

protected:
	board *game;

private:
	string thisMenu;
	string previousMenu;
	int size;
	string *menuAr;
	int ptrPos;
	
};