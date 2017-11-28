#pragma once
#include "MenuAbstract.h"
#include "gameMenu.h"
#include "historyStatistics.h"

class mainMenu : public menuAbstract
{
public:
	mainMenu();
	void userController();
private:
	gameMenu gMenu;
	historyStatistics statistics;
};